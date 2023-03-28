#ifndef EXCEPTION_HPP
#define EXPCETION_HPP

#include <exception>

class RepresentationtypeException : public std::exception
{
private:
    char *message;

public:
    RepresentationtypeException(char *msg) : message(msg) {}
    char *what()
    {
        return message;
    }
};

#endif