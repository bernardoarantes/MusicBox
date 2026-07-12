/* auth/forgot_password/ */

"use client";

import Link from "next/link";
import { useState, FormEvent } from "react";
import { newPasswordValidator, emailValidator, passwordValidator } from "../../../core/utils";

export default function ForgotPasswordForm() {
    const [email, setEmail] = useState("");
    const [password1, setPassword1] = useState("");
    const [password2, setPassword2] = useState("");
    const [errors, setErrors] = useState({ email: "", password1: "", match: "" });

    function handleSubmit(e: FormEvent) {
        e.preventDefault();

        const emailError = emailValidator(email);
        const passwordError = passwordValidator(password1);
        const matchError = passwordError ? "" : newPasswordValidator(password1, password2);
        setErrors({ email: emailError, password1: passwordError, match: matchError });

        if (emailError || passwordError || matchError) return;

        // change password endpoint
    }

    return (
    <div className="flex flex-col items-center text-center py-10 space-y-10">
        <h1 className="mb-1 text-xl font-bold text-fog">Redefina sua senha!</h1>

        <form onSubmit={handleSubmit} className="items-center space-y-3" noValidate>
        <div className="space-y-3">
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
            <div>
            <label htmlFor="password1" className="sr-only">
                Nova Senha
            </label>
            <input
                id="password1"
                name="password1"
                type="password1"
                value={password1}
                 onChange={(e) => setPassword1(e.target.value)}
                placeholder="Nova senha"
                className="w-full rounded-md border border-surface2 bg-surface px-3 py-2.5 text-sm text-fog outline-none"
            />
            {errors.password1 && <p className="mt-1 text-left text-xs text-red-400">{errors.password1}</p>}
            </div>
            <div>
            <label htmlFor="password2" className="sr-only">
                Senha
            </label>
            <input
                id="password2"
                name="password2"
                type="password2"
                value={password2}
                 onChange={(e) => setPassword2(e.target.value)}
                placeholder="Repita a senha"
                className="w-full rounded-md border border-surface2 bg-surface px-3 py-2.5 text-sm text-fog outline-none"
            />
            {errors.match && <p className="mt-1 text-left text-xs text-red-400">{errors.match}</p>}
            </div>
        </div>
        <button
            type="submit"
            className="enter_btn w-full rounded-md border border-surface2 bg-surface px-3 py-2.5 text-sm text-fog outline-none">
            Renovar senha
        </button>
        </form>

        <Link href="/auth/login" className="links">
        Voltar para o login
        </Link>
    </div>
    );
    }