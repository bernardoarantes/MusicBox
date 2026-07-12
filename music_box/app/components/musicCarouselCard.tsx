"use client";
import { title } from "process";
import react, { useRef } from "react";
import Image from "next/image";


interface MusicCarouselCardProps {
  title: string;
  artist: string[];
  duration: any;
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
    <div className="w-full">

        <div className="flex flex-col gap-4 bg-[#525B5B] flex-col items-center p-4 rounded-md w-full max-w-md">
        {/* <div className="flex gap-2">
        </div> */}
        {/* Imagem da capa do álbum/faixa */}
        <div className="w-16 h-16 rounded-lg flex-shrink-0">
            <img src={coverImg} alt={"Capa de " + title} className="w-16 h-16 object-cover rounded-md"/>
        </div>
        <div className="flex flex-row justify-between w-full gap-4 mt-1 px-4">
            <div className="flex flex-col gap-0.5 ml-2">
            <h3 className="text-lg font-bold">{title}</h3>
            <p className="text-gray-100">{artist.join(", ")}</p>
            <p className="text-sm text-gray-400">{duration}</p>
            </div>
            <p>{album}</p>
        </div>
        </div>
    </div>
  );
}