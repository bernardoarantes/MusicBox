/* /profile/ */

"use client";

import Image from "next/image";
import { useEffect, useState } from "react";
import { useAuth } from "../../context/auth";
import { listEntries } from "../../services/entries";
import { CardMusicReview } from "../components/card_musicReview";
import { EntryStatus } from "next/dist/client/components/segment-cache/cache";

const MockEntries = [{id: "1", title: "Music 1", artist: ["Artist 1"], album: "Album 1", duration: 210000, coverImg: "/assets/music1.jpg", rating: 2, commentary: "a"},
{id: "2", title: "Music 2", artist: ["Artist 2"], album: "Album 2", duration: 180000, coverImg: "/assets/music2.jpg", rating: 3, commentary: "a"},
{id: "3", title: "Music 3", artist: ["Artist 3"], album: "Album 3", duration: 240000, coverImg: "/assets/music3.jpg", rating: 1, commentary: "a"},
{id: "4", title: "Music 4", artist: ["Artist 4"], album: "Album 4", duration: 200000, coverImg: "/assets/music4.jpg", rating: 0, commentary: "a"},
{id: "5", title: "Music 5", artist: ["Artist 5"], album: "Album 5", duration: 220000, coverImg: "/assets/music5.jpg", rating: 5, commentary: "a"},
{id: "6", title: "Music 6", artist: ["Artist 6"], album: "Album 6", duration: 190000, coverImg: "/assets/music6.jpg", rating: 2, commentary: "a"},
{id: "7", title: "Music 7", artist: ["Artist 7"], album: "Album 7", duration: 230000, coverImg: "/assets/music7.jpg", rating: 3, commentary: "a"}];

interface Entry {
  title: string;
  artist: Array<string>;
  duration: number;
  album: string;
  coverImg: string;
  rating: number;
  commentary: string;
}

export default function Profile() {
    {/* id, number_of_reviews, rating of each thing */}
    const { user } = useAuth();
    const [entries, setEntries] = useState<any[]>([]);

    useEffect(() => {
        async function fetchEntries() {
            try {
                const data = await listEntries({ user_id : user?.id || "" }); // have user id so i can get it
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
                <p className="maintext"></p> {/* username, get throug api with user.id */}
                <Image src="/assets/Test Account.png" alt="profile default" width={100} height={100} />
            </div>

            <div className="items-center ">
                <p className="maintext">{entries.length}</p> {/* number of reviews */}
                <p className="subtext">total reviews</p>
            </div>

            <div className="flex-col flex space-y-3 pb-20">
                {/* {entries.map((entry) => ( */}
                {MockEntries.map((entry) => (
                    <CardMusicReview
                        id={entry.id}
                        title={entry.title}
                        artist={entry.artist}
                        duration={entry.duration}
                        rating={entry.rating}
                        coverImg={entry.coverImg}
                        album={entry.album}
                        commentary={entry.commentary}
                    />
                ))}
            </div>
        </div>
    )
}