#ifndef GAMEEXCEPTION_H
#define GAMEEXCEPTION_H

#include <exception>
#include <string>

class GameException : public std::exception {
private:
    std::string message;
public:
    explicit GameException(const std::string& msg);
    const char* what() const noexcept override;
};

#endif
