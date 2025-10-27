#pragma once
#include "Coordinate.h"

class PlayerObserver
{
public:
    virtual void OnPlayerMove(const Coordinate<int>& newPosition) = 0;
    virtual ~PlayerObserver() = default;
};
