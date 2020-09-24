#include <SFML/Graphics.hpp>
#include "Character.hpp"
#include "Coin.hpp"
#include "projectile.hpp"
#include "BadCoin.hpp"
#include <iostream>
#include <string>
#include <SFML/audio.hpp>


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
    //load sound files
    sf::SoundBuffer bufferCollide;
    if (!bufferCollide.loadFromFile("../../collision.wav")){
        std::cout << "collision sound didn't load" <<std::endl;
        return 1;
    }
    sf::Sound collision;
    collision.setBuffer(bufferCollide);
    
    sf::SoundBuffer bufferCollect;
    if (!bufferCollect.loadFromFile("../../collect.wav")){
        std::cout << "collision sound didn't load" <<std::endl;
        return 1;
    }
    sf::Sound collect;
    collect.setBuffer(bufferCollect);

    
    int hitCounter = 0;
    int score = 0;
    std::vector <Coin> vecOfCoins;
    std::vector <BadCoin> vecOfBadCoins;
    std::vector <Projectile> proj1;
    Ball character(25,sf::Vector2f(800,600));
    for(int i = 0; i < 1; i++){ //loop + vector to easily scale at a later point
        Coin tempCoin;
        vecOfCoins.push_back(tempCoin);
    }
    //score text
    sf::Text text("SCORE", font, 30);
    sf::Text displayScore(std::to_string(score), font, 50);
    text.setPosition(700, 1);
    displayScore.setPosition(730, 25);
    
    //game over text
    sf::Text gameOver("GAME OVER", font, 60);
    gameOver.setPosition(300, 250);
    sf::Text timer("TIME LEFT", font, 20);
    
    //CLOCK
    sf::Clock clock;
    sf::Time roundTime = sf::seconds(10.0);
    
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        window.draw(displayScore);
        window.draw(gameOver);
        sf::Time elapsed1 = clock.getElapsedTime();
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            //if time runs out or hitCounter goes above 3, character can't move anymore
            if (elapsed1 > roundTime || hitCounter > 3) break;
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
        
        //establish bounding boxes for each element
        sf::FloatRect testBoundingBox = character.shape.getGlobalBounds();
        std::vector <sf::FloatRect> vecOfBounds;
        for(int i = 0; i < vecOfCoins.size(); i++){
            sf::FloatRect tempBound = vecOfCoins[i].shape.getGlobalBounds();
            vecOfBounds.push_back(tempBound);
            if(testBoundingBox.intersects(vecOfBounds[i])){//detects collision, adds to score and removes that Coin
                collect.play();
                vecOfCoins.erase(vecOfCoins.begin()+i);
                score++;
            }
        }
        
        std::vector <sf::FloatRect> vecOfBCBounds;
        for(int i = 0; i < vecOfBadCoins.size(); i++){
            sf::FloatRect tempBound = vecOfBadCoins[i].shape.getGlobalBounds();
            vecOfBCBounds.push_back(tempBound);
            if(testBoundingBox.intersects(vecOfBCBounds[i])){//detects collision, adds to score and removes that Coin
                vecOfBadCoins.erase(vecOfBadCoins.begin()+i);
                score -= 3;
            }
        }
        
        std::vector <sf::FloatRect> proj1Bounds;
        for(int i = 0; i < proj1.size(); i++){
            sf::FloatRect tempBound = proj1[i].shape.getGlobalBounds();
            proj1Bounds.push_back(tempBound);
            if(testBoundingBox.intersects(proj1Bounds[i])){
                collision.play();
                proj1.erase(proj1.begin()+i);
                hitCounter ++;
            }
        }
        
        //Checks when all coins are collected and starts a new round. Loads additional BadCoins and projectiles to increase difficulty of subsequent rounds.
        if(vecOfCoins.size() == 0){ //once all coins are collected, reset timer, spawn next round's coins
            clock.restart();  //
            for(int i = 0; i < 1; i++){ //loop + vector to easily scale at a later point
                Coin tempCoin;
                vecOfCoins.push_back(tempCoin);
            }

            for(int i = 0; i < 2; i++){ //loop +  vector to easily scale at a later point
                Projectile tempProjectile;
                BadCoin tempCoin;
                vecOfBadCoins.push_back(tempCoin); //add more badCoins at end of round
                proj1.push_back(tempProjectile); //add more projectiles at end of round

                for(int i = 0; i < vecOfBadCoins.size(); i++){ //set position of each projectile to coincide with a bad coin
                    proj1[i].shape.setPosition(vecOfBadCoins[i].shape.getPosition());
                }
            }
        }

        // clear the window with black color
        window.clear(sf::Color::Black);
    
        //draw necesarry objects
        character.draw(window);
        for(Coin c : vecOfCoins){
            c.draw(window);
        }
        for(BadCoin c : vecOfBadCoins){
            c.draw(window);
        }
        for(Projectile p : proj1){
            p.draw(window);
        }
        for(int p = 0; p < proj1.size(); p++){
            proj1[p].shape.move(((character.shape.getPosition().x - vecOfBadCoins[p].shape.getPosition().x) * .0001), ((character.shape.getPosition().y - vecOfBadCoins[p].shape.getPosition().y) *.0001)); //finds direction to where character is and moves projectiles in that direction; * .0001 to slow down projectiles to reasonable speed
        }

        //draws the title for score
        window.draw(text);
        //called to update and display score in proper position after each loop.
        sf::Text displayScore(std::to_string(score), font, 50);
        displayScore.setPosition(730, 25);
        window.draw(displayScore);
        
        //CLOCK
        
        //calculate countdown
        sf::Time timeLeft = roundTime - elapsed1;
        
        //cast time to string (necessary so it can be printed on screen)
        std::string gameTime = std::to_string((int)(timeLeft.asSeconds()));
        
        sf::Text gameClock(gameTime, font, 50);
        gameClock.setPosition(400, 10);
        timer.setPosition(370, 1);
        
        //check if time has run out
        if (elapsed1 > roundTime || hitCounter> 3) {
            window.draw(gameOver);

        } else{
            window.draw(timer);
            window.draw(gameClock);
        }
        // end the current frame
        window.display();      
    }

    return 0;
}

