/**
 * This class describes StartScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "startscene.h"

StartScene::StartScene() : Scene()
{
	startbutton = new Button("Start");
	startbutton->position = Point2(SWIDTH / 2, SHEIGHT / 2 - 100);
	startbutton->setCallbackFunction(std::bind(&StartScene::SetScene, this));

	optionbutton = new Button("Options");
	optionbutton->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	optionbutton->setCallbackFunction(std::bind(&StartScene::OpenOptions, this));

	quitbutton = new Button("Quit game");
	quitbutton->position = Point2(SWIDTH / 2, SHEIGHT / 2 + 100);
	quitbutton->setCallbackFunction(std::bind(&StartScene::stop, this));

	this->addChild(startbutton);
	this->addChild(optionbutton);
	this->addChild(quitbutton);
}


StartScene::~StartScene()
{
	this->removeChild(startbutton);
	delete startbutton;
	startbutton = nullptr;

	this->removeChild(optionbutton);
	delete optionbutton;
	optionbutton = nullptr;

	this->removeChild(quitbutton);
	delete quitbutton;
	quitbutton = nullptr;
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

void StartScene::OpenOptions()
{
	ManageScene::activescene = 3;
}