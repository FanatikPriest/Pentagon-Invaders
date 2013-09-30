#include <list>
#include <SDL.h>
#include <SDL_opengl.h>
#include <GL/glut.h>

#include "SpaceShip.h"

namespace DrawingUtils
{
 
	void renderShip(const SpaceShip& ship, bool flush = true)
	{
		// Begin drawing the ship.
		glBegin(GL_POLYGON);

		// TODO get color from object
		glColor3f(0.75f, 0.5f, 0.25f);

		Vector2f *vertices = ship.getVertices();

		for (int i = 0; i < ship.getNumberOfVertices(); i++) {
			Vector2f v = vertices[i];

			glVertex2f(v.getX(), v.getY());
		}

		// End drawing the ship.
		glEnd();

		if (flush)
		{
			glFlush();
		}
	}

	void renderShips(const std::list<SpaceShip*>& ships)
	{
		std::list<SpaceShip*>::const_iterator iterator;
		for (iterator = ships.begin(); iterator != ships.end(); ++iterator) {
			SpaceShip* ship = *iterator;
			renderShip(*ship, false);
		}

		glFlush();
	}
}