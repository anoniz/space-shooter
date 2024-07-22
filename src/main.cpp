#include "Game.cpp"

int main () {

  // create new game object
  Game game;

  while(game.running()) {
    // update game state
    game.update();

    
    // render game
    game.render();
  }   

    
}