import { Link } from "lucide-react";
import { useState } from "react";


interface ReviewFormProps {
  isOpen: boolean,
  onClose: () => void,
  musicId: string,
  musicTitle: string,
  cover: string,
  initialComment?: string;
  initialRating?: number;
  onCancel?: () => void;
  onSubmit?: (title:string, comment: string, rating: number) => void;
}


export function ReviewForm({isOpen, onClose, musicId, musicTitle, cover, initialComment = "", initialRating = 0, onSubmit }: ReviewFormProps) {
  const music_id = musicId;
  const [comment, setComment] = useState(initialComment);
  const [title, setTitle] = useState("");
  const [rating, setRating] = useState(initialRating);
  const [hoverRating, setHoverRating] = useState(0);
  
  const handleSave = () => {
    if(onsubmit){
      onSubmit(title, comment, rating) //ver com o arantes como que é pra enviar uma review
    }
    onClose();
  }

  if(!isOpen) return null;
  
  return (
    <div className="fixed inset-0 z-50 flex items-center justify-center bg-black/80 backdrop-blur-sm p-4">
      <div className="flex flex-col gap-4 bg-[#525B5B] w-flex min-w-[40%] px-10 py-8 rounded-lg">
        <div className="flex flex-row gap-10 items-center">
          <img src={cover} alt={"Capa de " + {musicTitle}} className="w-12 h-12 rounded object-cover"/>
          <div className="flex flex-col w-full gap-4">
            <h3 className="font-bold">{musicTitle}oi</h3>
            <div className="w-full rounded-md p-2 bg-[#B7BFBE]">
              <input type="text" name="" id="" onChange={(e) => {setTitle(e.target.value)}} className="text-[#122022] w-full focus:outline-0 border-b-1 border-gray-100 placeholder:font-semibold" placeholder="Titulo..."/>
            </div>
            <textarea
              value={comment}
              onChange={(e) => setComment(e.target.value)}
              placeholder="Escreva sua review aqui..."
              className="rounded-md p-2 w-full bg-[#B7BFBE] placeholder:font-semibold text-[#122022] focus:outline-0"
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