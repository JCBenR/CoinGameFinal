#include <SFML/Graphics.hpp>
#include "Character.hpp"
#include "Coin.hpp"
#include "BadCoin.hpp"
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

void fillVectorBCoins(std::vector <BadCoin> vec){
    for(int i = 0; i < 10; i++){
    BadCoin tempCoin;
    vec.push_back(tempCoin);
    }
}

void fillVectorCoins(std::vector <Coin> vec){
    for(int i = 0; i < 5; i++){
    Coin tempCoin;
    vec.push_back(tempCoin);
    }
}


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
    
Ball character(25,sf::Vector2f(800,600));
    std::vector <Coin> vecOfCoins;
    for(int i = 0; i < 1; i++){
        Coin tempCoin;
        vecOfCoins.push_back(tempCoin);
    }
    //fillVectorCoins(vecOfCoins);
    std::vector <BadCoin> vecOfBadCoins;

    
    int score = 0;
    sf::Text text("SCORE", font, 30);
    sf::Text displayScore(std::to_string(score), font, 50);
    text.setPosition(700, 1);
    displayScore.setPosition(730, 25);
    
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
        
        //Round 1 collision
        sf::FloatRect testBoundingBox = character.shape.getGlobalBounds();
        std::vector <sf::FloatRect> vecOfBounds;
        for(int i = 0; i < vecOfCoins.size(); i++){
            sf::FloatRect tempBound = vecOfCoins[i].shape.getGlobalBounds();
            vecOfBounds.push_back(tempBound);
            if(testBoundingBox.intersects(vecOfBounds[i])){//detects collision, adds to score and removes that Coin
                std::cout << "Collision!" << i << std::endl;
                vecOfCoins.erase(vecOfCoins.begin()+i);
                score++;
                
            }
        }
        std::vector <sf::FloatRect> vecOfBCBounds;
        for(int i = 0; i < vecOfBadCoins.size(); i++){
            sf::FloatRect tempBound = vecOfBadCoins[i].shape.getGlobalBounds();
            vecOfBCBounds.push_back(tempBound);
            if(testBoundingBox.intersects(vecOfBCBounds[i])){//detects collision, adds to score and removes that Coin
                std::cout << "Collision!" << i << std::endl;
                vecOfBadCoins.erase(vecOfBadCoins.begin()+i);
                score--;
                
            }
        }
    
        if(vecOfCoins.size() == 0){ //once all coins are collected, reset timer, spawn next round's coins
            //reset timer
            std::cout << "Spawn new vector" << std::endl;
            for(int i = 0; i < 1; i++){
                Coin tempCoin;
                vecOfCoins.push_back(tempCoin);
            }
            for(int i = 0; i < 2; i++){
                BadCoin tempCoin;
                vecOfBadCoins.push_back(tempCoin);
            }
        }
        

        
        // clear the window with black color
        window.clear(sf::Color::Black);
        
        character.draw(window);
        for(Coin c : vecOfCoins){
            c.draw(window);
        }
        
        for(BadCoin c : vecOfBadCoins){
            c.draw(window);
        }


        //draws the title for score
        window.draw(text);
        //called to update and display score in proper position after each loop.
        sf::Text displayScore(std::to_string(score), font, 50);
        displayScore.setPosition(730, 25);
        window.draw(displayScore);
        //redraw the ball shape

	// end the current frame
        window.display();
      
    }

    return 0;
}

