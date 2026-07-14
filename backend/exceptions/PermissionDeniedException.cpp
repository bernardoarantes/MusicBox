#include <exception>
#include <string>

class PermissionDeniedException: public std:: exception {
    private:
        std::string message;
    public:
        // converte str pra PermissionDeniedException
        explicit PermissionDeniedException(const std::string& msg) { message = msg;}

        const char* what() const noexcept override {
            return message.c_str();
        }
};
