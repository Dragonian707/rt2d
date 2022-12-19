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
	/*
	// Scene01
	Grid* myscene = new Grid(); // create Scene on the heap
	while(myscene->isRunning()) { // check status of Scene every frame
		core.run(myscene); // update and render the current scene
		//core.showFrameRate(5); // show framerate in output every n seconds
	}
	//core.cleanup(); // cleanup ResourceManager (Textures + Meshes, but not Shaders)
	delete myscene; // delete Scene and everything in it from the heap to make space for next Scene
	*/

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
