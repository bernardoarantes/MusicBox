interface CardMusicProp {
    id: string,
    title: string,
    artist: string[],
    duration: number,
    album: string,
    coverImg: string
}

export const CardMusic = ( {title, artist, duration, album, coverImg}: CardMusicProp) => {
  return (
    <div className="flex items-center p-4 rounded-md w-full max-w-md">
      <div className="w-16 h-16 rounded-lg flex-shrink-0">
        <img src={coverImg} alt={"Capa de " + title} className="w-16 h-16 object-cover rounded-md"/>
      </div>
      <div className="flex items-center gap-4 mt-1">
        <div className="flex flex-col gap-0.5 ml-2">
          <h3 className="text-lg font-bold">{title}</h3>
          <p className="text-gray-600">{artist}</p>
          <p>{album}</p>
          <p className="text-sm text-gray-500">{duration}</p>
        </div>
      </div>
    </div>
  );
}