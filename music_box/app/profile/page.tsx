/* /profile/ */

"use client";

import Image from "next/image";
import { useEffect, useState } from "react";
import { listEntries } from "../../services/entries";
import { CardMusicReview } from "../components/card_musicReview";

interface Entry {
  id: string;
  title: string;
  artist: string;
  duration: string;
  album: string;
  cover_img: string;
//   rating: number;
}

export default function Profile() {
    {/* id, number_of_reviews, rating of each thing */}
    const [entries, setEntries] = useState<any[]>([]);

    useEffect(() => {
        async function fetchEntries() {
            try {
                const data = await listEntries({ user_id:''}); // have user id so i can get it
                setEntries(data);
            } catch (err) {
                console.error(err);
            }
        }
        fetchEntries();
    }, []);

    return(
        <div className="items-center text-center flex flex-col py-5">
            <div className="py-3">
                <p className="maintext"></p> {/* username */}
                <Image src="/assets/Test Account.png" alt="profile default" width={100} height={100} />
            </div>

            <div className="items-center ">
                <p className="maintext"></p> {/* number of reviews */}
                <p className="subtext">total reviews</p>
            </div>

            <div className="flex-col flex align-left">
                {entries.map((entry) => (
                    <CardMusicReview
                        title={entry.title}
                        artist={entry.artist}
                        duration={entry.duration}
                        rating={entry.rating}
                        coverImg={entry.cover_img}
                    />
                ))}
            </div>
        </div>
    )
}