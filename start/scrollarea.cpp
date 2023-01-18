/**
 * This class describes ScrollArea behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "scrollarea.h"

ScrollArea::ScrollArea() : Entity()
{
	active = false;
}

ScrollArea::~ScrollArea()
{
	for (Entity* child : this->children())
	{
		this->removeChild(child);
	}
}

void ScrollArea::update(float deltaTime)
{
	if (active)
	{
		if (input()->getKey(KeyCode::Down))
		{
			for (Entity* child : this->children())
			{
				child->position.y += 10;
			}
		}
		if (input()->getKey(KeyCode::Up))
		{
			for (Entity* child : this->children())
			{
				child->position.y -= 10;
			}
		}
	}
}
