"use client";
import { useEffect, useState } from "react";
import { useAuth } from "../../../context/auth";
import { DynamicStar } from "./card_musicReview";

interface ReviewCardProps {
    id: string;
}

interface ReviewData {
    title: string;
    username: string;
    rating: number;
    text: string;
}

export const ReviewCard: React.FC<ReviewCardProps> = ({ id }) => {
    const { user } = useAuth();
    const [review, setReview] = useState<ReviewData | null>(null);
    const [isLoading, setIsLoading] = useState<boolean>(true);

    useEffect(() => {
        const fetchReviewData = async () => {
            try {
                setIsLoading(true);
                const response = await fetch(`http://localhost:8080/reviews/${id}`); 
                
                if (!response.ok) throw new Error("Erro na requisição");
                
                const data: ReviewData = await response.json();
                setReview(data);
            } catch (error) {
                console.error("Erro ao buscar os dados da review:", error);
            } finally {
                setIsLoading(false);
            }
        };

        if (id) {
            fetchReviewData();
        }
    }, [id]);

    if (isLoading) {
        return <div className="px-4">Carregando review...</div>;
    }

    if (!review) {
        return <div className="px-4 text-red-500">Erro ao carregar a review.</div>;
    }

    return(
        <div className="flex flex-col content-start px-4 w-full h-flex ">
            <div className="flex flex-row items-center gap-4">
                <img src="/assets/Person.png" alt="User Image" className="w-10 h-10 -translate-y-2 -translate-x-1"/>
                <h3 className="font-semibold">{ user?.name || review.username || "" }</h3>
                <DynamicStar rating={review.rating ? review.rating : 0} /> 
            </div>
            <p className="text-[#727979]">{review.text ? review.text : "text review undefined"}</p>
        </div>
    );
}