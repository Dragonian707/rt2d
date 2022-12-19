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
	endText->message("YOU WIN!");
	endText->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	this->addChild(endText);
}


EndScene::~EndScene()
{
	this->removeChild(endText);
	delete endText;
	endText = nullptr;
}

void EndScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
}
