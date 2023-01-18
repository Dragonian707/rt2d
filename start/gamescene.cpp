/**
 * This class describes GameScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "gamescene.h"
#include "grid.h"

GameScene::GameScene() : Scene()
{
	grid = new Grid(ManageScene::Xsize, ManageScene::Ysize, ManageScene::Colors);
	clicksleft = ManageScene::Clicks;
	t.start();
	this->addChild(grid);
	HUD = new Text;
	HUD->position = Point2(SWIDTH / 8, SHEIGHT - 15);
	HUD->scale = Point2(0.3, 0.3);
	this->addChild(HUD);
	UpdateText();
}

GameScene::~GameScene()
{
	this->removeChild(grid);
	delete grid;
	grid = nullptr;
}

void GameScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
	
	if (clicksleft <= 0)
	{
		ResetGrid();
	}

	if (t.seconds() >= ManageScene::Time)
	{
		ResetGrid();
	}

	if (input()->getKeyDown(KeyCode::Enter))
	{
		ResetGrid();
	}

	if (input()->getMouseDown(0))
	{
		clicksleft--;
	}

	UpdateText();
}

void GameScene::UpdateText()
{
	std::string display = "";
	display += "Time left: ";
	display += std::to_string(ManageScene::Time - t.seconds());
	display += "     Clicks left: ";
	display += std::to_string(clicksleft);
	HUD->message(display);
}

void GameScene::ResetGrid()
{
	t.stop();
	grid->createGrid();
	clicksleft = ManageScene::Clicks;
	t.start();
}
