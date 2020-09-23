#include <SFML/Graphics.hpp>
#include "Character.hpp"
#include "Game.hpp"
#include "Coin.hpp"
#include <iostream>

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
    sf::Font font;

//    if (!font.loadFromFile("ArialNarrow.ttf"))
//    {
//        std::cout<<"font not loaded"<<std::endl;
//        return 1;
//    }

//    sf::CircleShape shape(50.f);
    //sf::CircleShape shape(25.f);
    Ball character(25,sf::Vector2f(800,600));
    std::vector <Coin> vecOfCoins;
    for(int i = 0; i < 10; i++){
        Coin tempCoin;
        vecOfCoins.push_back(tempCoin);
    }

    
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
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            
            //KEYBOARD MOVEMENTS
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::W){
                    character.move(sf::Vector2f(0,-30));
                }
                if(event.key.code == sf::Keyboard::S){
                    character.move(sf::Vector2f(0,30));
                }
                if(event.key.code == sf::Keyboard::A){
                    character.move(sf::Vector2f(-30,0));
                }
                if(event.key.code == sf::Keyboard::D){
                    character.move(sf::Vector2f(30,0));
                }
            }
        }
        sf::FloatRect testBoundingBox = character.shape.getGlobalBounds();
        sf::FloatRect coin1BoundingBox = vecOfCoins[0].shape.getGlobalBounds();
        std::vector <sf::FloatRect> vecOfBounds;
        for(int i = 0; i < vecOfCoins.size(); i++){
            sf::FloatRect tempBound = vecOfCoins[i].shape.getGlobalBounds();
            vecOfBounds.push_back(tempBound);
            if(testBoundingBox.intersects(vecOfBounds[i])){
                std::cout << "Collision!" << i << std::endl;
                vecOfCoins.erase(vecOfCoins.begin()+i);
            }
        }
    
//    if(testBoundingBox.intersects(coin1BoundingBox)){
//        std::cout << "Collision!" << std::endl;
//    }

        
        // clear the window with black color
        window.clear(sf::Color::Black);
        
        character.draw(window);
        for(Coin c : vecOfCoins){
            c.draw(window);
        }
	// end the current frame
        window.display();
      
    }

    return 0;
}

