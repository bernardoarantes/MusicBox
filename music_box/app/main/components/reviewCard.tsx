"use client";
import { useEffect, useState } from "react";
import { useAuth } from "../../../context/auth";
import { DynamicStar } from "./card_musicReview";
import { getMusic, getAlbum, getArtists, getUsername } from "@/services/entries";

interface ReviewData {
    id: string,
    owner_id: string,
    target_id: string,
    comment: string,
    rating: number;
    type: string,
}

export const ReviewCard: React.FC<ReviewData> = ({ id, owner_id, target_id, comment, rating, type }) => {
    const [username, setUsername] = useState<string>("");
    const [albumCover, setAlbumCover] = useState<string>("");

    useEffect(() => {
        async function fetchUsername(){
            if (!owner_id) return;
            try{
                const data = await getUsername({ user_id: owner_id });
                setUsername(data.name || "");
            }catch(Err){
                console.error("Não foi possível obter username.", Err);
                setUsername("Usuário Desconhecido");
            }
        }
        fetchUsername();
    }, [owner_id]);

    useEffect(() => {
        async function fetchAlbumCover(){
            if (!target_id) return;
            try{
                if (type === "track" || type === "music") {
                    const data = await getMusic({music_id: target_id});
                    setAlbumCover(data.cover || "");
                } else if (type === "album") {
                    const data = await getAlbum({album_id: target_id});
                    setAlbumCover(data.cover || "");
                } else if (type === "artist") {
                    setAlbumCover("/assets/Person.png");
                }
            }catch(error){
                console.error("Capa da musica não encontrada.", error);
                setAlbumCover("/assets/Person.png");
            }
        }
        fetchAlbumCover();
    }, [target_id, type]);

    return(
        <div className="flex flex-col content-start px-4 w-full h-flex ">
            <div className="flex flex-row items-center gap-4">
                <img 
                  src={albumCover || "/assets/Person.png"} 
                  alt="User Image" 
                  className="w-10 h-10 -translate-y-2 -translate-x-1 object-cover rounded-full"
                />
                <h3 className="font-semibold text-white">{ username || "" }</h3>
                <DynamicStar rating={rating ? rating : 0} /> 
            </div>
            <p className="text-[#727979] text-left mt-1">{comment ? comment : "text review undefined"}</p>
        </div>
    );
}
