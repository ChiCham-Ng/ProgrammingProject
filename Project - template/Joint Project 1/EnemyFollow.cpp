//Name:Chi Cham Ng
//ID: C00278721

#include "EnemyFollow.h"
#include"Game.h"

#include<iostream>



EnemyFollow::EnemyFollow()
{
	loadContent();

	xPos = (rand() % 800) + 1;    // Generates a random number between 1 and 800
	yPos = 50;  
	body.setPosition(xPos, yPos);

	speed = (rand() % 2) + 1;  // 2 level of speed

	direction = 4;

	isAlive = true;

}

void EnemyFollow::loadContent()
{
	if (!textureSouth.loadFromFile("ASSETS\\IMAGES\\enemy1Down.png"))
	{
		std::cout << "Error- Emeny pic" << std::endl;
	}
	body.setTexture(textureSouth);
}

void EnemyFollow::draw()
{
}

void EnemyFollow::hit()
{
}

void EnemyFollow::dies()
{
	isAlive = false;
}

void EnemyFollow::reSpawn()
{
	if (isAlive == false)
	{
		loadContent();

		int xPos = (rand() % 800) + 1;    // Generates a random number between 1 and 800
		int yPos = 50;
		body.setPosition(xPos, yPos);

		speed = (rand() % 3) + 3;  // 3 level of speed

		direction = 4;

		isAlive = true;
	}
}

