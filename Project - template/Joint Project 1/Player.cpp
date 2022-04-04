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
	body.setPosition(400, 450);

	health = 3;
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
		std::cout << "Error- player pic" << std::endl;
	}
	body.setTexture(textureSouth);

}

void Player::shoot()
{
	Bullet bullet;
	bullet.loadContent();
	

	bullet.isfired = true;

	bullet.direction = direction; //bullet direction = player's direction

	sf::Vector2f bulletPos = bullet.body.getPosition();
	sf::Vector2f playerPos = body.getPosition();

	bulletPos.x = playerPos.x + 9; //top middle of player
	bulletPos.y = playerPos.y ;

	bullet.body.setPosition(bulletPos);

	bullet.draw();
	bullet.move();


}

void Player::dies()
{
	if (health == 0)
	{
		if (!textureSouth.loadFromFile("ASSETS\\IMAGES\\die.png"))
		{
			std::cout << "Error- player pic" << std::endl;
		}
		body.setTexture(textureSouth);
	}
}

void Player::decreaseHealth(int t_health)
{
	health = health - t_health;
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

	if (!textureWest.loadFromFile("ASSETS\\IMAGES\\left.png"))
	{
		std::cout << "Error" << std::endl;
	}
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

	if (!textureEast.loadFromFile("ASSETS\\IMAGES\\right.png"))
	{
		std::cout << "Error" << std::endl;
	}
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

	if (!textureNorth.loadFromFile("ASSETS\\IMAGES\\up.png"))
	{
		std::cout << "Error" << std::endl;
	}
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

	if (!textureSouth.loadFromFile("ASSETS\\IMAGES\\down.png"))
	{
		std::cout << "Error" << std::endl;
	}
	body.setTexture(textureSouth);

}


void Player::increaseScore(int t_newScore)
{
	score = score + t_newScore;
}

//bool Player::collisionDection(EnemyLeftRight aEnemyLR[], const int MAX_ENEMIES)
//{
//	bool collide = false;
//
//	sf::Vector2f pos(body.getPosition()); //get the player position
//	sf::Vector2f sizeVec(18, 24);
//
//	for (int index = 0; index < MAX_ENEMIES; index++)
//	{
//		sf::Vector2f enemyPos(aEnemyLR[index].body.getPosition()); //get the enemyLR position
//
//		if ((enemyPos.x >= pos.x) && (enemyPos.x + 18 <= pos.x + 18) &&
//			(enemyPos.y >= pos.y) && (enemyPos.y + 24 <= pos.y + 24)) //picture size = 18*24
//		{
//			collide = true;
//		}
//	}
//
//	return collide;
//}
