"use client";

import { useRef, useState, useEffect } from "react";
import { useAuth } from "../../context/auth"
import { MusicCarouselCard }  from "./musicCarouselCard";

interface Music {
    musicId: string,
    title: string,
    artists: string[],
    album: string,
    duration: number,
    cover: string
}

export const ReviewsCarousel = () => {
    const { user } = useAuth();
    const [reviewedMusics, setReviewedMusics] = useState<Music[]>([]);
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

    useEffect(() => {
        const fetchUserReviews = async() => {

            if(!user?.id) return
            try{
                // arrumar o end point :)
                const res = await fetch("http://seu-backend/api/login/", {
                        method: "POST",
                        headers: { "Content-Type": "application/json" },
                        body: JSON.stringify({ userId : user?.id }),
                    });
                    if(!res.ok){
                        throw new Error("Falha na requisação");
                    }
                    const data: Music[] = await res.json(); //recebe ids de cada music
                    setReviewedMusics(data)
                }
                catch(error){
                }
                    console.error("Erro ao buscar reviews.")
                }
                fetchUserReviews();
    }, [user?.id])

    if(!reviewedMusics || reviewedMusics.length == 0){
        return <div className="p-4 text-gray-400">Nenhuma Review encontrada.</div>
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
            {reviewedMusics.map((music) => (
            <div key={music.musicId} className="snap-start shrink-0 w-[300px] my-6 ">
                <MusicCarouselCard
                id={music.musicId}
                title={music.title}
                artists={music.artists}
                duration={music.duration/1000}
                album={music.album}
                cover={music.cover}
                />
            </div>
            ))}
      </div>
    </div>
  );
}