#ifndef PELOTA_HPP
#define PELOTA_HPP
#include "utils.hpp"

class MyGame;
class Pelota
{
private:
    MyGame* g;
    sf::CircleShape ball;
    sf::Vector2f speed;
    sf::FloatRect boundRect;
public:
    Pelota();
    Pelota(MyGame* game,int radio,float velo);
    void update(float deltaTime);
    void draw();
    void boost(float Boost,int x, int y);
};

#endif // PELOTA_HPP
