/* /profile/ */

"use client";

import Link from "next/link";
import Image from "next/image";
import { useRouter } from 'next/navigation';
import { useEffect, useState } from "react";
import { useAuth } from "../../context/auth";
import { listUserEntries } from "../../services/entries";
import { CardMusicReview } from "../components/card_musicReview";

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
    const router = useRouter();
    const { user, logout } = useAuth();
    const [entries, setEntries] = useState<any[]>([]);

    useEffect(() => {
        async function fetchEntries() {
            try {
                const data = await listUserEntries({ id : user?.id || "" });
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
                <p className="maintext">{user?.name || ""}</p>
                <Image src="/assets/Test Account.png" alt="profile default" width={100} height={100} />
            </div>

            <div className="items-center ">
                <p className="maintext">{entries.length}</p>
                <p className="subtext">total reviews</p>
            </div>

            <div className="flex-col flex space-y-3 pb-20">
                {entries.map((entry) => (
                    // <Link href={"search/" + entry.target_id}>
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
                    // </Link>
                ))}
            </div>

            <div className="flex items-center pb-20 hover-y-1">
                <button onClick={() => { logout(); router.push("/auth/login"); }}>
                    Logout
                </button>
            </div>
        </div>
    )
}