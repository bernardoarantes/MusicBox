#ifndef USERENTITY
#define USERENTITY

#include "entity/Entity.cpp"
#include "exceptions/ValidationException.cpp"
#include <regex>

class UserEntity : public Entity {
    private:
        const string id;
        const string name;
        const string email;
        const string password;

    public:
        UserEntity(const string &id, const string &name, const string &email, const string &password) :
            id(id),
            name(name),
            email(email),
            password(password) {
                validateEmail();
                validateName();
            }

        const string getId() const override {
            return this->id;
        }

        const string getName() const {
            return this->name;
        }

        json toJson() const override {
            return "{\"id\":\"" + id + 
                   "\",\"name\":\"" + name +
                   "\",\"email\":\"" + email +
                   "\",\"password\":\"" + password +
                   "}";
        }

        void validateEmail() {
            if (this->email.empty())
                throw ValidationException("email cannot be empty");
            
            for (char c : this->email) 
                if (c == ' ')
                    throw ValidationException("email cannot contain blanks");

            if (!std::regex_match(this->email, std::regex("^[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,6}$", std::regex_constants::icase)))
                throw ValidationException("invalid email " + this->email);
        }

        void validateName() {
            if (this->name.empty())
                throw ValidationException("username cannot be empty");

            if (!std::regex_match(this->name, std::regex("^[A-Z0-9._%+-]+", std::regex_constants::icase)))
                throw ValidationException("invalid username " + name);
        }

        bool hasEmail(const string &email) const {
            return this->email == email;
        }

        bool hasPassword(const string &password) const {
            return this->password == password;
        }
};

#endif
