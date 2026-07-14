"use client";
import { useEffect, useState } from "react";
import { useAuth } from "../../../context/auth";
import { DynamicStar } from "./card_musicReview";
import { getMusic, getUsername } from "@/services/entries";

interface ReviewData {
    id: string,
    owner_id: string,
    target: string,
    comment: string,
    rating: number;
    type: string,
}

export const ReviewCard: React.FC<ReviewData> = ({ id, owner_id, target, comment, rating, type}) => {
    const [username, setUsername] = useState<String>()
    const [albumCover, setAlbumCover] = useState<string>()
    useEffect(() => {
        async function fetchUsername(){
            if (!owner_id) return;
            try{
                const data = await getUsername({ user_id: owner_id });
                setUsername(data.name || "");
            }catch(Err){
                console.error("Não foi possível obter username.")
            }
        }
        fetchUsername();
    }, [owner_id]);

    async function fetchAlbumCover(){
        try{
            const data = await getMusic({music_id: target})
            setAlbumCover(data.cover);
        }catch(error){
            console.error("Capa da musica não encontrada.")
        }
    }fetchAlbumCover();

    return(
        <div className="flex flex-col content-start px-4 w-full h-flex ">
            <div className="flex flex-row items-center gap-4">
                <img src={albumCover? albumCover : ""} alt="User Image" className="w-10 h-10 -translate-y-2 -translate-x-1"/>
                <h3 className="font-semibold">{ username || "" }</h3>
                <DynamicStar rating={rating ? rating : 0} /> 
            </div>
            <p className="text-[#727979]">{comment ? comment : "text review undefined"}</p>
        </div>
    );
}