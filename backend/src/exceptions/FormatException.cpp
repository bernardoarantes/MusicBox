#ifndef FORMATEXCEPTION
#define FORMATEXCEPTION

#include <exception>
#include <string>

using std::exception;
using std::string;

class FormatException : public exception {
    private:
        const string message;

    public:
        explicit FormatException(const string &message) :
            message(message) {}

        const char *what() const noexcept override {
            return message.c_str();
        }
};

#endif
