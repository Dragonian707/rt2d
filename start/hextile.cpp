/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "hextile.h"

HexTile::HexTile() : Entity()
{
	Sprite* s = new Sprite();
	s->setupCircleSprite("assets/hexagon256.tga", 64 / 2, 6);
	s->uvdim = Point2(0.25f , 0.25f);
	s->filter(0);
	s->wrap(0);
	s->useCulling(1);
	s->uvoffset = Point2(-0.375f, -0.375f);
	s->color = RED;
	this->addSprite(s);
}

HexTile::~HexTile()
{
	//this->parent()->removeChild(this);
}

void HexTile::update(float deltaTime)
{
	
}

void HexTile::updateNeigbors()
{
	for each (HexTile* neigbor in neigbors)
	{
		//do stuff
		RGBAColor color = neigbor->sprite()->color;
		neigbor->sprite()->color = Color::rotate(color, 0.1f);
	}
}

void HexTile::addNeighbor(HexTile* toAdd)
{
	neigbors.push_back(toAdd);
}
