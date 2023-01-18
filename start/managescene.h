/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file ManageScene.h
 *
 * @brief description of ManageScene behavior.
 */

#ifndef MANAGESCENE_H
#define MANAGESCENE_H

#include <rt2d/scene.h>
#include <rt2d/text.h>

/// @brief The MyScene class is the Scene implementation.
class ManageScene
{
public:
	/// @brief Constructor
	ManageScene();
	/// @brief Destructor
	virtual ~ManageScene();


	void CheckScene();
	Scene* GetActiveScene();

	static int activescene;
	static int Xsize;
	static int Ysize;
	static int Clicks;
	static int Time;
	static int Colors;
	bool running = true;


private:
	Scene* currentScene;
	enum Active {startscene, gamescene, endscene, optionscene};
	Active active;
};

#endif /* SCENE00_H */
