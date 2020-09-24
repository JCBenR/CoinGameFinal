//
//  projectile.hpp
//  CoinGame
//
//  Created by Jeff Ramey on 9/23/20.
//

#ifndef projectile_hpp
#define projectile_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>

class Projectile{
public:
    sf::CircleShape shape;
    Projectile(){
        shape = sf::CircleShape(4);
        shape.setFillColor(sf::Color::White);
    }
  void draw(sf::RenderWindow &window) { window.draw(shape); }
};


#include <stdio.h>

#endif /* projectile_hpp */
