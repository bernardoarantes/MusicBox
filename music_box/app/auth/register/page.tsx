/* auth/register/ */

"use client";

import Link from "next/link";
import { useState, FormEvent } from "react";
import { nameValidator, emailValidator, passwordValidator } from "../../../core/utils";

export default function Register() {
  const [name, setName] = useState("");
  const [email, setEmail] = useState("");
  const [password, setPassword] = useState("");
  const [errors, setErrors] = useState({ name: "", email: "", password: "" });

  function handleSubmit(e: FormEvent) {
    e.preventDefault();

    const nameError = nameValidator(name);
    const emailError = emailValidator(email);
    const passwordError = passwordValidator(password);
    setErrors({ name: nameError, email: emailError, password: passwordError });

    if (nameError || emailError || passwordError) return;

    // register endpoint
  }

  return (
    <div className="flex flex-col items-center text-center space-y-5 py-5">
      <h1 className="py-5 mb-1 text-xl font-bold text-fog">Criar conta</h1>

      <form onSubmit={handleSubmit} className="items-center space-y-3" noValidate>
        <div>
          <label htmlFor="username" className="sr-only">
            Nome de usuário
          </label>
          <input
            id="username"
            name="username"
            type="text"
            value={name}
            onChange={(e) => setName(e.target.value)}
            placeholder="Nome"
            className="w-full rounded-md border border-surface2 bg-surface px-3 py-2.5 text-sm text-fog outline-none"
          />
          {errors.name && <p className="mt-1 text-left text-xs text-red-400">{errors.name}</p>}
        </div>
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
          Cadastrar
        </button>
      </form>

      <div className="items-center py-5">
      <p>Ja tem uma conta?</p>
      <Link href="/auth/login" className="links">
        Entrar
      </Link>
      </div>
    </div>
  );
}