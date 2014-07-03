#ifndef MYGAME_H
#define MYGAME_H
#include "Game.hpp"
#include "Pelota.hpp"

class MyGame : public Game {
public:
    MyGame(int scrwidth, int scrheight, std::string title, int style);
    ~MyGame();
    void update(float deltaTime);
    void draw();
    void processEvents(float deltaTime);
    sf::RenderWindow* getWindow();
private:
    std::vector<Pelota> balls;
    float timer;
    float time_to_next_ball;
};

#endif // MYGAME_H
