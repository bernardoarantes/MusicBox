import "@/app/globals.css";
import { Header } from "./components/header";
import { Footer } from "./components/footer";

export default function RootLayout({
  children,
}: Readonly<{
  children: React.ReactNode;
}>) {
  return (
    <>
      <Header />
      
      <main className="flex-grow flex flex-col">
        {children}
      </main>

      <Footer />
    </>
  );
}
