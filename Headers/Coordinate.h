#pragma once
template <typename T>
class Coordinate
{
public:
    T x;
    T y;

    Coordinate(T x, T y) : x(x), y(y) {}
};
