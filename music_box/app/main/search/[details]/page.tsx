"use client";

import { useState, useEffect } from "react";
import { getAlbum, getArtists, getIsReviewed } from "@/services/entries";
import { useParams } from "next/navigation";
import { getMusic } from "@/services/entries";
import { ReviewForm } from "@/app/main/components/review_form";
import { useAuth } from "@/context/auth";

interface MusicDetailsProps {
    id: string;
    title: string;
    artists: string;
    duration: any;
    album: string;
    cover: string;
}

export default function MusicDetails(){
    const params = useParams<{details: string }>();
    const music_id = params.details ? decodeURIComponent(params.details) : "";
    const { user } = useAuth();
    const [isReviewOpen, setIsReviewOpen] = useState(false)
    const [isReviewed, setIsReviewed] = useState(false)
    const [music, setMusic] = useState<MusicDetailsProps | null>(null);
    const [loading, setLoading] = useState(true);
    const [albumEntity, setAlbum] = useState<string>("");
    const [artistList, setArtistList] = useState<string>("");


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

    async function fetchAlbum(){
        try{
            const data = await getAlbum({album_id : music?.album || ""});
            setAlbum(data.title);
        }
        catch(error){
            console.error("Album não encontrado")
        }
    }fetchAlbum();
    
    async function fetchArtist(){
        try{
            const data = await getArtists({artists_id : music?.artists || ""});
            setArtistList(data.name);
        }catch(error){
            console.error("Artistas não encontrado")
        }
    }fetchArtist();

    async function fetchIsReviewed(){
        const user_id = user?.id || "";
        try{
            const data = await getIsReviewed({user_id: user_id, music_id: music_id});
            setIsReviewed(data.bool)
        }catch(error){
            console.error("Não foi possível verificar se a review foi feita")
        }
    }fetchIsReviewed();

    return(
        <div className="flex flex-col w-full items-center justify-center min-h-screen py-2">
            <div className="flex flex-col gap-4 items-center justify-center">
                <div className="w-80 h-80 bg-black rounded-lg flex-shrink-0 shadow-md">
                    <img src={music.cover} alt={"Capa de " + music.title} className="w-80 h-80 object-cover rounded-md"/>
                </div>
                <h2 className="font-black">{music.title ? music.title : "undefined"}</h2>
                <div className="flex flex-row w-full gap-2 text-[#727979]">
                    <p>{artistList ? artistList : ""}</p>
                    <span>&middot;</span>
                    <p>{music.duration ? (music.duration/1000).toFixed(0) + "s" : ""}</p>
                    <span>&middot;</span>
                    <p>{albumEntity ? albumEntity : ""}</p>
                </div>
                    {isReviewed ? (
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
                music_id = {music.id}
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
