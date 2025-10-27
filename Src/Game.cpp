#include "../Headers/Game.h"
#include "../Headers/Coordinate.h"
#include <ctime>

int Game::highScore = 0;
int Game::totalGames = 0;

Game::Game(int w, int h)
    : width(w), numberOfLanes(h), quit(false), score(0), gameOver(false)
{
    srand(time(0));

    for (int i = 0; i < numberOfLanes; i++)
    {
        if (i % 2 == 0)
            map.push_back(std::make_unique<Lane>(width));
        else
            map.push_back(std::make_unique<Obstacle>(width));
    }

    player = std::make_unique<Player<int>>(width);
}

Game::Game(const Game& other)
    : numberOfLanes(other.numberOfLanes),
    width(other.width),
    quit(other.quit),
    score(other.score)
{
    player = std::make_unique<Player<int>>(*other.player);
    for (const auto& obj : other.map)
        map.push_back(obj->Clone());
}

void Game::Draw()
{
    system("cls");
    for (int i = 0; i < numberOfLanes; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 && (j == 0 || j == width - 1))
                std::cout << "S";
            else if (i == numberOfLanes - 1 && (j == 0 || j == width - 1))
                std::cout << "F";
            else if (map[i]->CheckPos(j) && i != 0 && i != numberOfLanes - 1)
                std::cout << "#";
            else if (player->getX() == j && player->getY() == i)
                std::cout << "V";
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Score: " << score << std::endl;
}

void Game::Input()
{
    if (_kbhit())
    {
        char current = _getch();
        if (current == 'a') player->moveLeft();
        if (current == 'd') player->moveRight();
        if (current == 'w') player->moveUp();
        if (current == 's') player->moveDown();
        if (current == 'q') quit = true;

        for (auto observer : observers)
            observer->OnPlayerMove(player->GetPosition());
    }
}

void Game::AddObserver(PlayerObserver* observer)
{
    observers.push_back(observer);
}

void Game::Logic()
{
    for (int i = 0; i < numberOfLanes - 1; i++)
        map[i]->Move();

    int playerX = player->getX();
    int playerY = player->getY();

    if (playerY > 0 && playerY < numberOfLanes - 1)
    {
        if (map[playerY]->CheckPos(playerX))
        {
            quit = true;
            gameOver = true;
            system("cls");
            std::cout << "\nGAME OVER!\n";
            std::cout << "Scorul tau final: " << score << "\n";
            std::cout << "Apasa orice tasta pentru a reveni la meniu...\n";
            _getch();
            return;
        }
    }

    if (player->getY() == numberOfLanes - 1)
    {
        score++;
        player->ResetPosition();
    }

}

void Game::Run()
{
    while (!quit)
    {
        Input();
        Draw();
        Logic();
        Sleep(100);
    }

    // daca jucatorul moare
    if (gameOver)
        return;

	// daca jucatorul apasa 'q' pentru a iesi
    system("cls");
    std::cout << "\nYou left the game!\n";
    std::cout << "Scor final: " << score << "\n";
    std::cout << "Apasa orice tasta pentru a reveni la meniu...\n";
    _getch();
}


