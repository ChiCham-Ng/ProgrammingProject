#include "Bullet.h"
#include"Game.h"
#include<iostream>


Bullet::Bullet()
{
	speed = 6;
	isfired = true;
}

void Bullet::loadContent()
{
	if (!textureSouth.loadFromFile("ASSETS\\IMAGES\\arrowDown.png"))
	{
		std::cout << "Error- Arrow pic" << std::endl;
	}
	body.setTexture(textureSouth);
}

void Bullet::draw()
{
}

void Bullet::hit()
{
	isfired = false;
}

void Bullet::fired()
{
	isfired = true;
}

void Bullet::move()
{
	
	sf::Vector2f pos(body.getPosition());

	if (direction == 1)
	{
		if (!textureWest.loadFromFile("ASSETS\\IMAGES\\arrowRight.png"))  // load picture
		{
			std::cout << "Error" << std::endl;
		}
		body.setTexture(textureWest);

		pos.x = pos.x - speed;
	}
	if (direction == 2)
	{
		if (!textureEast.loadFromFile("ASSETS\\IMAGES\\arrowLeft.png"))  // load picture
		{
			std::cout << "Error" << std::endl;
		}
		body.setTexture(textureEast);

		pos.x = pos.x + speed;
	}
	if (direction == 3)
	{
		if (!textureNorth.loadFromFile("ASSETS\\IMAGES\\arrowUp.png"))  // load picture
		{
			std::cout << "Error" << std::endl;
		}
		body.setTexture(textureNorth);

		pos.x = pos.y - speed;
	}
	if (direction == 4)
	{
		if (!textureSouth.loadFromFile("ASSETS\\IMAGES\\arrowDown.png"))  // load picture
		{
			std::cout << "Error" << std::endl;
		}
		body.setTexture(textureSouth);
		
		pos.x = pos.y + speed;
	}
}
