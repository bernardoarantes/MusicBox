"use client";
import react from "react";
import { DynamicStar } from "./card_musicReview";

interface reviewCard {
    id: string,
    username: string,
    userId: string,
    title: string,
    rating: number,
    text: string,
}

export const ReviewCard: React.FC<reviewCard> = ({
    id,
    username,
    userId,
    title,
    rating,
    text
}) => {
    return(
        <div className="flex flex-col content-start px-4 w-full h-flex ">
            <div className="flex flex-row items-center gap-4">
                <img src="/assets/Person.png" alt="User Image" className="w-10 h-10 -translate-y-2 -translate-x-1"/>
                <h3 className="font-semibold">{username}</h3> 
                {/* mudar o usurname para criar uma request baseada no userId e receber o username */}
                <DynamicStar rating={rating ? rating : 0} />
            </div>
            <p className="text-[#727979]">{text ? text : "text review undefined"}</p>
        </div>
    );
}