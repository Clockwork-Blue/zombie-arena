#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Zombie
{
private:
	//all type zombie speed
	const float BLOATER_SPEED = 40;
	const float CHASER_SPEED = 80;
	const float CRAWLER_SPEED = 20;
	// all type Zombie Hp
	const float BLOATER_HEALTH = 5;
	const float CHASER_HEALTH = 1;
	const float CRAWLER_HEALTH = 3;
	//Zombie speed variance
	const int MAX_VARIANCE = 30;
	const int OFFSET = 101 - MAX_VARIANCE;
	//Zombie Position
	Vector2f m_Position;
	//Zombie Sprite
	Sprite m_Sprite;
	//this zombie hp
	float m_Health;
	//this zombie speed
	float m_Speed;
	//is this zombie alive
	bool m_Alive;
	//Public stuff, write when sober
};