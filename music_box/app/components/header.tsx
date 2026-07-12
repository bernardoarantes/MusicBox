import react from "react";
import Image from "next/image";
import { SearchMusicBar } from "./SearchMusicBar";

export const Header = () => {
    return (
        <div className="flex flex-row items-center justify-between gap-20 p-4 bg-[#122022] text-white border-b px-40">
            <Image src="/assets/music_boxd.png" alt="MusicBoxd" width={100} height={100} />
            <div className="flex flex-row w-1/6 items-center justify-between gap-4">
                <a href="/review" className="text-white text-lg duration-300 ease-in-out font-bold hover:text-gray-300 hover:-translate-y-0.5">
                    Review
                </a>
                <a href="/profile" className="text-white text-lg duration-300 ease-in-out font-bold hover:text-gray-300 hover:-translate-y-0.5">
                    Profile
                </a>
                {/* {SearchMusicBar()}  */}
            </div>
        </div>
    )
}