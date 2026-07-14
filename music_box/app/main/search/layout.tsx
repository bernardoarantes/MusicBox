import react from "react";

export default function ReviewLayout({ children }: { children: React.ReactNode }) {
  return (
    <div className="flex flex-col items-center min-h-screen py-2">
      {children}
    </div>
  );
}