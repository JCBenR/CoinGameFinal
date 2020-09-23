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
    //time
//    a. location in window
//    b. point value
//    c. movement
//    d. countdown
//    e. speed
//    f. is live
//    --shape class
//    --event class
//    --time class
//    --color

#endif /* Coin_hpp */

