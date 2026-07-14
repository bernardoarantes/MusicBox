"use client";

import { useAuth } from "../../../context/auth";
import { DynamicStar } from "./card_musicReview";

interface reviewCard {
    id: string,
    title: string,
    username: string,
    rating: number,
    text: string,
}

export const ReviewCard: React.FC<reviewCard> = ({id,title,rating,text}) => {
    const { user } = useAuth();

    return(
        <div className="flex flex-col content-start px-4 w-full h-flex ">
            <div className="flex flex-row items-center gap-4">
                <img src="/assets/Person.png" alt="User Image" className="w-10 h-10 -translate-y-2 -translate-x-1"/>
                <h3 className="font-semibold">{ user?.name || ""}</h3>
                <DynamicStar rating={rating ? rating : 0} />
            </div>
            <p className="text-[#727979]">{text ? text : "text review undefined"}</p>
        </div>
    );
}