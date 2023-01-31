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
		//Check of the neighbors of this kextile are the same color as this one
		if (this->sprite()->color == neigbor->sprite()->color && !neigbor->isChecked)
		{
			//If so, check their neigbors as well
			neigbor->checkNeigbors(clickedCol);
		}
	}
	//Change all their colors to the one that was clicked
	this->addCircleSprite("assets/hexagonPressed.tga", 64 / 2, 6);
	this->sprite()->color = clickedCol;
}

void HexTile::addNeighbor(HexTile* toAdd)
{
	neigbors.push_back(toAdd);
}
