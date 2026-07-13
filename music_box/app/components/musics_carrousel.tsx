"use client";
import react, { useRef } from "react";
import { MusicCarouselCard }  from "./musicCarouselCard";

const MockMusics= [{id: "1", title: "Music 1", artist: ["Artist 1"], album: "Album 1", duration: 210000, coverImg: "/assets/music1.jpg"},
{id: "2", title: "Music 2", artist: ["Artist 2"], album: "Album 2", duration: 180000, coverImg: "/assets/music2.jpg"},
{id: "3", title: "Music 3", artist: ["Artist 3"], album: "Album 3", duration: 240000, coverImg: "/assets/music3.jpg"},
{id: "4", title: "Music 4", artist: ["Artist 4"], album: "Album 4", duration: 200000, coverImg: "/assets/music4.jpg"},
{id: "5", title: "Music 5", artist: ["Artist 5"], album: "Album 5", duration: 220000, coverImg: "/assets/music5.jpg"},
{id: "6", title: "Music 6", artist: ["Artist 6"], album: "Album 6", duration: 190000, coverImg: "/assets/music6.jpg"},
{id: "7", title: "Music 7", artist: ["Artist 7"], album: "Album 7", duration: 230000, coverImg: "/assets/music7.jpg"}];

export const MusicsCarrousel = () => {
    const carouselRef = useRef<HTMLDivElement>(null);
    const scrollLeft = () => {
        if(carouselRef.current){
            carouselRef.current.scrollBy({ left: -320, behavior: "smooth" });
        }
    }
    const scrollRight = () => {
        if(carouselRef.current){
            carouselRef.current.scrollBy({ left: 320, behavior: "smooth" });
        }
    }
    return (
    <div className="h-full max-w-5xl py-6 px-4">
        <div className="flex justify-between items-center mb-4">
            <h2 className="text-xl font-bold text-gray-100 mb-4">Last Reviews</h2>
            <div className="flex gap-2">
                <button 
                    onClick={scrollLeft}
                    className="w-10 h-10 flex items-center justify-center duration-300 hover:shadow-2xl bg-[#525B5B] text-white rounded-full hover:bg-gray-400 transition-colors duration-200"
                    aria-label="Rolar para a esquerda"
                >
                    <span className="material-symbols-outlined">arrow_back</span>
                </button>
                
                <button 
                    onClick={scrollRight}
                    className="w-10 h-10 flex items-center justify-center duration-300 hover:shadow-2xl bg-[#525B5B] text-white rounded-full hover:bg-gray-400 transition-colors duration-200"
                    aria-label="Rolar para a direita"
                >
                    <span className="material-symbols-outlined">arrow_forward</span>
                </button>
                </div>
        </div>
    
        <div ref={carouselRef}
        className="flex gap-6 py-8 px-4 overflow-x-auto pb-4 snap-x snap-mandatory scrollbar-thin scrollbar-thumb-gray-700 scrollbar-track-transparent"
        style={{ scrollbarWidth: 'none' }}
        >
            {MockMusics.map((music) => (
            <div key={music.id} className="snap-start shrink-0 w-[300px] my-6 ">
                <MusicCarouselCard
                id={music.id}
                title={music.title}
                artist={music.artist}
                duration={music.duration/1000 + "s"}
                album={music.album}
                coverImg={music.coverImg}
                />
            </div>
            ))}
      </div>
    </div>
  );
}