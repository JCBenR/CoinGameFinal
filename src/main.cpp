#include <SFML/Graphics.hpp>
#include "Character.hpp"
#include <iostream>
#include <string>

/*
 1. character object
    a. location in window
    b. shape and color
    c. 
 2. goal objects
    a. location in window
    b. point value
    c. movement
    d. countdown
    e. speed
    f. is live
    --shape class
    --event class
    --time class
    --color
 3. window
    a. static size (window class)
    b. resizing window
 4. countdown clock
    a. start time
    b. countdown
 5. score counter
    a. total score
    b. add points method
    c. high score
    d. running total
 6. vector of objects
    a. amount of objects
    b. randomization
    c. generate objects

 */

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    // Declare a new font
    sf::Font font;
    // Load it from a file
    if (!font.loadFromFile("../../ArialNarrow.ttf"))
    {
        std::cout<<"font didn't load"<<std::endl;
        return 1;
    }
    
    int score = 0;
    sf::Text text("SCORE", font, 30);
    sf::Text displayScore(std::to_string(score), font, 50);
    text.setPosition(700, 1);
    displayScore.setPosition(730, 25);
    Ball shape(15,sf::Vector2f(800,600));
    
//    // set the shape color to green
//    shape.setFillColor(sf::Color(100, 250, 50));
//    shape.setOutlineThickness(10.f);
//    shape.setOutlineColor(sf::Color(250, 150, 100));
    
    
    //CLOCK
    sf::Clock clock;
    
    float dx=0, dy=0;
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        window.draw(displayScore);
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            
            //KEYBOARD MOVEMENTS
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::W){
                    shape.move(sf::Vector2f(0,-30));
                }
                if(event.key.code == sf::Keyboard::S){
                    shape.move(sf::Vector2f(0,30));
                }
                if(event.key.code == sf::Keyboard::A){
                    shape.move(sf::Vector2f(-30,0));
                }
                if(event.key.code == sf::Keyboard::D){
                    shape.move(sf::Vector2f(30,0));
                    score++;
                    std::cout<<score<<std::endl;
                }
            }
        }
        
        // clear the window with black color
        window.clear(sf::Color::Black);
        //draws the title for score
        window.draw(text);
        //called to update and display score in proper position after each loop.
        sf::Text displayScore(std::to_string(score), font, 50);
        displayScore.setPosition(730, 25);
        window.draw(displayScore);
        
        shape.draw(window);

	// end the current frame
        window.display();
      
    }

    return 0;
}

