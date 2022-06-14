#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Player
{
private:
	const float m_StartSpeed = 200;
	const float m_StartHealth = 100;
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
public:
};