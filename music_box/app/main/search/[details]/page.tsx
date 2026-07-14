"use client";
import { ReviewsList } from "@/app/main/components/listReviews";
import { ReviewForm } from "@/app/main/components/review_form";
import { ReviewCard } from "@/app/main/components/reviewCard";
import react, { useState } from "react";

interface MusicDetailsProps {
    id: string;
    title: string;
    artist: string[];
    duration: any;
    album: string;
    coverImg: string;
    isReviewed: boolean;
    // data: string;
}
// TODO: overall rating for the music, based on user reviews. This can be a number between 0 and 5, where 0 means no rating and 5 means the highest rating.
export default function MusicDetails({ id, title, artist, duration, album, coverImg, isReviewed }: MusicDetailsProps){
    const [isReviewOpen, setIsReviewOpen] = useState(false)

    return(
        <div className="flex flex-col w-full items-center justify-center min-h-screen py-2">
            <div className="flex flex-col gap-4 items-center justify-center">
                <div className="w-80 h-80 bg-black rounded-lg flex-shrink-0 shadow-md">
                    <img src={coverImg} alt={"Capa de " + title} className="w-64 h-64 object-cover rounded-md"/>
                </div>
                <h2 className="font-black">{title ? title : "undefined"}</h2>
                <div className="flex flex-row w-full gap-2 text-[#727979]">
                    <p>{artist ? artist.join(", ") : "undefined Artist"}</p>
                    <span>&middot;</span>
                    <p>{duration ? duration/1000 + "s" : "undefined Duration"}</p>
                    <span>&middot;</span>
                    <p>{album ? album : "undefined Album"}</p>
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
                musicId = {id}
                musicTitle = {title}
                cover = {coverImg}
            />
            {/* Review list */}
            <div className="flex flex-col">
                {/* <ReviewsList></ReviewsList> */}
            </div>
        </div>
    );
}