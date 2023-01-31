/**
 * This class describes EndScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "endscene.h"

EndScene::EndScene() : Scene()
{
	endText = new Text;
	endText->message(" YOU WIN!");
	endText->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	endText->position.x -= (endText->message().size() * 32 * endText->scale.x / 2);
	this->addChild(endText);

	backToHome = new Button("main menu");
	backToHome->position = Point2(SWIDTH / 2, SHEIGHT / 4 * 3);
	backToHome->setCallbackFunction(std::bind(&EndScene::mainMenu, this));

	this->addChild(backToHome);
}


EndScene::~EndScene()
{
	this->removeChild(endText);
	delete endText;
	endText = nullptr;

	this->removeChild(backToHome);
	delete backToHome;
	backToHome = nullptr;
}

void EndScene::update(float deltaTime)
{
	
}

void EndScene::mainMenu()
{
	ManageScene::activescene = 0;
}
