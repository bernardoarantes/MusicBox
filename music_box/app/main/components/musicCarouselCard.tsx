import { getAlbum, getArtists } from "@/services/entries";
import React, {useState} from "react";

interface MusicCarouselCardProps {
    id: string;
    title: string;
    artists: string;
    duration: number;
    album: string;
    cover: string;
}


export const MusicCarouselCard: React.FC<MusicCarouselCardProps> = ({
    id,
    title,
    artists,
    duration,
    album,
    cover
}) => {
    const [albumEntity, setAlbum] = useState<string>("");
    const [artistList, setArtistList] = useState<string>("");

    React.useEffect(() => {
        async function fetchAlbum(){
            try{
                const data = await getAlbum({album_id : album});
                setAlbum(data.title || "");
            }
            catch(error){
                console.error("Album não encontrado")
            }
        }
        
        async function fetchArtist(){
            try{
                const data = await getArtists({artists_id : artists});
                setArtistList(data.name || "");
            }catch(error){
                console.error("Artistas não encontrado")
            }
        }

        if (album) fetchAlbum();
        if (artists) fetchArtist();
    }, [album, artists]);

  return (
    <div className="w-full">
        <a
            href={`/main/search/${id}/`}
            className="block hover:-translate-y-1 duration-300 ease-in-out hover:shadow-lg hover:shadow-green-500/30 rounded-md"
        >
            <div className="flex flex-col gap-4 bg-[#525B5B] items-center p-6 rounded-md w-full max-w-md">
                <div className="w-40 h-40 bg-black rounded-lg flex-shrink-0 shadow-md">
                    <img
                        src={cover}
                        alt={"Capa de " + title}
                        className="w-full h-full object-cover rounded-md"
                    />
                </div>
                
                <div className="flex flex-row justify-between items-center w-full gap-4 mt-2">
                    <div className="flex flex-col gap-1 text-left flex-1">
                        <h3 className="text-xl font-bold text-white leading-tight truncate">{title}</h3>
                        <p className="text-gray-200 font-medium truncate">{(artistList ? artistList : "")}</p>
                        <p className="text-sm text-gray-400">{duration} s</p>
                    </div>
                    
                    {/* Bloco da Direita: Nome do Álbum (Alinhado à direita) */}
                    <div className="text-right max-w-[40%]">
                        <p className="text-gray-300 text-sm font-semibold truncate">{albumEntity}</p>
                    </div>
                </div>
            </div>
        </a>
    </div>
  );
}
