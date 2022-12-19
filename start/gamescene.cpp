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
	grid = new Grid;
	this->addChild(grid);
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

	if (input()->getKeyDown(KeyCode::Enter))
	{
		grid->createGrid();
	}
}
