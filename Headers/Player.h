#pragma once
#include "GameObj.h"
#include "Coordinate.h"
#include <memory>

template <typename T>
class Player : public GameObj
{
private:
    Coordinate<T> position;
    int startX;
    int startY;

public:
    Player(int width) : position(width / 2, 0), startX(width / 2), startY(0) {}
    Player(const Player& other)
        : position(other.position), startX(other.startX), startY(other.startY) {
    }

    // Getters
    T getX() const { return position.x; }
    T getY() const { return position.y; }

    // Abstract class overrides
    void Move() override {}
    bool CheckPos(int) const override { return false; }

    std::unique_ptr<GameObj> Clone() const override
    {
        return std::make_unique<Player>(*this);
    }

    // Movement controls
    void moveLeft() { position.x--; }
    void moveRight() { position.x++; }
    void moveUp() { position.y--; }
    void moveDown() { position.y++; }

    // Reset player to start
    void ResetPosition()
    {
        position.x = startX;
        position.y = startY;
    }

    Coordinate<T> GetPosition() const { return position; }
};
