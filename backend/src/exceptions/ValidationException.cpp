#ifndef VALIDATIONEXCEPTION
#define VALIDATIONEXCEPTION

#include <exception>
#include <string>

using std::exception;
using std::string;

class ValidationException : public exception {
    private:
        const string message;

    public:
        explicit ValidationException(const string &message) :
            message(message) {}

        const char *what() const noexcept override {
            return message.c_str();
        }
};

#endif
