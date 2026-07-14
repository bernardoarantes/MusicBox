import { Star, StarHalf } from 'lucide-react';

interface DynamicStarProps {
  rating: number;
}

export const DynamicStar = ({ rating }: DynamicStarProps) => {
  const starsOutOfFive = rating / 2;

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

interface CardMusicReviewProps {
    id: string,
    title: string,
    artist: Array<string>,
    duration: number,
    rating: number,
    coverImg: string,
    album: string,
    commentary: string,
}

export const CardMusicReview = ({id, title, artist, duration, rating, coverImg, commentary }: CardMusicReviewProps) => {

  const duration_treated = ((duration/1000)).toFixed(0)

  return (
    <div className="flex items-center gap-4 p-4 rounded-md w-full max-w-md">
      <div className="w-16 h-16 rounded-lg flex-shrink-0 space-y-2">
        <img src={coverImg} alt={"Capa de " + title} className="w-16 h-16 bg-[#3C4445] object-cover rounded-md"/>
      </div>
      <div className="flex items-center gap-4 mt-1">
        <div className="flex flex-col gap-0.5 ml-2 items-start">
          <h3 className="maintext">{title}</h3>
          <p className="subtext">{artist}</p>
          <p className="subtext">{duration_treated} s</p>
        </div>
        <div className="flex flex-col gap-0.5">
          <DynamicStar rating={rating} />
          <span className="subtext">{rating.toFixed(1)} / 10</span>
        </div>
      </div>
    </div>
  );
}