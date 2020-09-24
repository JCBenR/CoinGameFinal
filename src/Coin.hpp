//
//  Coin.hpp
//  testSFML
//
//  Created by Justin Siebenhaar on 9/22/20.
//

#ifndef Coin_hpp
#define Coin_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>

class Coin {
public:
    float xLoc, yLoc;
    int value;

    
 
//private:
  sf::CircleShape shape;
  float radius;


public:
    Coin(){
        radius = 10;
        shape = sf::CircleShape(radius);
        shape.setFillColor(sf::Color::Yellow);
        shape.setOrigin(radius, radius); // sets the orgin to the center
        shape.setPosition(rand() % 800, rand() % 600); //gives random position
  }

  void draw(sf::RenderWindow &window) { window.draw(shape); }
};


#endif /* Coin_hpp */

