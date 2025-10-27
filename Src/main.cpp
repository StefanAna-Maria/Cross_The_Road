#include "../Headers/Game.h"
#include "../Headers/Command.h"
#include <iostream>

template <typename T>
void PrintCoordinates(const Coordinate<T>& coord)
{
    std::cout << "X: " << coord.x << ", Y: " << coord.y << std::endl;
}

int ShowMenu()
{
    std::cout << "1. Start Game\n";
    std::cout << "2. Exit Game\n";
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;
    return choice;
}

int main()
{
    srand(time(NULL));
    Game::highScore = 0;
    Game::totalGames = 0;

    try
    {
        int choice;
        do
        {
            choice = ShowMenu();
            switch (choice)
            {
            case 1:
            {
                Game game(30, 5);

                class PlayerObserverImpl : public PlayerObserver
                {
                public:
                    void OnPlayerMove(const Coordinate<int>& newPosition) override
                    {
                        PrintCoordinates(newPosition);
                    }
                };

                PlayerObserverImpl observer;
                game.AddObserver(&observer);

                StartGameCommand startCommand;
                startCommand.Execute(game);
                break;
            }
            case 2:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter 1 or 2.\n";
                break;
            }
        } while (choice != 2);
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
