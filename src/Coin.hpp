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
///creates coins of positive value. these are the objectives the user wants to collect.
class Coin {
public:
    ///draws circle shape from SFML library
  sf::CircleShape shape;
  float radius;
    ///default constructor
    ///@param radius to set size of coin
    ///@param shape to set shape as circle
    Coin(){
        radius = 10;
        shape = sf::CircleShape(radius);
        shape.setFillColor(sf::Color::Yellow);
        shape.setOrigin(radius, radius); // sets the orgin to the center
        shape.setPosition(rand() % 800, rand() % 600); //gives random position
    }
///render the coin on the screen
  void draw(sf::RenderWindow &window){
      window.draw(shape);
  }
};


#endif /* Coin_hpp */

