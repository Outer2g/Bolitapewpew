#include "MyGame.hpp"

MyGame::MyGame(int scrwidth, int scrheight, std::string title, int style)
    : Game(scrwidth,scrheight,title,style) {

    Pelota aux(this,10,100);
    balls = std::vector<Pelota> (1);
    balls[0] = aux;
    timer=0.0;
    time_to_next_ball=0.4;
}

MyGame::~MyGame() {}

void MyGame::update(float deltaTime){
    for (unsigned i = 0; i < balls.size(); ++i) balls[i].update(deltaTime);
}

void MyGame::draw(){
    for (unsigned i = 0; i < balls.size(); ++i) balls[i].draw();
}

void MyGame::processEvents(float deltaTime){
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape) window.close();
            if (event.key.code == sf::Keyboard::Space and timer>=time_to_next_ball){
                timer=0.0;
                Pelota nBall(this,100,100);
                balls.push_back(nBall);
            }
            break;
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button ==sf::Mouse::Left){
                for (unsigned i = 0; i < balls.size(); ++i){
                    balls[i].boost(500.0,event.mouseButton.x,event.mouseButton.y);
                }
            }
            break;
            // Add more events to handle them
        default:
            break;
        }
    }
    timer+=deltaTime;

}

sf::RenderWindow *MyGame::getWindow() {
    return &window;
}
