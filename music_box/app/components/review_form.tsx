import { Link } from "lucide-react";
import { useState } from "react";

interface ReviewFormProps {
  initialComment?: string;
  initialRating?: number;
  onSubmit: (comment: string, rating: number) => void;
  onCancel: () => void;
}

export function ReviewForm({ params }: { params: { id: string } }, { initialComment = "", initialRating = 0, onSubmit }: ReviewFormProps) {
  const music_id = params.id;
  const [comment, setComment] = useState(initialComment);
  const [rating, setRating] = useState(initialRating);
  
  return (
    <div className="flex flex-col gap-4">
      <textarea
        value={comment}
        onChange={(e) => setComment(e.target.value)}
        placeholder="Escreva sua review aqui..."
        className="border rounded-md p-2 w-full"
        rows={4}
      />
      <div className="flex items-center flex-row">
        <div className="flex">
            <button onClick={() => onSubmit(comment, rating)} className="px-4 py-2 rounded-md bg-black text-white">
            Salvar
            </button>
        </div>
        <div className="flex">
            {/* deve voltar para a tela de details daquele som */}
            <Link href={"search/" + music_id} className="links">Cancelar</Link>
        </div>
      </div>
    </div>
  );
}