/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file startscene.h
 *
 * @brief description of StartScene behavior.
 */

#ifndef STARTSCENE_H
#define STARTSCENE_H

#include <rt2d/scene.h>
#include <rt2d/text.h>
#include "managescene.h"
#include "button.h"

/// @brief The MyScene class is the Scene implementation.
class StartScene : public Scene
{
public:
	/// @brief Constructor
	StartScene();
	/// @brief Destructor
	virtual ~StartScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	Button* startbutton;
	Button* optionbutton;
	Button* quitbutton;

	void SetScene();
	void OpenOptions(); 
};

#endif /* SCENE00_H */
