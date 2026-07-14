import { getAlbum, getArtists, getMusic } from "@/services/entries";
import React, { useState, useEffect } from "react";

interface MusicCarouselCardProps {
    id: string;
    type?: string;
    title?: string;
    artists?: string;
    duration?: number | string;
    album?: string;
    cover?: string;
}

export const MusicCarouselCard: React.FC<MusicCarouselCardProps> = ({
    id,
    type = "track",
    title,
    artists,
    duration,
    album,
    cover
}) => {
    const [details, setDetails] = useState<{ title: string; artist: string; cover: string; duration: string } | null>(null);

    useEffect(() => {
        if (title && cover) {
            const dur = typeof duration === "number" ? duration + " s" : duration || "";
            setDetails({
                title,
                artist: String(artists || ""),
                cover,
                duration: dur
            });
            return;
        }

        async function fetchDetails() {
            if (!id) return;
            try {
                const resolvedType = type || "track";
                if (resolvedType === "track" || resolvedType === "music") {
                    const data = await getMusic({ music_id: id });
                    let artistName = "";
                    if (data.artists) {
                        try {
                            const artistData = await getArtists({ artists_id: data.artists });
                            artistName = artistData.name || "";
                        } catch (e) {
                            artistName = data.artists;
                        }
                    }
                    const durationSec = data.duration ? (data.duration / 1000).toFixed(0) : "0";
                    setDetails({
                        title: data.title || "",
                        artist: artistName,
                        cover: data.cover || "",
                        duration: durationSec + " s"
                    });
                } else if (resolvedType === "album") {
                    const data = await getAlbum({ album_id: id });
                    let artistName = "";
                    if (data.artists) {
                        try {
                            const artistData = await getArtists({ artists_id: data.artists });
                            artistName = artistData.name || "";
                        } catch (e) {
                            artistName = data.artists;
                        }
                    }
                    setDetails({
                        title: data.title || "",
                        artist: artistName,
                        cover: data.cover || "",
                        duration: "Álbum"
                    });
                } else if (resolvedType === "artist") {
                    const data = await getArtists({ artists_id: id });
                    setDetails({
                        title: data.name || "",
                        artist: "Artist",
                        cover: "/assets/Person.png",
                        duration: "Artista"
                    });
                }
            } catch (error) {
                console.error("Erro ao buscar detalhes no carrossel:", error);
            }
        }
        fetchDetails();
    }, [id, type, title, artists, duration, album, cover]);

    return (
        <div className="w-full">
            <a
                href={`/main/search/${id}/`}
                className="block hover:-translate-y-1 duration-300 ease-in-out hover:shadow-lg hover:shadow-green-500/30 rounded-md"
            >
                <div className="flex flex-col gap-4 bg-[#525B5B] items-center p-6 rounded-md w-full max-w-md">
                    <div className="w-40 h-40 bg-black rounded-lg flex-shrink-0 shadow-md">
                        <img
                            src={details?.cover || "/assets/music_logo.png"}
                            alt={"Capa de " + (details?.title || "Carregando")}
                            className="w-full h-full object-cover rounded-md"
                        />
                    </div>
                    
                    <div className="flex flex-row justify-between items-center w-full gap-4 mt-2 text-left">
                        <div className="flex flex-col gap-1 flex-1 min-w-0">
                            <h3 className="text-xl font-bold text-white leading-tight truncate">{details?.title || "Carregando..."}</h3>
                            <p className="text-gray-200 font-medium truncate">{details?.artist || ""}</p>
                            <p className="text-sm text-gray-400">{details?.duration || ""}</p>
                        </div>
                    </div>
                </div>
            </a>
        </div>
    );
}
