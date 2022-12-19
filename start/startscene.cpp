/**
 * This class describes StartScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "startscene.h"
#include "managescene.h"

StartScene::StartScene() : Scene()
{
	startbutt = new Button("Start");
	startbutt->position = Point2(SWIDTH / 2, SHEIGHT / 2 - 100);
	startbutt->setCallbackFunction(std::bind(&StartScene::SetScene, this));

	quitbutton = new Button("Quit game");
	quitbutton->position = Point2(SWIDTH / 2, SHEIGHT / 2 + 100);
	quitbutton->setCallbackFunction(std::bind(&StartScene::stop, this));

	this->addChild(startbutt);
	this->addChild(quitbutton);
}


StartScene::~StartScene()
{
	this->removeChild(startbutt);
	delete startbutt;
	startbutt = nullptr;

	this->removeChild(quitbutton);
	delete quitbutton;
	quitbutton = nullptr;

	std::cout << "startscene deconstructor \n";
}

void StartScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
}

void StartScene::SetScene()
{
	ManageScene::activescene = 1;
}
