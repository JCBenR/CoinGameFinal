//
//  BadCoin.hpp
//  testSFML
//
//  Created by Justin Siebenhaar on 9/22/20.
//

#ifndef BadCoin_hpp
#define BadCoin_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>

class BadCoin {
public:
    float xLoc, yLoc;
    int value;
    
 
//private:
  sf::CircleShape shape;
  float radius;


public:
    BadCoin(){
        radius = 10;
        shape = sf::CircleShape(radius);
        shape.setFillColor(sf::Color::Red);
        shape.setOrigin(radius, radius); // sets the orgin to the center
        shape.setPosition(rand() % 800, rand() % 600); //gives random position
  }

  void draw(sf::RenderWindow &window) { window.draw(shape); }
};


#endif /* Coin_hpp */

