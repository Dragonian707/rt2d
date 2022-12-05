/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
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

	std::vector<HexTile*> neigbors;

	void updateNeigbors();

	void addNeighbor(HexTile* toAdd);

private:
	/* add your private declarations */
};

#endif /* HEXTILE_H */
