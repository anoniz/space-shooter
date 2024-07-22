#include "../includes/Game.h"

Game::Game() {
    // Initialize variables and window
    this->initVariables();
    this->initWindow();
    this->initEnemies();
}

Game::~Game() {
   delete this->window;
}

void Game::initVariables() {
    this->window = nullptr;
}

void Game::initWindow() {

    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->window = new sf::RenderWindow(this->videoMode, "Game 1", sf::Style::Close | sf::Style::Titlebar);
}

const bool Game::running() const {
    return this->window->isOpen();
}

void Game::pollEvents() {

    // the event loop
    while(this->window->pollEvent(this->event)) {
        switch(this->event.type) {
            case sf::Event::Closed :
            this->window->close();
            break;

            case sf::Event::KeyPressed :
            if(this->event.key.code == sf::Keyboard::Escape) {
                this->window->close();
                break;
            }
        }
    }
}

void Game::update() {
    // Update game logic here
    this->pollEvents();

    std::cout << "Mouse pos: " 
    << sf::Mouse::getPosition(*this->window).x 
    << "," << sf::Mouse::getPosition(*this->window).y << "\n";

}

void Game::render() {
    // clear the screen
    this->window->clear(sf::Color::White);

    // Draw Game Objects here
    this->window->draw(this->enemy);

    // Display the window
    this->window->display();
}

void Game::initEnemies() {
    // Initialize enemies here
    this->enemy.setPosition(sf::Vector2(10.f, 10.f));
    this->enemy.setSize(sf::Vector2(100.f, 100.f));
    this->enemy.setScale(sf::Vector2(0.5f, 0.5f));
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineColor(sf::Color::Green);
    this->enemy.setOutlineThickness(5.f);
}