//Name:Chi Cham Ng
//ID: C00278721

#include "EnemyLeftRight.h"
#include"Game.h"
#include<iostream>
//

EnemyLeftRight::EnemyLeftRight()
{
	loadContent();

	xPos = (rand() % 800) + 1;    // random number between 1 and 800
	yPos = (rand() % 350) + 51;   // random number between 50 and 400
	body.setPosition(xPos, yPos);

	speed = (rand() % 5) + 1;  // 5 level of speed

	direction = (rand() % 2) + 1; //random number between 1 and 2

	isAlive = true;

}

void EnemyLeftRight::loadContent()
{
	if (!textureEast.loadFromFile("ASSETS\\IMAGES\\enemyRight.png"))// load picture
	{
		std::cout << "Error- Emeny pic" << std::endl;
	}
	if (!textureWest.loadFromFile("ASSETS\\IMAGES\\enemyLeft.png")) // load picture
	{
		std::cout << "Error" << std::endl;
	}
	body.setTexture(textureEast);
}


void EnemyLeftRight::draw()
{
}

void EnemyLeftRight::hit()
{

}

void EnemyLeftRight::dies()
{
	isAlive = false;
}



void EnemyLeftRight::reSpawn()
{
}



void EnemyLeftRight::move()
{
	sf::Vector2f pos(body.getPosition());  // get the current position

	sf::Vector2f playerPosition;
	if (direction == WEST)   //move to left
	{

		body.setTexture(textureWest);

		if (pos.x <= 0)  //keep the enemies in screen
		{
			direction = EAST;
		}
		pos.x = pos.x - speed;
	}

	else if (direction == EAST)   //move to right
	{

		body.setTexture(textureEast);

		if (pos.x >= SCREEN_WIDTH - 18)  //keep the enemies in screen
		{
			direction = 1;
		}
		pos.x = pos.x + speed;
	}


	body.setPosition(pos);  // set to the new position
}
