"use client";

import { useState, useEffect } from "react";
import { MusicCarouselCard } from "./musicCarouselCard";

interface searchResult {
    id: string;
    title: string;
    artists: string[];
    duration: number;
    album: string;
    cover: string;
}

export const SearchMusicBar = () => {
        const [requestedTerm, setRequestedTerm] = useState<string>("");
        const [results, setResults] = useState<searchResult[]>([]);
        const [isLoading, setIsLoading] = useState<boolean>(false);
        const url = "http://localhost:8080";
        const endpoint = "/search?type=track&query=";

        const fetchMusicAPI = async (query: string) => {
            if(!query.trim()) {
                setResults([]);
                return;
            }
            setIsLoading(true);
            try {
                const fullUrl = `${url}${endpoint}${encodeURIComponent(query)}`;
                const method = "GET";
                const response = await fetch(fullUrl, {
                    method,
                    headers: {
                        "Content-Type": "application/json",
                    },
                    body: undefined,
                });
                if (!response.ok) {
                    throw new Error('Erro ao buscar API de música');
                }
                const data = await response.json();
                setResults(data.items || data)
        }
        catch (error) {
            console.error('Error fetching music data:', error);
        }
        finally {
            setIsLoading(false);
        }
    }

    useEffect(() => {
        const delayTime = setTimeout(() => {
            if(requestedTerm.trim()) {
                fetchMusicAPI(requestedTerm);
            }
            else{
                setResults([]);
            }}, 500);
            return () => clearTimeout(delayTime);
        }, [requestedTerm]);

    return (
        <div className="flex flex-col w-full max-w-5xl py-6 px-4">
            <div className="flex flex-row w-full max-w-md rounded-2xl bg-[#FFFFFF] px-6 py-3 gap-2 items-center">
                <div className="w-5 h-5 -translate-x-0.5">
                    <img src="assets/search_icon.png" alt="Search icon" />
                </div>
                <input type="text" placeholder="Search for music..." value={requestedTerm} onChange={(e) => setRequestedTerm(e.target.value)} className="w-80 pb-0.5 border-b border-[#B7BFBE] font-bold text-[#122022] placeholder:text-[#BBC2C2] placeholder:font-medium focus:outline-none"/>
                
            </div>
            {isLoading && <p className="text-gray-500 mt-2">Searching for your musics...</p>}
            {!isLoading && results.length > 0 && (
                <div>
                    {results.map((music) => (
                        <MusicCarouselCard
                        id={music.id}
                        title={music.title}
                        artists={music.artists}
                        duration={music.duration/1000}
                        album={music.album}
                        cover={music.cover}
                        />
                        ))
                            }
                </div>
            )}
            {!isLoading && requestedTerm.trim() && results.length === 0 && (
                <div className="text-gray-200 mt-2">No musics found.</div>
            )}
        </div>
    );
}
