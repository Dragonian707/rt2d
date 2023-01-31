/**
 * This class describes HudBox behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "hudbox.h"

HUDbox::HUDbox() : Entity()
{
	//give this entity a sprite and its size
	this->addSprite("assets/hudBackground.tga");
	sprite()->size = Point2(SWIDTH / 4, SHEIGHT / 6 * 5);
}


HUDbox::~HUDbox()
{
	for (Entity* childs : this->children())
	{
		this->removeChild(childs);
	}
}

void HUDbox::update(float deltaTime)
{

}
