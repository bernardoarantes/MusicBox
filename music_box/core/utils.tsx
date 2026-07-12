export const emailValidator = (email: string) => {
  const re = /^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,6}$/

  if (!email || email.length <= 0) return 'Email cannot be empty.';
  if (!re.test(email)) return 'Oops! Invalid Email.';

  return '';
};

export const passwordValidator = (password: string) => {
  if (!password || password.length <= 0) return 'Password cannot be empty.';
  if (password.length <8) return "Password should have 8 or more digits"

  return '';
};

export const nameValidator = (name: string) => {
  const letters = /^[A-Za-z]+$/;

  if (!name || name.length <= 0) return 'Name cannot be empty.';
  if (!letters.test(name)) return "Name field should be all chars"

  return '';
};

export const newPasswordValidator = (password1: string, password2: string) => {
  if (!(password1 === password2)) return "As senhas novas nao condizem"

  return ''
}