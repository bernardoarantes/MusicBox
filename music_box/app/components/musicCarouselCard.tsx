import { title } from "process";
import react from "react";
import Image from "next/image";


interface MusicCarouselCardProps {
  title: string;
  artist: string[];
  duration: number;
  album: string;
  coverImg: string;
}

export const MusicCarouselCard:React.FC<MusicCarouselCardProps> = ({ 
    title,
    artist,
    duration,
    album,
    coverImg }) => {
  return (
    <div className="flex flex-col items-center p-4 rounded-md w-full max-w-md">
      {/* Imagem da capa do álbum/faixa */}
      <div className="w-16 h-16 rounded-lg flex-shrink-0">
        <img src={coverImg} alt={"Capa de " + title} className="w-16 h-16 object-cover rounded-md"/>
      </div>
      <div className="flex flex-row items-center gap-4 mt-1">
        <div className="flex flex-col gap-0.5 ml-2">
          <h3 className="text-lg font-bold">{title}</h3>
          <p className="text-gray-600">{artist.join(", ")}</p>
          <p>{album}</p>
          <p className="text-sm text-gray-500">{duration}</p>
        </div>
      </div>
    </div>
  );
}