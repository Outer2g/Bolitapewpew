#include "Pelota.hpp"
#include "MyGame.hpp"

Pelota::Pelota(){
}

Pelota::Pelota (MyGame* game,int radio,float velo) {
    g = game;
    ball = sf::CircleShape(radio);
    speed.x=velo;
    speed.y=0;
    ball.setOrigin(sf::Vector2f(radio, radio));
    ball.setPosition(sf::Vector2f(g->getWindow()->getSize().x/2, g->getWindow()->getSize().y/2));
    boundRect= ball.getGlobalBounds();
}

void Pelota::update(float deltaTime) {
    speed.y += gravity*deltaTime;
    sf::Vector2f movimiento = ball.getPosition();
    movimiento.x += speed.x*deltaTime;
    movimiento.y += speed.y*deltaTime;
    ball.setPosition(movimiento);
    //Colision con ground
    float ground = g->getWindow()->getSize().y;
    if( (movimiento.y + ball.getRadius()) > ground){
        speed.y *= -1;
    }
    //colision con left border - rightBorder
    float leftBorder = g->getWindow()->getSize().x;
    if (movimiento.x+ball.getRadius()>leftBorder or movimiento.x-ball.getRadius()<0.0) speed.x*=-1;
}

void Pelota::draw() {
    g->getWindow()->draw(ball);

}

void Pelota::boost(float Boost,int x,int y){
    boundRect=ball.getGlobalBounds();
    bool inX= (boundRect.left< x and boundRect.left+boundRect.width > x);
    bool inY= (boundRect.top<y and boundRect.top+boundRect.height> y);
    if (inX and inY){
        speed.y-=Boost;
    }
    else if (ball.getPosition().y<0) speed.y=0.0;

}
