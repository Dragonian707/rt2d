/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "grid.h"

Grid::Grid() : Scene()
{
	for (int y = 0; y < gridy; y++)
	{
		for (int x = 0; x < gridx; x++)
		{
			hextile = new HexTile();
			hextile->position.x = x * 64 * 0.75f;
			if (x % 2 == 0)
			{
				hextile->position.y = y * 64 * sin(60 * DEG_TO_RAD);
			}
			else
			{
				hextile->position.y = y * 64 * sin(60 * DEG_TO_RAD) + (sin(60 * DEG_TO_RAD) * 32);
			}
			hextile->position += Point2(32, 32);
			//hextile->sprite()->frame(rand() % 16);
			this->addChild(hextile);
			tiles.push_back(hextile);
		}
	}
	colors.push_back(RED);
	colors.push_back(ORANGE);
	colors.push_back(YELLOW);
	colors.push_back(GREEN);
	colors.push_back(BLUE);
	colors.push_back(MAGENTA);
	colors.push_back(WHITE);

	for (int i = 0; i < tiles.size(); i++)
	{
		int y = i / gridx;
		int x = i % gridx;
		//std::cout << "index: " << i << " X position: " << x << " Y position: " << y << std::endl;
		std::vector<unsigned char> indexesX;
		std::vector<unsigned char> indexesY;
		std::vector<int> indexesTiles;
		//std::cout << "//X coordinate: " << x << "//Y coordinate: " << y << "//position: " << tiles[i]->position << std::endl;
		indexesX.push_back(x - 1);	indexesY.push_back(y);
		indexesX.push_back(x + 1);	indexesY.push_back(y); 
		indexesX.push_back(x);		indexesY.push_back(y - 1);
		indexesX.push_back(x);		indexesY.push_back(y + 1);

		if (x % 2 == 0)
		{
			// +1 / -1 / +26 / -25 -- -27
			indexesX.push_back(x - 1); indexesY.push_back(y - 1);
			indexesX.push_back(x + 1); indexesY.push_back(y - 1);
		}
		else
		{
			// +1 / -1 / -26 / +25 -- +27
			indexesX.push_back(x - 1); indexesY.push_back(y + 1);
			indexesX.push_back(x + 1); indexesY.push_back(y + 1);
		}
		//check values
		for (int j = indexesX.size() - 1; j >= 0; j--)
		{
			if (indexesX[j] > 25 || indexesY[j] > 11)
			{
				indexesX.erase(indexesX.begin() + j);
				indexesY.erase(indexesY.begin() + j);
			}
			else
			{
				int add = gridx * indexesY[j] + indexesX[j];
				indexesTiles.push_back(add);
			}
		}
		//give values to add neighbors
		for (int j = 0; j < indexesTiles.size(); j++)
		{
			tiles[i]->addNeighbor(tiles[indexesTiles[j]]);
		}
	}
}


Grid::~Grid()
{
	for (size_t i = 0; i < tiles.size(); i++)
	{
		removeChild(tiles[i]);
		delete tiles[i];
		tiles[i] = nullptr;
	}
}

void Grid::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
	int mouseX = input()->getMouseX();
	int mouseY = input()->getMouseY();
	Point2 mousepos = Point2(mouseX, mouseY);

	int selectedID = CheckClosest(mousepos);
	std::cout << "selected: " << selectedID << " X pos: " << (selectedID % gridx) << " Y pos: " << (selectedID / gridx) << std::endl;
	if (input()->getMouseDown(0))
	{
		//std::cout << "click!" << std::endl;
		//RGBAColor color = tiles[selectedID]->sprite()->color;
		//tiles[selectedID]->sprite()->color = Color::rotate(color, 0.1f);
		tiles[selectedID]->updateNeigbors();
	}
}

int Grid::CheckClosest(Point2 pos)
{
	int n = 0;
	float closest = 10000;

	for (int i = 0; i < tiles.size(); i++)
	{
		Vector2 p = Vector2(tiles[i]->position, pos);
		float b = p.getLength();
		if (b < closest)
		{
			closest = b;
			n = i;
		}
	}
	return n;
}
