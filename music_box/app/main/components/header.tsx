import Image from "next/image";

export const Header = () => {
    return (
        <div className="flex flex-row items-center justify-between bg-[#122022] text-white border-b px-40 border-[#BBC2C2] shadow-md shadow-green-200">
            <div className="flex-1 flex justify-start">
                <a href="/main">
                    <Image src="/assets/music_boxd.png" alt="MusicBoxd" width={100} height={100} />
                </a>
            </div>
            <div className="flex flex-row justify-end space-x-10">
                <div className="flex-1 flex">
                    <a href="/main/search" className="text-white text-lg duration-300 ease-in-out font-bold hover:text-gray-300 hover:-translate-y-0.5">
                        Search
                    </a>
                </div>
                <div className="flex-1 flex">
                    <a href="/main/profile" className="text-white text-lg duration-300 ease-in-out font-bold hover:text-gray-300 hover:-translate-y-0.5">
                        Profile
                    </a>
                </div>
            </div>
        </div>
    )
}