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

void Player::Spawn(IntRect arena, Vector2f resolution, int tileSize)
{
	//place the player in the middle of the arena
	m_Position.x = arena.width / 2;
	m_Position.y = arena.height / 2;
	/*copy the arena's details to the player's arena information*/
	m_Arena.width = arena.width;
	m_Arena.left = arena.left;
	m_Arena.top = arena.top;
	m_Arena.height = arena.height;
	m_TileSize = tileSize;

}

void Player::resetPlayerStats() {
	m_Speed = Start_Speed;
	m_Health = Start_Health;
	m_MaxHealth = Start_Health;
}

Time Player::getLastHitTime()
{
	return m_LastHit;
}

bool Player::hit(Time timehit)
{
	if (timehit.asMilliseconds() - m_LastHit.asMilliseconds() > 200)
	{
		m_LastHit = timehit;
		m_Health -= 10;
		return true;
	}
	else 
	{
		return false;
	}
}

FloatRect Player::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

Vector2f Player::getCenter()
{
	return m_Position;
}

float Player::getRotation()
{
	return m_Sprite.getRotation();
}

Sprite Player::getSprite()
{
	return m_Sprite;
}

int Player::getHealth()
{
	return m_Health;
}

void Player::moveLeft() 
{
	bool m_LeftPressed = true;
}

void Player::stopLeft()
{
	bool m_LeftPressed = false;
}

void Player::moveRight()
{
	bool m_RightPressed = true;
}

void Player::stopRight()
{
	bool m_RightPressed = false;
}

void Player::moveUp()
{
	bool m_UpPressed = true;
}

void Player::stopUp()
{
	bool m_UpPressed = false;
}

void Player::moveDown()
{
	bool m_DownPressed = true;
}

void Player::stopDown()
{
	bool m_DownPressed = false;
}

void Player::update(float elapsedTime, Vector2i mousePosition)
{
	if (m_UpPressed)
	{
		m_Position.y -= m_Speed * elapsedTime;
	}
	if (m_DownPressed)
	{
		m_Position.y += m_Speed * elapsedTime;
	}
	if (m_LeftPressed)
	{
		m_Position.x -= m_Speed * elapsedTime;
	}
	if (m_RightPressed)
	{
		m_Position.x += m_Speed * elapsedTime;
	}
	m_Sprite.setPosition(m_Position);
	//keep the player in the arena
	if (m_Position.x > m_Arena.width - m_TileSize)
	{
		m_Position.x = m_Arena.width - m_TileSize;
	}
	if (m_Position.x < m_Arena.left + m_TileSize)
	{
		m_Position.x = m_Arena.left + m_TileSize;
	}

	if (m_Position.y > m_Arena.height - m_TileSize)
	{
		m_Position.y = m_Arena.height - m_TileSize;
	}

	if (m_Position.y < m_Arena.top + m_TileSize)
	{
		m_Position.y = m_Arena.top + m_TileSize;
	}
	float angle = (atan2(mousePosition.y - m_Resolution.y / 2, m_Position.x - m_Resolution.x / 2) * 180) / 3.141;
	m_Sprite.setRotation(angle);
}

void Player::upgradeSpeed()
{
	// up speed by 20%
	m_Speed += (Start_Speed * .2);
}

void Player::upgradeHealth()
{
	// up max health by 20%
	m_MaxHealth += (m_MaxHealth * .2);
}

void Player::increaseHealthLevel(int amount) {
	m_Health += amount;
	if (m_Health > m_MaxHealth)
	{
		m_Health = m_MaxHealth;
	}
}

int Player::getHealth()
{
	return m_Health;
}