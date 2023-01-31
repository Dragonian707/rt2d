/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file EndScene.h
 *
 * @brief description of EndScene behavior.
 */

#ifndef ENDSCENE_H
#define ENDSCENE_H

#include <rt2d/scene.h>
#include <rt2d/text.h>
#include "managescene.h"
#include "button.h"

/// @brief The EndScene class is the Scene implementation.
class EndScene : public Scene
{
public:
	/// @brief Constructor
	EndScene();
	/// @brief Destructor
	virtual ~EndScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	Text* endText;

	Button* backToHome;

	void mainMenu();
};

#endif /* SCENE00_H */
