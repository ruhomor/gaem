#include "graphics.h"

void	DrawEllipse(float radiusX, float radiusY, float x, float y, Color c)
{
	int		i;

	//glBegin(GL_LINE_LOOP);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(c.r, c.g, c.b);
	glVertex2f(x - 1.0f, y - 1.0f);
	for(i = 0;i < 361; i++)
	{
		float rad = i * DEG2RAD;
		glVertex2f(cos(rad) * radiusX + x - 1.0f,
				sin(rad) * radiusY + y - 1.0f);
	}
	glEnd();
}


void ShootingAnimateWall(float xPx, float yPx, float x, float y, int direction, Color c)
{
	switch (direction) {
		case 5: //SHOOT_DOWN
			glBegin(GL_TRIANGLE_FAN);
			glColor3f(c.r, c.g, c.b);
			glVertex2f(x + (xPx / 2) - 1.0f, y - 1.0f);
			glVertex2f(x - (xPx / 2) - 1.0f, y - 1.0f);
			glVertex2f(x - 1.0f, -1.0f);
			glEnd();
			break;

		case 6: //SHOOT_UP
			glBegin(GL_TRIANGLE_FAN);
			glColor3f(c.r, c.g, c.b);
			glVertex2f(x + (xPx / 2) - 1.0f, y - 1.0f);
			glVertex2f(x - (xPx / 2) - 1.0f, y - 1.0f);
			glVertex2f(x - 1.0f, 1.0f);
			glEnd();
			break;
		case 7: //SHOOT_LEFT
			glBegin(GL_TRIANGLE_FAN);
			glColor3f(c.r, c.g, c.b);
			glVertex2f(x - 1.0f, y + (yPx / 2) - 1.0f);
			glVertex2f(x - 1.0f, y - (yPx / 2) - 1.0f);
			glVertex2f(-1.0, y - 1.0f);
			glEnd();
			break;
		case 8: //SHOOT_RIGHT
			glBegin(GL_TRIANGLE_FAN);
			glColor3f(c.r, c.g, c.b);
			glVertex2f(x - 1.0f, y + (yPx / 2) - 1.0f);
			glVertex2f(x - 1.0f, y - (yPx / 2) - 1.0f);
			glVertex2f(1.0, y - 1.0f);
			glEnd();
			break;

		default:
			break;
	}

}

void ShootingAnimateHit(float xPx, float yPx, float x, float y, int direction, Color c, int tx, int ty)
{

}
/*
void	DrawLine(float tx, float ty, float x, float y, Color c)
{
	int		i;

	glBegin(GL_LINES);
	glLineWidth(2.5);
	glColor3f(c.r, c.g, c.b);
	glVertex2f(x - 1.0f, y - 1.0f);
	glVertex2f(tx - 1.0f, ty - 1.0f);
	glLineWidth(1);
	glColor3f(1.0f, 1.0f, 1.0f);
	glEnd();
}
*/
/*
void	output(int x, int y, Color c, int font, std::string s)
{
	glColor3f(c.r, c.g, c.b);
	glRasterPos2f(x, y);
	int len, i;
	len = (int)strlen(s);
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(font, s[i]);
	}
}
*/
