"use client";
import React, { useState, useEffect } from "react";
import { MusicCarouselCard } from "./musicCarouselCard";

interface searchResult {
    id: string;
    title: string;
    artist: string[];
    duration: number;
    album: string;
    coverImg: string;
}

export const SearchMusicBar = () => {
        const [requestedTerm, setRequestedTerm] = useState<string>("");
        const [results, setResults] = useState<searchResult[]>([]);
        const [isLoading, setIsLoading] = useState<boolean>(false);

        const fetchMusicAPI = async (query: string) => {
            if(query.trim()) {
                setResults([]);
                return;
            }
            setIsLoading(true);
            try {
            const response = await fetch('https://localhost:8080/query-music', );
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
            }500;})
            return () => clearTimeout(delayTime);
        }, [requestedTerm]);

    return (
        <div className="flex flex-col w-full max-w-5xl py-6 px-4">
            <div className="w-full max-w-md">
                <input type="text" placeholder="Search music..." value={requestedTerm} onChange={(e) => setRequestedTerm(e.target.value)} className="w-full bg-[#FFFFFF] text-[#122022] placeholder:text-[#BBC2C2] border border-[#CCCCCC] focus:outline-none focus:ring-2 focus:ring-blue-500"/>
                
            </div>
            {isLoading && <p className="text-gray-500 mt-2">Searching for your musics...</p>}
            {!isLoading && results.length > 0 && (
                <div>
                    {results.map((music) => (
                        <MusicCarouselCard
                        key={music.id}
                        title={music.title}
                        artist={music.artist}
                        duration={music.duration}
                        album={music.album}
                        coverImg={music.coverImg}
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
