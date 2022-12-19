/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file hextile.h
 *
 * @brief description of HexTile behavior.
 */

#ifndef HEXTILE_H
#define HEXTILE_H

#include <rt2d/entity.h>

/// @brief The MyEntity class is the Entity implementation.
class HexTile : public Entity
{
public:
	/// @brief Constructor
	HexTile();
	/// @brief Destructor
	~HexTile();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	void checkNeigbors(RGBAColor clickedCol);

	void addNeighbor(HexTile* toAdd);

	std::vector<HexTile*> neigbors;
	bool isChecked;

private:
	/* add your private declarations */
};

#endif /* HEXTILE_H */
