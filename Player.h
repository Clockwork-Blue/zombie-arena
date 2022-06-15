#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Player
{
private:
	const float Start_Speed = 200;
	const float Start_Health = 100;
	//where is the player
	Vector2f m_Position;
	//Player Sprite
	Sprite m_Sprite;
	//Player Texture
	Texture m_Texture;
	//interesting thing here
	//what is the screen resolution
	Vector2f m_Resolution;
	//What size is the current arena
	IntRect m_Arena;
	//How big is each tile of the arena
	int m_TileSize;
	// which directions the player is moving in
	bool upPressed;
	bool downPressed;
	bool leftPressed;
	bool rightPressed;
	//Player current health
	int m_Health;
	int m_MaxHealth;
	//when was the player last hit
	Time m_LastHit;
	float m_Speed;
public:
	Player();
	void Spawn(IntRect arena, Vector2f resolution, int tileSize);
	//Call this at the end of every game
	void resetPlayerStats();
	//handle the player getting hit by a zombie
	bool hit(Time timehit);
	//Hol long ago was the player last hit
	Time getLastHitTime();
	//Where is the player
	FloatRect getPosition();
	// where is the center of the player
	Vector2f getCenter();
	//what angle is the player facing
	float getRotation();
	//send a copy of the sprite to the main function
	Sprite getSprite();
	//the players four directional movements
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	//stop the player's four movements
	void stopUp();
	void stopDown();
	void stopLeft();
	void stopRight();
	//call function once every frame
	void update(float elapsedTime, Vector2i mousePosition);
	//give the player a speed boost
	void upgradeSpeed();
	//increase the players max health
	void upgradeHealth();
	// Increase amount of health the player has up to the max
	void increaseHealthLevel(int amount);
	// How much health does the player currently have?
	int getHealth();
};