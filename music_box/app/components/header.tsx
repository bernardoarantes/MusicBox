import react from "react";
// import { SearchMusicBar } from "./SearchMusicBar.tsx";

export const Header = () => {
    return (
        <div className="flex flex-row items-center justify-between gap-20 p-4 bg-[#122022] text-white border-b">
            <p className="appName">MusicBoxd</p>
            <div className="flex flex-row w-1/6 items-center justify-between gap-4">
                <a href="/review" className="text-white text-lg duration-300 ease-in-out font-bold hover:text-gray-300 hover:-translate-y-1">
                    Review
                </a>
                <a href="/profile" className="text-white text-lg duration-300 ease-in-out font-bold hover:text-gray-300 hover:-translate-y-1">
                    Profile
                </a>
                {/* {SearchMusicBar()}  */}
            </div>
        </div>
    )
}