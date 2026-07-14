import "../globals.css";
import { AuthProvider } from "@/context/auth";
import { Footer } from "../main/components/footer";

export default function RootLayout({
  children,
}: Readonly<{
  children: React.ReactNode;
}>) {
  return (
      <div className="min-h-full flex flex-col bg-[#122022]">

            {/* <RouteGuard> */}
                {children}
            {/* </RouteGuard> */}
        
      </div>
  );
}
