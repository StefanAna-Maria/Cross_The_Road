#pragma once
#include "Game.h"

class Command
{
public:
    virtual void Execute(Game& game) = 0;
    virtual ~Command() = default;
};

class StartGameCommand : public Command
{
public:
    void Execute(Game& game) override;
};

class ExitGameCommand : public Command
{
public:
    void Execute(Game& game) override;
};
