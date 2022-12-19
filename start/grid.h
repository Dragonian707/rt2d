/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file grid.h
 *
 * @brief description of Grid behavior.
 */

#ifndef GRID_H
#define GRID_H

//#include <vector>
#include <rt2d/scene.h>

#include "hextile.h"
#include "managescene.h"

/// @brief The MyScene class is the Scene implementation.
class Grid : public Entity
{
public:
	/// @brief Constructor
	Grid();
	/// @brief Destructor
	~Grid();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	void createGrid();

private:
	std::vector<HexTile*> tiles;
	HexTile* hextile;
	std::vector<RGBAColor> colors;

	int gridy = 12;
	int gridx = 26;
	HexTile* firstClick = nullptr;

	void removeGrid();
	void checkColors();
	void win();

	int CheckClosest(Point2 pos);
};

#endif /* GRID_H */
