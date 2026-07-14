import { Link, Star } from "lucide-react";
import { useEffect, useState } from "react";
import { useAuth } from "@/context/auth";
import { error } from "console";


interface ReviewFormProps {
  isOpen: boolean,
  onClose: () => void,
  music_id: string,
  musicTitle: string,
  cover: string,
  initialComment?: string;
  initialRating?: number;
  type?: string;
  onCancel?: () => void;
  onSubmit?: (userId:string, musicId:string, comment: string, rating: number, type: string) => void;
}


export function ReviewForm({isOpen, onClose, music_id, musicTitle, cover, initialComment = "", initialRating = 0, type = "music", onSubmit }: ReviewFormProps) {
  const musicId = music_id;
  const { user } = useAuth();
  const [comment, setComment] = useState(initialComment);
  const [rating, setRating] = useState(initialRating);
  const [hoverRating, setHoverRating] = useState(0);

  const handleSave = async () => {
    try {
      const res = await fetch("http://localhost:8080/create-entry", {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify({user_id: user?.id || "", music_id: musicId, comment: comment, rating: (rating*2), type: type, }),
      });
      if (!res.ok) {
        return (<div className="font-semibold">
          Erro ao salvar review
        </div>)
      }
      console.log("Review salva com sucesso!");
      onClose(); 
    } catch (error) {
      console.error("Erro ao salvar a review:", error);
    }
  };


  if(!isOpen) return null;
  
  return (
    <div className="fixed inset-0 z-50 flex items-center justify-center bg-black/80 backdrop-blur-sm p-4">
      <div className="flex flex-col gap-4 bg-[#122022] w-flex min-w-[40%] px-10 py-8 rounded-lg">
        <div className="flex w-full h-4 border-gray-300 border-b-1 items-center"><h3 className="flex pb-4 font-bold">I listened...</h3></div>
        <div className="flex flex-row gap-10 items-center">
          <img src={cover} alt={"Capa de " + {musicTitle}} className="w-12 h-12 rounded object-cover"/>
          <div className="flex flex-col w-full gap-4">
          <h3 className="font-bold">{musicTitle}</h3>
            <div className="flex items-center gap-6">
              <div className="w-full flex flex-row items-center justify-between">
                <span className="flex font-semibold">Rating:</span>
                <div className="flex flex-row items-center pt-1" onMouseLeave={() => setHoverRating(0)}>
                  {[1, 2, 3, 4, 5].map((index) => {
                    const fillValue = hoverRating || rating;
                    const isHalf = fillValue >= index - 0.5;
                    const isFull = fillValue >= index;
                    return(
                      <div key={index} className="relative cursor-pointer transition-transform hover:scale-110">
                        <Star size={24} className="text-gray-500"/>
                        {isHalf && (
                          <div
                            className={`absolute top-0 left-0 overflow-hidden ${
                              isFull ? "w-full" : "w-1/2"
                            }`}
                          >
                            <Star size={24} className="fill-[#00e054] text-[#00e054]" />
                          </div>
                        )}
                        <div
                          className="absolute top-0 left-0 w-1/2 h-full z-10"
                          onMouseEnter={() => setHoverRating(index - 0.5)}
                          onClick={() => setRating(index - 0.5)}
                        />
                        <div
                          className="absolute top-0 right-0 w-1/2 h-full z-10"
                          onMouseEnter={() => setHoverRating(index)}
                          onClick={() => setRating(index*2)}
                        />
                      </div>
                    )
                  })}

                </div>
              </div>
            </div>
            
            <textarea
              value={comment}
              onChange={(e) => setComment(e.target.value)}
              placeholder="Escreva sua review aqui..."
              className="rounded-md p-2 w-full bg-[#B7BFBE] placeholder:font-medium text-[#122022] focus:outline-0"
              rows={4}
            />
          </div>
        </div>
        <div className="w-full flex justify-end gap-6 items-center flex-row">
          <div className="flex">
              <button onClick={handleSave} className="px-4 py-2 rounded-xl bg-black text-white hover:bg-grey-400">
              Salvar
              </button>
          </div>
          <div className="flex">
              {/* deve voltar para a tela de details daquele som */}
              <button onClick={onClose} className="bg-red-700 px-4 py-2 rounded-xl text-grey-300 hover:text-white trasition-colors hover:border-red-700 hover:bg-grey-400 hover:">Cancelar</button>
          </div>
        </div>
      </div>
    </div>
  );
}