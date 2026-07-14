"use client";

import { useEffect, useState } from "react";
import { ReviewCard } from "./reviewCard";
import { useAuth } from "@/context/auth";
import { listMusicEntries } from "../../services/entries"

interface reviews {
    id: string,
    username: string,
    title: string,
    rating: number,
    text: string
}
export const ReviewsList = ( { params }: { params: { musicId:string }}) => {
    const [reviews, setReviews] = useState<reviews[]>([])
    const musicId = params.musicId;
    const { user } = useAuth();

    useEffect(() => {
        const fetchReviews = async() => {
            if(musicId == null || musicId == ""){return}
            try{
                    const data: reviews[] = await listMusicEntries({ id: musicId});
                    setReviews(data);
            }
            catch(error){
                console.error("Erro ao buscar Reviews.")
            } fetchReviews();
        }
    })

    return (
        <div className="flex flex-col w-full max-w-4xl mt-8 px-4 pb-20">
            <h2 className="text-xl font-bold text-gray-200 mb-6 border-b border-gray-700 pb-2">
                Reviews da Comunidade ({reviews.length})
            </h2>

            <div className="flex flex-col gap-6">
                {reviews.map((reviews : reviews) => (
                    <ReviewCard
                        key={reviews.id}
                        id={reviews.id}
                        username={user?.name || ""}
                        title={reviews.title}
                        rating={reviews.rating}
                        text={reviews.text}
                    />
                ))}
            </div>
            {reviews.length === 0 && (
                <p className="text-gray-500 text-center py-4">
                    Nenhuma review ainda. Seja o primeiro a avaliar!
                </p>
            )}
        </div>
    );
};