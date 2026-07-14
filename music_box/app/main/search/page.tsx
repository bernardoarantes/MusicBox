import Image from "next/image";
import { SearchMusicBar } from "../components/SearchMusicBar";

export default function Home() {
  return (
    <div >
      {/* ver como o musicsCarousel receberá as musicas */}
      <div className="flex min-h-screen flex-col gap-30 p-24">
        <SearchMusicBar/>
      </div>
    </div>

  );
}