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
	//Create the grid 
	grid = new Grid(ManageScene::Xsize, ManageScene::Ysize, ManageScene::Colors);
	clicksleft = ManageScene::Clicks;
	t.start();
	this->addChild(grid);

	//Place text in the bottomleft with some information
	HUD = new Text;
	HUD->position = Point2(SWIDTH / 8, SHEIGHT - 15);
	HUD->scale = Point2(0.3, 0.3);
	this->addChild(HUD);
	UpdateText();

	//Make a menu for when the player pushed escape
	pauseHUD = new HUDbox;
	pauseHUD->position = Point2(SWIDTH / 2, SHEIGHT / 2);

	closeHUD = new Button("close");
	closeHUD->position = Point2(0, -200);
	closeHUD->setCallbackFunction(std::bind(&GameScene::ClosePause, this));
	openOptions = new Button("options");
	openOptions->position = Point2(0, 0);
	openOptions->setCallbackFunction(std::bind(&GameScene::OpenOptions, this));
	quitGame = new Button("quit");
	quitGame->position = Point2(0, 200);
	quitGame->setCallbackFunction(std::bind(&GameScene::stop, this));

	pauseHUD->addChild(closeHUD);
	pauseHUD->addChild(openOptions);
	pauseHUD->addChild(quitGame);
}

GameScene::~GameScene()
{
	this->removeChild(grid);
	delete grid;
	grid = nullptr;

	if (pauseHUD->parent() != nullptr)
	{
		this->removeChild(pauseHUD);
	}
	delete pauseHUD;
	pauseHUD = nullptr;

	delete closeHUD;
	closeHUD = nullptr;
	delete openOptions;
	openOptions = nullptr;
	delete quitGame;
	quitGame = nullptr;
}

void GameScene::update(float deltaTime)
{
	//Pause the game when escape is pressed
	if (input()->getKeyUp(KeyCode::Escape) && !t.paused()) {
		OpenPause();
	}
	
	//Check if the player still can click
	if (clicksleft <= 0)
	{
		ResetGrid();
	}

	//Check if the time has run out
	if (t.seconds() >= ManageScene::Time)
	{
		ResetGrid();
	}

	//Regenetrate the grid with enter
	if (input()->getKeyDown(KeyCode::Enter))
	{
		ResetGrid();
	}

	//Remove a click when clicking and the game isn't paused
	if (input()->getMouseDown(0) && !t.paused())
	{
		clicksleft--;
	}

	UpdateText();
}

void GameScene::OpenPause()
{
	t.pause();
	grid->paused = true;
	this->addChild(pauseHUD);
}
void GameScene::OpenOptions()
{
	ManageScene::activescene = 3;
}
void GameScene::ClosePause()
{
	t.unpause();
	grid->paused = false;
	this->removeChild(pauseHUD);
}

void GameScene::UpdateText()
{
	//Update the informational text
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
