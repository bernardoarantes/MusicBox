"use client";
import { useEffect, useState } from "react";
import { useAuth } from "../../../context/auth";
import { DynamicStar } from "./card_musicReview";
import { getUsername } from "@/services/entries";

interface ReviewData {
    id: string,
    owner_id: string,
    target: string,
    comment: string,
    rating: number;
    type: string,
}

export const ReviewCard: React.FC<ReviewData> = ({ id, owner_id, target, comment, rating, type}) => {
    const [review, setReview] = useState<ReviewData | null>(null);
    const [username, setUsername] = useState<String>()
    const [isLoading, setIsLoading] = useState<boolean>(true)

    useEffect(() => {
        async function fetchUsername(){
            try{
                //getuser
                const data = await getUsername({ user_id: owner_id ? owner_id : "" })
                setUsername(data);
            }catch(Err){
                console.error("Não foi possível obter username.")
            }
        }fetchUsername();
    },[username]);

    return(
        <div className="flex flex-col content-start px-4 w-full h-flex ">
            <div className="flex flex-row items-center gap-4">
                <img src="/assets/Person.png" alt="User Image" className="w-10 h-10 -translate-y-2 -translate-x-1"/>
                <h3 className="font-semibold">{ username || "" }</h3>
                <DynamicStar rating={rating ? rating : 0} /> 
            </div>
            <p className="text-[#727979]">{comment ? comment : "text review undefined"}</p>
        </div>
    );
}