import React from "react" ;
import { Star, StarHalf } from 'lucide-react';

interface DynamicStarProps {
  rating: number;
}

export const DynamicStar = ({ rating }: DynamicStarProps) => {
  const starsOutOfFive = rating / 2;
  const hasHalfStar = rating % 1 >= 0.5;

  return (
    <div className="flex gap-0.5 text-gray-300">
      {[...Array(5)].map((_, i) => {
        const starIndex = i + 1;

        if (starIndex <= starsOutOfFive) {
          return <Star key={i} size={14} className="text-gray-200 fill-current" />;
        } else if (starsOutOfFive >= starIndex - 0.75 && starsOutOfFive < starIndex) {
          return <StarHalf key={i} size={14} className="text-gray-200 fill-current" />;
        } else {
          return <Star key={i} size={14} className="text-gray-600 fill-current" />;
        }
      })}
    </div>
  );
};

export const CardMusicReview = (
    title: string,
    artist: string,
    duration: string,
    rating: number,
    coverImg: string
) => {
  return (
    <div className="flex items-center p-4 rounded-md w-full max-w-md">
      /*Imagem da capa do album/faixa */
      <div className="w-16 h-16 rounded-lg flex-shrink-0">
        <img src={coverImg} alt={"Capa de " + title} className="w-16 h-16 object-cover rounded-md"/>
      </div>
      <div className="flex items-center gap-4 mt-1">
        <div className="flex flex-col gap-0.5 ml-2">
          <DynamicStar rating={rating} />
          <span className="text-sm text-gray-500">{rating.toFixed(1)} / 10</span>
          <h3 className="text-lg font-bold">{title}</h3>
          <p className="text-gray-600">{artist}</p>
          <p className="text-sm text-gray-500">{duration}</p>
        </div>
      </div>
    </div>
  );
}