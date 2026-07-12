import react from "react";
import { MusicCarouselCard }  from "./musicCarouselCard";

const MockMusics= [{id: "1", title: "Music 1", artist: ["Artist 1"], album: "Album 1", duration: 21000, coverImg: "/assets/music1.jpg"},
{id: "2", title: "Music 2", artist: ["Artist 2"], album: "Album 2", duration: 18000, coverImg: "/assets/music2.jpg"},
{id: "3", title: "Music 3", artist: ["Artist 3"], album: "Album 3", duration: 24000, coverImg: "/assets/music3.jpg"},
{id: "4", title: "Music 4", artist: ["Artist 4"], album: "Album 4", duration: 20000, coverImg: "/assets/music4.jpg"},
{id: "5", title: "Music 5", artist: ["Artist 5"], album: "Album 5", duration: 22000, coverImg: "/assets/music5.jpg"},
{id: "6", title: "Music 6", artist: ["Artist 6"], album: "Album 6", duration: 19000, coverImg: "/assets/music6.jpg"},
{id: "7", title: "Music 7", artist: ["Artist 7"], album: "Album 7", duration: 23000, coverImg: "/assets/music7.jpg"}];

export const musicsCarrousel = () => {
    return (
    <div className="w-full max-w-5xl py-6 px-4">
      <h2 className="text-xl font-bold text-gray-100 mb-4">Reviews Recentes</h2>

      <div 
        className="flex gap-4 overflow-x-auto pb-4 snap-x snap-mandatory scrollbar-thin scrollbar-thumb-gray-700 scrollbar-track-transparent"
        style={{ scrollbarWidth: 'none' }}
      >
        {MockMusics.map((music) => (
          <div key={music.id} className="snap-start shrink-0 w-[300px]">
            <MusicCarouselCard
              title={music.title}
              artist={music.artist}
              duration={music.duration}
              album={music.album}
              coverImg={music.coverImg}
            />
          </div>
        ))}
      </div>
    </div>
  );
}