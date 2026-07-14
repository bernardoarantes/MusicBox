"use client";

import { useEffect } from "react";
import { usePathname, useRouter } from "next/navigation";
import { useAuth } from "./auth";

const PUBLIC_ROUTES = ["/auth/login", "/auth/register", "/auth/forgot_password"];

export function RouteGuard({ children }: { children: React.ReactNode }) {
  const { user, loading } = useAuth();
  const pathname = usePathname();
  const router = useRouter();

  const isPublicRoute = PUBLIC_ROUTES.includes(pathname);

  useEffect(() => {
    if (loading) return;

    if (!user || !isPublicRoute) {
      router.replace("/auth/login");
    }

    if (user && isPublicRoute) {
      router.replace("/");
    }
  }, [user, loading, isPublicRoute, router]);

  if (loading) return null;
  if (!user && !isPublicRoute) return null;
  if (user && isPublicRoute) return null;

  return <>{children}</>;
}