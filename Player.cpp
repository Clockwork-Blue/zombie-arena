#include "Player.h"

Player::Player() {
	m_Speed = Start_Speed;
	m_Health = Start_Health;
	m_MaxHealth = Start_Health;
	//watch this space
	m_Texture.loadFromFile("graphics/player.png");
	m_Sprite.setTexture(m_Texture);
	//set origin of sprite to center for smooth rotation
	m_Sprite.setOrigin(25, 25);

}

void Player::Spawn()
{

}