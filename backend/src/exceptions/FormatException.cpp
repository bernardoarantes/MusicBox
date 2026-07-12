#include <exception>
#include <string>

class FormatException: public std:: exception {
    private:
        std::string message;
    public:
        // converte str pra FormatException
        explicit FormatException(const std::string& msg) { message = msg;}

        const char* what() const noexcept override {
            return message.c_str();
        }
};
