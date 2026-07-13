"use client";
import React from "react";
// Importe o seu card (lembre-se de mudar para ReviewCard com letra maiúscula no seu arquivo!)
import { ReviewCard } from "./reviewCard"; 

// 1. Criamos um Mock de dados seguindo exatamente a sua interface reviewCard
const MockReviews = [
    {
        id: "rev1",
        username: "joao_farmaAura",
        userId: "user_123",
        title: "Obra prima!",
        rating: 10,
        text: "Esse álbum mudou a minha vida. As transições entre as faixas são perfeitas e a produção é impecável."
    },
    {
        id: "rev2",
        username: "arantesinho_do_67",
        userId: "user_456",
        title: "Bom, mas cansativo",
        rating: 6,
        text: "Achei a primeira metade incrível, mas da metade para o final as músicas começam a soar muito parecidas."
    },
    {
        id: "rev3",
        username: "laurinha_r",
        userId: "user_789",
        title: "Clássico",
        rating: 9.5,
        text: "Não tem como dar uma nota menor para um trabalho com tanto impacto na indústria."
    }
];

export const ReviewsList = () => {
    return (
        <div className="flex flex-col w-full max-w-4xl mt-8 px-4 pb-20">
            <h2 className="text-xl font-bold text-gray-200 mb-6 border-b border-gray-700 pb-2">
                Reviews da Comunidade ({MockReviews.length})
            </h2>

            <div className="flex flex-col gap-6">
                {MockReviews.map((review) => (
                    <ReviewCard
                        key={review.id}
                        id={review.id}
                        username={review.username}
                        userId={review.userId}
                        title={review.title}
                        rating={review.rating}
                        text={review.text}
                    />
                ))}
            </div>
            {MockReviews.length === 0 && (
                <p className="text-gray-500 text-center py-4">
                    Nenhuma review ainda. Seja o primeiro a avaliar!
                </p>
            )}
        </div>
    );
};