"use client";

import { useState, useEffect } from "react";
import { useParams } from "next/navigation";
import { getMusic } from "@/services/entries";
import { ReviewForm } from "@/app/main/components/review_form";

interface MusicDetailsProps {
    id: string;
    title: string;
    artists: string[];
    duration: any;
    album: string;
    cover: string;
    isReviewed?: boolean;
}

export default function MusicDetails(){
    const params = useParams<{details: string }>();
    const music_id = params.details ? decodeURIComponent(params.details) : "";

    const [isReviewOpen, setIsReviewOpen] = useState(false)
    const [music, setMusic] = useState<MusicDetailsProps | null>(null);
    const [loading, setLoading] = useState(true);

    useEffect(() => {
        if(!music_id)return;

        async function fetchMusic(){
            try{
                const data = await getMusic({ music_id: music_id ? music_id : ""});
                setMusic(data)
            } catch(err){
                console.error("Nao foi possivel pegar a musica.")
            } finally {
                setLoading(false)
            }
        }
        fetchMusic();
    }, [music_id]);

    if (loading) {
        return <div className="p-4 text-gray-400">Carregando...</div>;
    }

    if (!music) {
        return <div className="p-4 text-gray-400">Musica nao encontrada.</div>;
    }

    return(
        <div className="flex flex-col w-full items-center justify-center min-h-screen py-2">
            <div className="flex flex-col gap-4 items-center justify-center">
                <div className="w-80 h-80 bg-black rounded-lg flex-shrink-0 shadow-md">
                    <img src={music.cover} alt={"Capa de " + music.title} className="w-64 h-64 object-cover rounded-md"/>
                </div>
                <h2 className="font-black">{music.title ? music.title : "undefined"}</h2>
                <div className="flex flex-row w-full gap-2 text-[#727979]">
                    <p>{music.artists ? music.artists.join(", ") : "undefined Artist"}</p>
                    <span>&middot;</span>
                    <p>{music.duration ? music.duration/1000 + "s" : "undefined Duration"}</p>
                    <span>&middot;</span>
                    <p>{music.album ? music.album : "undefined Album"}</p>
                </div>
                    {music.isReviewed ? (
                        <button disabled className="rounded-md bg-green-400 text-white px-4 py-2 hover:bg-green-600">
                            Review
                        </button>
                        ) :
                        <button onClick={() => {setIsReviewOpen(true)}} className="rounded-md bg-green-500 text-white px-4 py-2 hover:bg-green-600 duration-300 ease-in-out">
                            Review
                        </button>
                    }
            </div>
            <div className="w-full h-0.5 color-[#727979]"></div>
            <ReviewForm
                isOpen = {isReviewOpen}
                onClose = {() => setIsReviewOpen(false)}
                musicId = {music.id}
                musicTitle = {music.title}
                cover = {music.cover}
            />
            {/* Review list */}
            <div className="flex flex-col">
                {/* <ReviewsList></ReviewsList> */}
            </div>
        </div>
    );
}