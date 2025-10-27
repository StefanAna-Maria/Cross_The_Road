#pragma once
#include <exception>

class GameException : public std::exception
{
private:
    const char* message;

public:
    explicit GameException(const char* msg) : message(msg) {}
    const char* what() const noexcept override { return message; }
};
