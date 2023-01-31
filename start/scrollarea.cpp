/**
 * This class describes ScrollArea behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "scrollarea.h"

ScrollArea::ScrollArea() : Entity()
{
	active = false;
	//place text in the bottomleft corner to inform the player how to scroll
	scrollText = new Text;
	scrollText->message("Use arrows to scroll up and down");
	scrollText->scale = Point2(0.4, 0.4);
	scrollText->position = Point2(30, SHEIGHT - 30);
	addChild(scrollText);
}

ScrollArea::~ScrollArea()
{
	delete scrollText;
	scrollText = nullptr;
}

void ScrollArea::update(float deltaTime)
{
	if (active)
	{
		//while pushing the down arrow move everything up
		if (input()->getKey(KeyCode::Down))
		{
			for (Entity* child : this->children())
			{
				if (child->position.x != SWIDTH / 2)
				{
				}
				else
				{
					child->position.y += 350 * deltaTime;
				}
			}
		}
		//while pushing the up arrow move everything down
		if (input()->getKey(KeyCode::Up))
		{
			for (Entity* child : this->children())
			{
				if (child->position.x != SWIDTH / 2)
				{
				}
				else
				{
					child->position.y -= 350 * deltaTime;
				}
			}
		}
	}
}
