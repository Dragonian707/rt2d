/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @brief Description of My Awesome Game.
 *
 * @file main.cpp
 *
 * @mainpage My Awesome Game
 *
 * @section intro Introduction
 *
 * Detailed description of My Awesome Game.
 *
 * There's even a second paragraph.
 */
#include <rt2d/core.h>

#include "managescene.h"

/// @brief main entry point
int main( void )
{
	// Core instance
	Core core;

	static ManageScene* scene = new ManageScene();


	char running = 1;
	while (running)
	{
		core.run(scene->GetActiveScene());

		if (!scene->running) { running = 0; }
	}

	delete scene;
	scene = nullptr;

	return 0;
}
