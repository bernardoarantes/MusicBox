import { Star, StarHalf } from 'lucide-react';
import { getMusic, getAlbum, getArtists } from "@/services/entries";
import React, { useEffect, useState } from "react";

interface DynamicStarProps {
  rating: number;
}

export const DynamicStar = ({ rating }: DynamicStarProps) => {
  const starsOutOfFive = rating / 2;

  return (
    <div className="flex gap-0.5 text-gray-300">
      {[...Array(5)].map((_, i) => {
        const starIndex = i + 1;

        if (starIndex <= starsOutOfFive) {
          return <Star key={i} size={14} className="text-gray-200 fill-current" />;
        } else if (starsOutOfFive >= starIndex - 0.75 && starsOutOfFive < starIndex) {
          return <StarHalf key={i} size={14} className="text-gray-200 fill-current" />;
        } else {
          return <Star key={i} size={14} className="text-gray-600 fill-current" />;
        }
      })}
    </div>
  );
};

interface CardMusicReviewProps {
    id: string;
    target_id: string;
    type: string;
    rating: number;
    comment: string;
}

export const CardMusicReview = ({ id, target_id, type, rating, comment }: CardMusicReviewProps) => {
  const [details, setDetails] = useState<{ title: string; artist: string; coverImg: string } | null>(null);

  useEffect(() => {
    async function fetchDetails() {
      if (!target_id) return;
      try {
        if (type === "track" || type === "music") {
          const data = await getMusic({ music_id: target_id });
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
            coverImg: data.cover || ""
          });
        } else if (type === "album") {
          const data = await getAlbum({ album_id: target_id });
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
            coverImg: data.cover || ""
          });
        } else if (type === "artist") {
          const data = await getArtists({ artists_id: target_id });
          setDetails({
            title: data.name || "",
            artist: "Artist",
            coverImg: "/assets/Person.png"
          });
        }
      } catch (err) {
        console.error("Erro ao carregar detalhes do item:", err);
      }
    }
    fetchDetails();
  }, [target_id, type]);

  return (
    <div className="flex flex-col gap-2 p-4 bg-[#1b2b2d] rounded-lg w-full max-w-md shadow-md text-left border border-surface2/30">
      <div className="flex items-center gap-4">
        <img 
          src={details?.coverImg || "/assets/music_logo.png"} 
          alt={details?.title || "Capa do item"} 
          className="w-16 h-16 bg-[#3C4445] object-cover rounded-md flex-shrink-0"
        />
        <div className="flex flex-col flex-1 min-w-0">
          <h3 className="text-white font-bold truncate">{details?.title || "Carregando..."}</h3>
          <p className="text-gray-400 text-sm truncate">{details?.artist || ""}</p>
        </div>
        <div className="flex flex-col items-end gap-1 flex-shrink-0">
          <DynamicStar rating={rating} />
          <span className="text-gray-400 text-xs font-semibold">{rating} / 10</span>
        </div>
      </div>
      {comment && (
        <div className="mt-2 pt-2 border-t border-[#3C4445]/50">
          <p className="text-gray-300 text-sm italic">"{comment}"</p>
        </div>
      )}
    </div>
  );
};
