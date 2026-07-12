import Image from "next/image";
import { Header } from "./components/header";
import { MusicsCarrousel } from "./components/musics_carrousel";

export default function Home() {
  return (
    <div >
      <div className="flex min-h-screen flex-col items-center justify-between p-24">
        <MusicsCarrousel />
      </div>
    </div>

  );
}
