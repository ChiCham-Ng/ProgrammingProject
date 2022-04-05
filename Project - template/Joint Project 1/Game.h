//Name:Chi Cham Ng
//ID: C00278721

// Game class declaration
#pragma once

#include "SFML/Graphics.hpp" 
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function

#include "Globals.h"   // include Global header file
#include "Player.h"   // include Player header file
#include"EnemyLeftRight.h"
#include"EnemyFollow.h"
#include"Bullet.h"


class Game
{
	// private data members

	// put your game objects here eg player object and 
	// array of enemy objects etc.

	Player player;//player

	static const int MAX_BULLETS = 2;
	Bullet bulletArray[MAX_BULLETS];//bullet
	
	static const int MAX_ENEMIES = 10;	int noEnemies; //number of enemies alive
	EnemyLeftRight enemyLRArray[MAX_ENEMIES];  //enemy array


	static const int MAX_ENEMIESF = 2;
	EnemyFollow enemyFArray[MAX_ENEMIESF]; 


	bool gameOver;

	sf::RenderWindow window;
	bool exitGame;


public:


	sf::Font m_font;  // font for writing text
	sf::Text m_message;  // player status to write on the screen
	sf::Text m_message2;  // text to write on the screen

public:	  // declaration of member functions	
	Game(); // default constructor
	void	loadContent();
	void	run();
	void	update();
	void	draw();

	void	moveEnemiesLR(); // move the enemy objects within the array
	void  enemiesFollowMove(); //move enemiesF follow the player

	void   collisionDetection(); // when the player and the enemy collide
	void collisionDetectionBullet();// when bullet and the enemy collide

};
