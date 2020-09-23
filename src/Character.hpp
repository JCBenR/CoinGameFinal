//
//  Character.hpp
//  testSFML
//
//  Created by Justin Siebenhaar on 9/21/20.
//

#ifndef Character_hpp
#define Character_hpp


#include <stdio.h>
#include <SFML/Graphics.hpp>

class Ball {
public:
  sf::CircleShape shape;
  float radius;
  float xMin;
  float xMax;
  float yMin;
  float yMax;

public:
    Ball();
  Ball(float r, sf::Vector2f windowSize) { // the size of the window ie
                                           // 1920x1080
    radius = r;
    shape = sf::CircleShape(radius);
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(radius, radius); // sets the orgin to the center of the
                                     // Circle, I like thinking about it this
                                     // way.

    xMin = radius;
    yMin = radius;
    xMax = windowSize.x - radius;
    yMax = windowSize.y - radius;
  }

  void move(sf::Vector2f displacment) {
    sf::Vector2f position = shape.getPosition() + displacment;
    if (position.x < xMin) {
      position.x = xMin; // stop at edge
    }
    if (position.x > xMax) {
      position.x = xMax; // stop at edge
    }
    if (position.y < yMin) {
      position.y = yMin; // stop at edge
    }
    if (position.y > yMax) {
      position.y = yMax; // stop at edge
    }

    shape.setPosition(position);
  }
  void draw(sf::RenderWindow &window) { window.draw(shape); }
};

#endif /* Character_hpp */

