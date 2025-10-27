#include "../Headers/Command.h"
#include "../Headers/Game.h"

void StartGameCommand::Execute(Game& game)
{
    game.Run();
}

void ExitGameCommand::Execute(Game& game)
{
    // nu face nimic momentan
}
