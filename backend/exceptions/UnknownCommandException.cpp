#include <exception>
#include <string>

class UnknownCommandException: public std:: exception {
    private:
        std::string message;
    public:
        // converte str pra UnknownCommandException
        explicit UnknownCommandException(const std::string& msg) { message = msg;}

        const char* what() const noexcept override {
            return message.c_str();
        }
};
