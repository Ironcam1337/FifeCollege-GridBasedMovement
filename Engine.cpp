#include "stdafx.h"
#include "Engine.h"
#include "GridSprite.h"

using namespace sf;

Engine::Engine()
	: m_Grid(10,10,64,64) // Set your grid size here!
{
	// Get the game screen resolution
	// and creste an SFML window and View
	Vector2i resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	m_Window.create(VideoMode(resolution.x, resolution.y),
		"Grid Based Movement Example",
		Style::Titlebar);

	// Initialise the fullscreen view
	m_MainView.setSize((Vector2f)resolution);

	// Set up the grid contents
	// NOTE: This could be done based on a file
	// similar to how Thomas Was Late levels were loaded!
	m_Grid.SetObject(0, 0, new GridSprite(TextureHolder::GetTexture("")));
}

void Engine::run()
{
	// Timing
	Clock clock;

	while (m_Window.isOpen())
	{
		Time dt = clock.restart();

		// Make a float from the delta time
		float dtAsSeconds = dt.asSeconds();

		// Call each part of the game loop in turn
		input();
		update(dtAsSeconds);
		draw();
	}
}