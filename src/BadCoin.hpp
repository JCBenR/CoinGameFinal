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
///bad coins are what the player wants to avoid. they do not move but fire projectiles that can kill the user (take lives). coins, if touched, will decrement score by 3.
class BadCoin {
public:
  sf::CircleShape shape;
  float radius;
    ///default constructor
    ///@param radius size of the coin (same size and good coins).
    BadCoin(){
        radius = 10;
        shape = sf::CircleShape(radius);
        shape.setFillColor(sf::Color::Red);
        shape.setOrigin(radius, radius); // sets the orgin to the center
        shape.setPosition(rand() % 800, rand() % 600); //gives random position
    }
///render bad coin to the screen
  void draw(sf::RenderWindow &window) { window.draw(shape); }
};


#endif /* BadCoin_hpp */

