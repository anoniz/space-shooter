#include<iostream>

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>


#ifndef GAME_H
#define GAME_H

class Game {
    private:
    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    sf::Event event;

    // enemy
    sf::RectangleShape enemy;

    // private methods
    void initVariables();
    void initWindow();

    public:
    // Constructors and Destructors
    Game();
    virtual ~Game();

    // Accessors
    const bool running() const;

    // Core Methods
    void pollEvents();
    void update();
    void render();

    // enemy methods
    void initEnemies();
};

#endif