/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file ScrollArea.h
 *
 * @brief description of ScrollArea behavior.
 */

#ifndef SCROLLAREA_H
#define SCROLLAREA_H

#include <rt2d/entity.h>
#include <rt2d/text.h>


/// @brief The MyEntity class is the Entity implementation.
class ScrollArea : public Entity
{
public:
	/// @brief Constructor
	ScrollArea();
	/// @brief Destructor
	~ScrollArea();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	bool active;

private:
	/* add your private declarations */
	Text* scrollText;
};

#endif /* ScrollArea_H */
