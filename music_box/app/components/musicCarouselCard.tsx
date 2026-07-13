"use client";
import react from "react";
// Removi o import { title } from "process", pois causa erros no client-side

interface MusicCarouselCardProps {
    id: string;
    title: string;
    artist: string[];
    duration: any;
    album: string;
    coverImg: string;
}

export const MusicCarouselCard: React.FC<MusicCarouselCardProps> = ({
    id,
    title,
    artist,
    duration,
    album,
    coverImg 
}) => {
  return (
    <div className="w-full">
        <a 
            href={`/search/${id}/`}
            className="block hover:-translate-y-1 duration-300 ease-in-out hover:shadow-lg hover:shadow-green-500/30 rounded-md"
        >
            <div className="flex flex-col gap-4 bg-[#525B5B] items-center p-6 rounded-md w-full max-w-md">
                
                <div className="w-40 h-40 bg-black rounded-lg flex-shrink-0 shadow-md">
                    <img 
                        src={coverImg} 
                        alt={"Capa de " + title} 
                        className="w-full h-full object-cover rounded-md"
                    />
                </div>
                
                <div className="flex flex-row justify-between items-center w-full gap-4 mt-2"> 
                    <div className="flex flex-col gap-1 text-left flex-1">
                        <h3 className="text-xl font-bold text-white leading-tight truncate">{title}</h3>
                        <p className="text-gray-200 font-medium truncate">{artist.join(", ")}</p>
                        <p className="text-sm text-gray-400">{duration}</p>
                    </div>
                    
                    {/* Bloco da Direita: Nome do Álbum (Alinhado à direita) */}
                    <div className="text-right max-w-[40%]">
                        <p className="text-gray-300 text-sm font-semibold truncate">{album}</p>
                    </div>
                    
                </div>
            </div>
        </a>
    </div>
  );
}