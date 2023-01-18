/**
 * This class describes HexTile behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "hextile.h"

HexTile::HexTile() : Entity()
{
	this->addCircleSprite("assets/hexagon.tga", 64 / 2, 6);
	isChecked = false;
}

HexTile::~HexTile()
{
	//this->parent()->removeChild(this);
	for (int i = neigbors.size() - 1; i >= 0; i--)
	{
		neigbors[i] = nullptr;
		neigbors.erase(neigbors.begin() + i);
	}
}

void HexTile::update(float deltaTime)
{
	
}

void HexTile::checkNeigbors(RGBAColor clickedCol)
{
	isChecked = true;
	for (HexTile* neigbor : neigbors)
	{
		//do stuff
		if (this->sprite()->color == neigbor->sprite()->color && !neigbor->isChecked)
		{
			neigbor->checkNeigbors(clickedCol);
		}
	}
		this->sprite()->color = clickedCol;
}

void HexTile::addNeighbor(HexTile* toAdd)
{
	neigbors.push_back(toAdd);
}
