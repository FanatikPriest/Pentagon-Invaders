#include <list>
#include <SDL.h>
#include <SDL_opengl.h>
#include <GL/glut.h>
#include <math.h>

#include "SpaceShip.h"
#include "Color.h"

class DrawingUtils
{
public:
	static void drawCircle(const float x, const float y, const float radius)
	{

		glLineWidth(1);

		float x2, y2;
		float angle;

		// TODO get color from object
		glColor3f(0.75f, 0.5f, 0.25f);
 
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
 
		for (angle = 1.0f; angle < 361.0f; angle += 1.0)
		{
			x2 = x + sin(angle) * radius;
			y2 = y + cos(angle) * radius;

			glVertex2f(x2, y2);
		}
 
		glEnd();
	}

	static void renderShip(const SpaceShip& ship, const bool flush = true)
	{
		// Begin drawing the ship.
		glBegin(GL_POLYGON);

		const Color& color = ship.getColor();
		glColor3f(color.red, color.green, color.blue);

		Vector2f *vertices = ship.getVertices();

		for (int i = 0; i < ship.getNumberOfVertices(); i++)
		{
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

	static void renderShips(const std::list<SpaceShip*>& ships)
	{
		std::list<SpaceShip*>::const_iterator iterator;
		for (iterator = ships.begin(); iterator != ships.end(); ++iterator)
		{
			SpaceShip* ship = *iterator;
			renderShip(*ship, false);
		}

		glFlush();
	}

	static void renderBullet(const Bullet& b, const bool flush = true)
	{
		drawCircle(b.getCenter().getX(), b.getCenter().getY(), b.getRadius());

		if (flush)
		{
			glFlush();
		}
	}

	static void renderBullets(std::list<Bullet*>& bullets)
	{
		for (auto iterator = bullets.begin(); iterator != bullets.end(); ++iterator)
		{
			renderBullet(**iterator, false);
		}

		glFlush();
	}
};