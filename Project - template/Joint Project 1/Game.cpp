// Name: Chi Cham Ng
// Login: C00278721
// Date: 4-4-2022
// Approximate time taken:  two weeks
//---------------------------------------------------------------------------
// Project description: simple game
// ---------------------------------------------------------------------------
// Known Bugs:
// ?

//////////////////////////////////////////////////////////// 
// include correct library file for release and debug versions
//////////////////////////////////////////////////////////// 

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 



#include "Game.h"   // include Game header file
#include<cmath>


int main()
{
	Game aGame;
	aGame.loadContent();
	aGame.run();

	return 0;
}

Game::Game() : 
	window(sf::VideoMode(static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGHT)), 
		"Project Game", sf::Style::Default)
// Default constructor
{
	
}

void Game::loadContent()
// Load the font file & setup the message string
{
	if (!m_font.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error with font file file";
	}

	// set up the message string 
	m_message.setFont(m_font);  // set the font for the text
	m_message.setCharacterSize(24); // set the text size
	m_message.setFillColor(sf::Color::White); // set the text colour
	m_message.setPosition(10, 10);  // its position on the screen

		// set up the message string 
	m_message2.setFont(m_font);  // set the font for the text
	m_message2.setCharacterSize(20); // set the text size
	m_message2.setFillColor(sf::Color::White); // set the text colour
	m_message2.setPosition(670, 570);  // its position on the screen

}


void Game::run()
// This function contains the main game loop which controls the game. 
{

	srand((int)time(nullptr)); // set the seed once

	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	// the clock object keeps the time.
	sf::Clock clock;


	clock.restart();

	while (window.isOpen())
	{
		// check if the close window button is clicked on
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//get the time since last update and restart the clock
		timeSinceLastUpdate += clock.restart();

		//update every 60th of a second
		//only when the time since last update is greater than 1/60 update the world.
		if (timeSinceLastUpdate > timePerFrame)
		{
			update();
			draw();

			// reset the timeSinceLastUpdate to 0 
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}  // end while loop

}

void Game::update()
// This function takes the keyboard input and updates the game world
{
	// get keyboard input
	if (player.health > 0) // if player is alive
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			player.moveLeft();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			player.moveRight();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			player.moveUp();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			player.moveDown();
		}

		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			bullet.setPosition(body.getPosition());

			Game::window.draw(bullet);
			player.shoot();
		}*/

	}
	


	// update any game variables here ...

	moveEnemiesLR(); //move enemies Left Right
	collisionDetection(); // If the player and the enemy collide
	enemiesFollowMove(); //move enemies Follow player
	
	if (player.health > 0) // if player is alive, enamyFollow respawn
	{
		for (int index = 0; index < MAX_ENEMIESF; index++) //reSpawn enamyFollow when dies
		{
			enemyFArray[index].reSpawn();
		}
	}


	player.dies();  //if player's health = 0

}









void Game::draw()
// This function draws the game world
{
	// Clear the screen and draw your game sprites

	window.clear();
	
	m_message.setString("Health: " + std::to_string(player.health) + "    || Score: " + std::to_string(player.score));
	m_message2.setString("press A to shoot ");

	window.draw(m_message);  // write message to the screen
	window.draw(m_message2);

	window.draw(player.body);

	// draw the enemy Left Right objects 
	for (int index = 0; index < MAX_ENEMIES; index++) 
	{
		if (enemyLRArray[index].isAlive == true)
		{
			window.draw(enemyLRArray[index].body);
		}
	}

	// draw the enemy objects which follow player

	for (int index = 0; index < MAX_ENEMIESF; index++) 
	{
		if (enemyFArray[index].isAlive == true)
		{
			window.draw(enemyFArray[index].body);
		}
	}
	


	window.display();

}

void Game::moveEnemiesLR()
{
	for (int index = 0; index < MAX_ENEMIES; index++)
	{
		enemyLRArray[index].move();  // move the enemy objects in the direction they are facing if they are alive
	}
}

void Game::collisionDetection()
{
	sf::FloatRect playerRec;
	sf::FloatRect enemyRec;

	bool collision = false;

	playerRec = player.body.getGlobalBounds();
	
	for (int index = 0; index < MAX_ENEMIES; index++)
	{
		if (enemyLRArray[index].isAlive == true) //if enemyLeftRight is Alive
		{
			enemyRec = enemyLRArray[index].body.getGlobalBounds();

			if (playerRec.intersects(enemyRec))
			{
				player.decreaseHealth(1);
				collision = true;

				player.increaseScore(100);  //increaseScore

				enemyLRArray[index].isAlive = false;
			}
		}
	}

	for (int index = 0; index < MAX_ENEMIESF; index++)
	{
		if (enemyFArray[index].isAlive == true) //if enemyLeftRight is Alive
		{
			enemyRec = enemyFArray[index].body.getGlobalBounds();

			if (playerRec.intersects(enemyRec))
			{
				player.decreaseHealth(1);
				collision = true;

				player.increaseScore(100);  //increaseScore

				enemyFArray[index].isAlive = false;
			}
		}
	}


}

void Game::enemiesFollowMove()
{
	sf::Vector2f playerPosition;
	sf::Vector2f enemyFPosition;

	playerPosition = player.body.getPosition(); //get player position

	
	for (int index = 0; index < MAX_ENEMIESF; index++)
	{
		enemyFPosition = enemyFArray[index].body.getPosition(); //get enemy position

		float angle = atan2(playerPosition.y - enemyFPosition.y, playerPosition.x - enemyFPosition.x);

		enemyFPosition.y = enemyFPosition.y  + sin(angle) * enemyFArray[index].speed;
		enemyFPosition.x = enemyFPosition.x + cos(angle) * enemyFArray[index].speed;

		enemyFArray[index].body.setPosition(enemyFPosition);
	}

	}

