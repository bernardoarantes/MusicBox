#include <exception>
#include <string>

class EntityNotFound: public std:: exception {
    private:
        std::string message;
    public:
        // converte str pra EntityNotFound
        explicit EntityNotFound(const std::string& msg) { message = msg;}

        const char* what() const noexcept override {
            return message.c_str();
        }
};
