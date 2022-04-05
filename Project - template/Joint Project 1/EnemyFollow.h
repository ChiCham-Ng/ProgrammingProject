//Name:Chi Cham Ng
//ID: C00278721


#pragma once

#include <SFML/Graphics.hpp>
#include"Player.h"

class EnemyFollow

{

	sf::Texture textureNorth;
	sf::Texture textureSouth;
	sf::Texture textureEast;
	sf::Texture textureWest;

	
	

public: //new function

	sf::Sprite body;
	int speed;
	int direction;
	int xPos;
	int yPos;

	bool isAlive;

	EnemyFollow(); //default constructor
	void loadContent(); //load the player image file

	void draw();
	void hit();
	void dies();
	void reSpawn();

};