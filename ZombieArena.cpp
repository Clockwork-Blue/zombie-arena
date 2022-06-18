// zombie.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace sf;


int main()
{
	// the game will always be in one of these states
	enum class states
	{
		PAUSED, LEVELING_UP, GAME_OVER, PLAYING
	};
	// game over
	// get resolution and create sfml window
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	RenderWindow window(VideoMode(resolution.x, resolution.y), "Zombie Arena", Style::Fullscreen);
	// Create a SFML view for the main screen
	View mainview(sf::FloatRect( 0, 0, resolution.x, resolution.y));
	//Clock for timing everything
	Clock clock;
	// how long has the playing state been active
	Time getTimeTotal;
	// where is the mouse relative to the worlds coordinates 
	Vector2f mouseWorldPosition;
	// where is the mouse relative to the screen coordinates
	Vector2i mouseScreenPosition;

	return 0;
}