#ifndef ENTITYNOTFOUNDEXCEPTION
#define ENTITYNOTFOUNDEXCEPTION

#include <exception>
#include <string>

using std::exception;
using std::string;

class EntityNotFoundException : public exception {
    private:
        const string message;

    public:
        explicit EntityNotFoundException(const string &message) :
            message(message) {}

        const char *what() const noexcept override {
            return message.c_str();
        }
};

#endif
