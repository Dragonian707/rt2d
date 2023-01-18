/**
 * This class describes Grid behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "grid.h"

Grid::Grid(int X, int Y, int colorAmount) : Entity()
{
	//set grid sizes correct
	gridx = X;
	gridy = Y;

	//give new seed to randomize off of
	srand(time(NULL));

	//add colors to list in order to assign them randomly
	if (colorAmount == 7)
	{
		colors.push_back(RED);
		colors.push_back(ORANGE);
		colors.push_back(YELLOW);
		colors.push_back(GREEN);
		colors.push_back(BLUE);
		colors.push_back(MAGENTA);
		colors.push_back(WHITE);
	}
	else
	{
		for (int i = 0; i <= colorAmount; i++)
		{
			colors.push_back(RGBAColor(rand() & 255, rand() & 255, rand() & 255, 255));
		}
	}

	// create the grid
	createGrid();
}


Grid::~Grid()
{
	//delete all te tiles and make the pointers NULL
	for (size_t i = 0; i < tiles.size(); i++)
	{
		removeChild(tiles[i]);
		delete tiles[i];
		tiles[i] = nullptr;
	}
}

void Grid::update(float deltaTime)
{
	//get the position of the mouse
	int mouseX = input()->getMouseX();
	int mouseY = input()->getMouseY();
	Point2 mousepos = Point2(mouseX, mouseY);

	//check the closest hex in comparison to the mouse position
	int selectedID = CheckClosest(mousepos);
	/*std::cout << "selected: " << selectedID << " X pos: " << (selectedID % gridx) << " Y pos: " << (selectedID / gridx) << std::endl;*/
	
	//whenever you click
	if (input()->getMouseDown(0))
	{
		/*std::cout << "click!" << std::endl;*/
		//if it's the first click set the first tile else update them and their neighbors to be new colors
		if (firstClick == nullptr)
		{
			firstClick = tiles[selectedID];
		}
		else
		{
			firstClick->checkNeigbors(tiles[selectedID]->sprite()->color);
			checkColors();
			for (size_t i = 0; i < tiles.size(); i++)
			{
				tiles[i]->isChecked = false;
			}
		}
	}

	//if (input()->getKeyDown(KeyCode::Enter))
	//{
	//	//createGrid();
	//	win();
	//}
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

void Grid::checkColors()
{
	RGBAColor compare = firstClick->sprite()->color;
	int counter = 0;

	for (int i = 0; i < tiles.size(); i++)
	{
		if (tiles[i]->sprite()->color == compare)
		{
			counter++;
		}
		tiles[i]->isChecked = false;
	}
	std::cout << "counter amount: " << counter << " target: " << tiles.size() << std::endl;
	if (counter == tiles.size())
	{
		win();
	}
}

void Grid::win()
{
	std::cout << "You Win!" << std::endl;
	ManageScene::activescene = 2;
}

void Grid::createGrid()
{
	removeGrid();
	firstClick = nullptr;

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
			this->addChild(hextile);
			hextile->sprite()->color = colors[rand() % colors.size()];
			tiles.push_back(hextile);
		}
	}

	//add the neigbors to all hexes
	for (int i = 0; i < tiles.size(); i++)
	{
		//get x and y value of tile to give neigbors to
		int y = i / gridx;
		int x = i % gridx;

		//create temporary lists to store neigbors values in
		std::vector<unsigned char> indexesX;
		std::vector<unsigned char> indexesY;
		std::vector<int> indexesTiles;

		//gain the neigbors values by x and y coordinate
		indexesX.push_back(x - 1);	indexesY.push_back(y);
		indexesX.push_back(x + 1);	indexesY.push_back(y);
		indexesX.push_back(x);		indexesY.push_back(y - 1);
		indexesX.push_back(x);		indexesY.push_back(y + 1);

		if (x % 2 == 0) //if the x is even minus the y value, else plus the y value
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

		//check if the values are in range
		for (int j = indexesX.size() - 1; j >= 0; j--)
		{
			if (indexesX[j] >= gridx || indexesY[j] >= gridy) //if not, erase them from the list  
			{
				indexesX.erase(indexesX.begin() + j);
				indexesY.erase(indexesY.begin() + j);
			}
			else //else convert them to a single digit and add that to a list
			{
				int add = gridx * indexesY[j] + indexesX[j];
				indexesTiles.push_back(add);
			}
		}
		//give single digit values to add correct neighbors
		for (int j = 0; j < indexesTiles.size(); j++)
		{
			tiles[i]->addNeighbor(tiles[indexesTiles[j]]);
		}
	}

}
void Grid::removeGrid()
{
	for (int i = tiles.size() - 1; i >= 0; i--)
	{
		removeChild(tiles[i]);
		delete tiles[i];
		tiles[i] = nullptr;
		tiles.erase(tiles.begin() + i);
	}
}
