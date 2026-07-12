/* auth/login/ */

"use client";

import Link from "next/link";
import Image from "next/image";
import { useState, FormEvent } from "react";
import { emailValidator, passwordValidator } from "../../../core/utils";

export default function Login() {
  const [email, setEmail] = useState("");
  const [password, setPassword] = useState("");
  const [errors, setErrors] = useState({ email: "", password: "" });

  function handleSubmit(e: FormEvent) {
    e.preventDefault();

    const emailError = emailValidator(email);
    const passwordError = passwordValidator(password);
    setErrors({ email: emailError, password: passwordError });

    if (emailError || passwordError) return;

    // login endpoint
  }

  return (
    <div className="flex flex-col items-center text-center">
      <div className="py-3">
        <Image src="/assets/music_boxd.png" alt="MusicBoxd" width={200} height={200} />
        <p>avalie musicas e albuns!</p>
      </div>
    
      <form onSubmit={handleSubmit} className="space-y-3 items-center" noValidate>
        <div>
          <label htmlFor="email" className="sr-only">
            E-mail
          </label>
          <input
            id="email"
            name="email"
            type="email"
            value={email}
            onChange={(e) => setEmail(e.target.value)}
            placeholder="E-mail"
            className="w-full rounded-md border border-surface2 bg-surface px-3 py-2.5 text-sm text-fog outline-none"
          />
          {errors.email && <p className="mt-1 text-left text-xs text-red-400">{errors.email}</p>}
        </div>
        <div>
          <label htmlFor="password" className="sr-only">
            Senha
          </label>
          <input
            id="password"
            name="password"
            type="password"
            value={password}
            onChange={(e) => setPassword(e.target.value)}
            placeholder="Senha"
            className="w-full rounded-md border border-surface2 bg-surface px-3 py-2.5 text-sm text-fog outline-none"
          />
          {errors.password && <p className="mt-1 text-left text-xs text-red-400">{errors.password}</p>}
        </div>
        <button
          type="submit"
          className="enter_btn w-full rounded-md border border-surface2 bg-surface px-3 py-2.5 text-sm text-fog outline-none"
        >
          Entrar
        </button>
      </form>

      <div className="items-center py-5">
        <p>Nao tem uma conta?</p>
        <Link href="/auth/register" className="links mt-6 text-sm text-slate hover:text-mist">
          Cadastrar
        </Link>
      </div>

      <div className="items-center py-5">
        <p>Esqueceu a senha?</p>
        <Link href="/auth/forgot_password" className="links">
          Redefinir Senha
        </Link>
      </div>
    </div>
  );
}