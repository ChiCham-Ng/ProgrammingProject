#include "Bullet.h"
#include"Game.h"
#include<iostream>


Bullet::Bullet()
{
	speed = 6;
	isfired = false;

	loadContent();
}

void Bullet::loadContent()
{
	if (!textureSouth.loadFromFile("ASSETS\\IMAGES\\arrowDown.png"))
	{
		std::cout << "Error- Arrow pic" << std::endl;
	}
	if (!textureNorth.loadFromFile("ASSETS\\IMAGES\\arrowUp.png"))  // load picture
	{
		std::cout << "Error" << std::endl;
	}
	if (!textureEast.loadFromFile("ASSETS\\IMAGES\\arrowLeft.png"))  // load picture
	{
		std::cout << "Error" << std::endl;
	}
	if (!textureWest.loadFromFile("ASSETS\\IMAGES\\arrowRight.png"))  // load picture
	{
		std::cout << "Error" << std::endl;
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

	if (direction == WEST)
	{
		pos.x = pos.x - speed;
	}

	else if (direction == EAST)
	{
		pos.x = pos.x + speed;
	}

	else if (direction == NORTH)
	{
		pos.y = pos.y - speed;
	}

	else
	{
		pos.y = pos.y + speed;
	}

	body.setPosition(pos);
}


void Bullet::shoot(Player t_aPlayer)
{


	isfired = true;

	direction = t_aPlayer.direction; //bullet direction = player's direction
	if (direction == 4)
	{
		body.setTexture(textureSouth);
	}
	else if (direction == 3)
	{

		body.setTexture(textureNorth);
	}
	else if (direction == 2)
	{

		body.setTexture(textureEast);
	}
	else
	{

		body.setTexture(textureWest);
	}


	sf::Vector2f bulletPos = body.getPosition();
	sf::Vector2f playerPos = t_aPlayer.body.getPosition();

	bulletPos.x = playerPos.x + 9; //top middle of player
	bulletPos.y = playerPos.y;

	body.setPosition(bulletPos);

}
