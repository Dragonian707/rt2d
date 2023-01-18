/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file GameScene.h
 *
 * @brief description of GameScene behavior.
 */

#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <rt2d/scene.h>
#include "managescene.h"
#include "grid.h"

/// @brief The MyScene class is the Scene implementation.
class GameScene : public Scene
{
public:
	/// @brief Constructor
	GameScene();
	/// @brief Destructor
	virtual ~GameScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	Grid* grid;
	Timer t;
	Text* HUD;
	int clicksleft;

	void ResetGrid();
	void UpdateText();
};

#endif /* SCENE00_H */
