//Name: Chi Cham Ng
//ID: C00278721
//Date: Restart: 28-Mar-2022 to  

#include "Player.h"   // include Player header file
#include"EnemyLeftRight.h"
#include"Game.h"
#include"Bullet.h"
#include <iostream>


// Player function definitions here

Player::Player()
{

	loadContent();
	body.setPosition(400, 500);

	A_HEALTH = 5;
	health = A_HEALTH;

	direction = 3;
	speed = 3;
	score = 0;


}


void Player::draw()
{

}

void Player::loadContent()
{
	if (!textureSouth.loadFromFile("ASSETS\\IMAGES\\down.png"))
	{
		std::cout << "Error-" << std::endl;
	}
	if (!textureNorth.loadFromFile("ASSETS\\IMAGES\\up.png"))
	{
		std::cout << "Error" << std::endl;
	}
	if (!textureEast.loadFromFile("ASSETS\\IMAGES\\right.png"))
	{
		std::cout << "Error" << std::endl;
	}
	if (!textureWest.loadFromFile("ASSETS\\IMAGES\\left.png"))
	{
		std::cout << "Error" << std::endl;
	}

	if (!textureDies.loadFromFile("ASSETS\\IMAGES\\die.png"))
	{
		std::cout << "Error- player pic" << std::endl;
	}
	body.setTexture(textureNorth);

}


void Player::dies()
{
	if (health == 0)
	{
		body.setTexture(textureDies);
		gameOver = true;
	}
}

void Player::decreaseHealth(int t_health)
{
	if (health > 0)
	{
		health = health - t_health;
	}
	
}

void Player::moveLeft()
{
	sf::Vector2f pos(body.getPosition());

	if (pos.x <= 0)//keep the player in screen
	{
		pos.x = 0;
	}
	else
	{
		pos.x = pos.x - speed;
	}
	body.setPosition(pos);



	direction = 1;
	body.setTexture(textureWest);




}

void Player::moveRight()
{
	sf::Vector2f pos(body.getPosition());

	if (pos.x >= SCREEN_WIDTH - 18)//keep the player in screen
	{
		pos.x = SCREEN_WIDTH - 18;
	}
	else
	{
		pos.x = pos.x + speed;
	}
	body.setPosition(pos);


	direction = 2;
	body.setTexture(textureEast);


}

void Player::moveUp()
{
	sf::Vector2f pos(body.getPosition());

	if (pos.y <= 0)//keep the player in screen
	{
		pos.y = 0;
	}
	else
	{
		pos.y = pos.y - speed;
	}
	body.setPosition(pos);


	direction = 3;
	body.setTexture(textureNorth);


}

void Player::moveDown()
{
	sf::Vector2f pos(body.getPosition());

	if (pos.y >= SCREEN_HEIGHT - 26)//keep the player in screen
	{
		pos.y = SCREEN_HEIGHT - 26;
	}
	else
	{
		pos.y = pos.y + speed;
	}
	body.setPosition(pos);

	direction = 4;
	body.setTexture(textureSouth);
}


void Player::increaseScore(int t_newScore)
{
	score = score + t_newScore;
}

