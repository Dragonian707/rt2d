/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file hudbox.h
 *
 * @brief description of HUDbox behavior.
 */

#ifndef HUDBOX_H
#define HUDBOX_H

#include <rt2d/entity.h>

class HUDbox: public Entity
{
	public:
		HUDbox();
		virtual ~HUDbox();

		virtual void update(float deltaTime);

	private:
		/* add your private declarations */
};

#endif /* HUDbox_H */
