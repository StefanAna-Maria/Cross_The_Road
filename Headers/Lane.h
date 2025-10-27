#pragma once
#include "GameObj.h"
#include <deque>
#include <cstdlib>
#include <memory>

class Lane : public GameObj
{
protected:
    std::deque<bool> cars;
    int moveCounter = 0;

public:
    explicit Lane(int width);
    Lane(const Lane& other);

    void Move() override;
    bool CheckPos(int pos) const override;
    std::unique_ptr<GameObj> Clone() const override;
};
