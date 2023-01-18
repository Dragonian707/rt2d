/**
 * This class describes ManageScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "managescene.h"

#include "startscene.h"
#include "gamescene.h"
#include "endscene.h"
#include "optionscene.h"

int ManageScene::activescene = 0;
int ManageScene::Xsize = 26;
int ManageScene::Ysize = 12;
int ManageScene::Clicks = 24;
int ManageScene::Time = 120;
int ManageScene::Colors = 7;

ManageScene::ManageScene()
{
	currentScene = new StartScene();
	std::cout << "nieuwe managescene" << std::endl;
	active = startscene; 
}


ManageScene::~ManageScene()
{
	delete currentScene;
	currentScene = nullptr;
}

Scene* ManageScene::GetActiveScene()
{
	if (currentScene == nullptr)
	{
		return NULL;
	}

	if (!currentScene->isRunning())
	{
		running = false;
	}

	CheckScene();

	return currentScene;
}

void ManageScene::CheckScene()
{
	if (currentScene == nullptr)
	{
		currentScene = new StartScene();
		active = startscene;
	}
	
	switch (activescene)
	{
		case 0:
		{
			if (active != startscene)
			{
				delete currentScene;
				currentScene = new StartScene();
				active = startscene;
			}
			break;
		}
		case 1:
		{
			if (active != gamescene)
			{
				delete currentScene;
				currentScene = new GameScene();
				active = gamescene;
			}
			break;
		}
		case 2:
		{
			if (active != endscene)
			{
				delete currentScene;
				currentScene = new EndScene();
				active = endscene;
			}
			break;
		}
		case 3:
		{
			if (active != optionscene)
			{
				delete currentScene;
				currentScene = new OptionScene();
				active = optionscene;
			}
			break;
		}
	}
}
