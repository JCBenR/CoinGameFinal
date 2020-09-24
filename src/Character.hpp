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
///Class that creates the user element, controlled via keyboard input
///
///will generate a small green ball that user can control with the objective of getting coins
class Ball {
public:
  sf::CircleShape shape;
  float radius;
  float xMin;
  float xMax;
  float yMin;
  float yMax;
    ///default constructor
  Ball();
    ///constructor
    ///@param r radius for size of the player element.
    ///@param windowSize the size of the window (should be same as the window so player element does not exit window bounds)
  Ball(float r, sf::Vector2f windowSize) { // the size of the window ie
                                           // 1920x1080
    radius = r;
    shape = sf::CircleShape(radius);
    shape.setFillColor(sf::Color::Green);
      ///sets the orgin to the center of the Circle, I like thinking about it this way.
    shape.setOrigin(radius, radius);
      ///gets shape position on screen
      shape.getPosition();
    xMin = radius;
    yMin = radius;
    xMax = windowSize.x - radius;
    yMax = windowSize.y - radius;
  }
///function to move the ball and have it stop at the edge of the screen
    ///@param displacement how far it should move in vector2f (example value (0,-30) moves character up 30 pixels, left/right 0 pixels).
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
      ///sets position to proper placement on screen
    shape.setPosition(position);
  }
  void draw(sf::RenderWindow &window) { window.draw(shape); }
};

#endif /* Character_hpp */

