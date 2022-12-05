/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef GRID_H
#define GRID_H

//#include <vector>
#include <rt2d/scene.h>

#include "hextile.h"

/// @brief The MyScene class is the Scene implementation.
class Grid : public Scene
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

private:
	std::vector<HexTile*> tiles;
	HexTile* hextile;
	std::vector<RGBAColor> colors;

	int gridy = 12;
	int gridx = 26;
	//HexTile* tiles[12][26];

	int CheckClosest(Point2 pos);
};

#endif /* GRID_H */
