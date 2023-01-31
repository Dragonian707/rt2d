/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file OptionScene.h
 *
 * @brief description of OptionScene behavior.
 */

#ifndef OPTIONSCENE_H
#define OPTIONSCENE_H

#include <rt2d/scene.h>
#include <rt2d/text.h>
#include "managescene.h"
#include "button.h"
#include "scrollarea.h"

/// @brief The MyScene class is the Scene implementation.
class OptionScene : public Scene
{
public:
	/// @brief Constructor
	OptionScene(int prevScene);
	/// @brief Destructor
	virtual ~OptionScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	Text* optionText;

	Button* startbutton;
	Button* optionbutton;
	Button* quitbutton;
	Button* exitoptions;
	Button* enterX;
	Button* enterY;
	Button* enterClick;
	Button* enterTime;
	Button* enterColors;

	ScrollArea* Xscroll;
	ScrollArea* Yscroll;
	ScrollArea* Clickscroll;
	ScrollArea* Timescroll;
	ScrollArea* Colorscroll;

	std::vector<Button*> Xoptions;
	std::vector<Button*> Yoptions;
	std::vector<Button*> ClickOptions;
	std::vector<Button*> TimeOptions;
	std::vector<Button*> ColorOptions;
	std::vector<Button*> Buttons;

	int _gridx;
	int _gridy;
	int _maxClicks;
	int _timeToBeat;
	int _colorAmount;
	int previous;

	void CloseOptions();
	void SetGridWidth(int width);
	void SetTime(int amount);
	void SetClicks(int amount);
	void SetColors(int amount);
	void SetGridHeight(int height);
	void OpenGridWidth();
	void OpenGridHeight();
	void OpenClicks();
	void OpenTime();
	void OpenColors();
	void SetupButtons();
	void DisableButtons();
	void EnableButtons();
	void UpdateText();
};

#endif /* SCENE00_H */
