import { CardMusic } from "../components/card_music";

export default function ReviewLayout({ children }: { children: React.ReactNode }) {
    {/* pegar uma unidade de musica que a partir dos detalhes */}
    const MockMusic = {
        id: "1",
        title: "Music 1",
        artist: ["Artist 1"],
        album: "Album 1",
        duration: 210000,
        coverImg: "/assets/music1.jpg" // rating???
    }

    return (
        <div>
            <CardMusic {...MockMusic} />
            {children}
        </div>
    );
}