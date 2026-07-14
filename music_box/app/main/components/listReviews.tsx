"use client";

import { useEffect, useState } from "react";
import { ReviewCard } from "./reviewCard";
import { useAuth } from "@/context/auth";
import { listMusicEntries } from "../../../services/entries"

interface reviews {
    id: string;
    owner_id: string;
    target_id: string,
    rating: number,
    type: string,
    comment: string
}
export const ReviewsList = ( { params }: { params: { musicId:string }}) => {
    const [reviews, setReviews] = useState<reviews[]>([])
    const musicId = params.musicId;
    const { user } = useAuth();

    useEffect(() => {
        const fetchReviews = async() => {
            if(musicId == null || musicId == ""){return}
            try{
                    const data = await listMusicEntries({ music_id: musicId});
                    setReviews(data);
            }
            catch(error){
                console.error("Erro ao buscar Reviews.")
            } fetchReviews();
        }
    }, [musicId]);

    return (
        <div className="flex flex-col w-full max-w-4xl mt-8 px-4 pb-20">
            <h2 className="text-xl font-bold text-gray-200 mb-6 border-b border-gray-700 pb-2">
                Reviews da Comunidade ({reviews.length})
            </h2>

            <div className="flex flex-col gap-6">
                {reviews.map((review) => (
                    <ReviewCard
                        key={review.id}
                        id={review.id}
                        target_id={review.target_id}
                        owner_id={review.owner_id}
                        comment={review.comment}
                        type={review.type}
                        rating={review.rating}
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
