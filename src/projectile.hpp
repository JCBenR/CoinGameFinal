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
    sf::Vector2f currVelocity;
    float maxSpeed;

    Projectile(float radius = 4)
    : currVelocity(0.f,0.f), maxSpeed(5.f)
    {
        shape = sf::CircleShape(radius);
        shape.setFillColor(sf::Color::White);

  }

  void draw(sf::RenderWindow &window) { window.draw(shape); }
};


#include <stdio.h>

#endif /* projectile_hpp */
