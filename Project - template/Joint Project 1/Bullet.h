//Name:Chi Cham Ng
//ID: C00278721

#pragma once


#include <SFML/Graphics.hpp>

class Bullet

{

	sf::Texture textureNorth;
	sf::Texture textureSouth;
	sf::Texture textureEast;
	sf::Texture textureWest;


public:

	sf::Sprite body;
	int speed;
	int direction;
	bool isfired;


	Bullet();
	void loadContent();


	void draw();
	void hit();
	void fired();
	void move();

};