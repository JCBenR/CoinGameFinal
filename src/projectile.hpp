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
///projectile that shoots from bad coin and chases after the user. each 'hit' of these projectiles degrades lives by 1.
class Projectile{
public:
    sf::CircleShape shape;
    ///default constructor
    ///@param shape define shape as cirlce of size 4.
    ///@param shape.setFillColor to set color of projectile to white
    Projectile(){
        shape = sf::CircleShape(4);
        shape.setFillColor(sf::Color::White);
    }
    ///render the projectile to the screen
  void draw(sf::RenderWindow &window) { window.draw(shape); }
};


#include <stdio.h>

#endif /* projectile_hpp */
