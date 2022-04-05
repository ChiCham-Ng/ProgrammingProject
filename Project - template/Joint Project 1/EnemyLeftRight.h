//Name:Chi Cham Ng
//ID: C00278721

#pragma once

#include <SFML/Graphics.hpp>

class EnemyLeftRight

{
	sf::Texture textureEast;
	sf::Texture textureWest;

	int speed;
	int direction;



public: //new function

	sf::Sprite body;
	int xPos; //set Position
	int yPos; //set Position
	bool isAlive;
	

	EnemyLeftRight(); //default constructor
	void loadContent(); //load the enmeies image file


	void draw();
	void hit();
	void dies();
	void reSpawn();
	void move();


};