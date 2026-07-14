import Image from "next/image";
import { Header } from "./components/header";
import { ReviewsCarousel } from "./components/reviewsCarousel";
import { CarouselMusics } from "./components/carouselMusics";

export default function Home() {
  return (
    <div >
      {/* ver como o musicsCarousel receberá as musicas */}
      <div className="flex min-h-screen flex-col items-center justify-center gap-30 p-24">
        <ReviewsCarousel />
        <CarouselMusics/>
      </div>
    </div>

  );
}
