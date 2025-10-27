#pragma once
#include "Player.h"
#include "Lane.h"
#include "Obstacle.h"
#include "PlayerObserver.h"
#include "GameException.h"
#include <vector>
#include <windows.h>
#include <conio.h>
#include <iostream>

class Game
{
private:
    int numberOfLanes;
    int width;
    bool quit;
    std::unique_ptr<Player<int>> player;
    int score;
    std::vector<std::unique_ptr<GameObj>> map;
    std::vector<PlayerObserver*> observers;
    bool gameOver; // jucatorul moare => true, iese voluntar (q) => false


public:
    static int highScore;
    static int totalGames;

    explicit Game(int w = 20, int h = 10);
    Game(const Game& other);
    ~Game() = default;

    void Draw();
    void Input();
    void AddObserver(PlayerObserver* observer);
    void Logic();
    void Run();

    static int GetHighScore();
    static int GetTotalGamesPlayed();
};
