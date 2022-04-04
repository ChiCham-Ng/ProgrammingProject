//Name:Chi Cham Ng
//ID: C00278721

// Player class declaration
#pragma once

#include <SFML/Graphics.hpp>

 
class EnemyLeftRight;  // forward reference

class Player
{
	// private data members
	sf::Texture textureNorth;
	sf::Texture textureSouth;
	sf::Texture textureEast;
	sf::Texture textureWest;


public:
	sf::Sprite body;


	int health;
	int speed;
	int score;
	int direction;

	sf::Vector2f location = sf::Vector2f{ 0.0f,0.0f };

	int noOfLives;

public:

	Player(); //default constructor
	void draw();
	void loadContent();


	void shoot();
	void dies();
	void decreaseHealth(int t_health);

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();


	//void reSpawn();

	void increaseScore(int t_newScore);
	//void decreaseScore();

};