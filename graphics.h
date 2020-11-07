#ifndef GRAPHICS_H

# define GRAPHICS_H

# include <GLFW/glfw3.h>
//# include <GLUT/glut.h>
# include <algorithm>
# include <math.h>
# include "color.h"
//# include <GLUT/glut.h>
# include <string>

//# define STEPS 30
//# define ANGLE 3.1415926 * 2.f / 30 //STEPS
# define DEG2RAD 3.14159/180.0

void	DrawEllipse(float radiusX, float radiusY, float x, float y, Color c);
//void	output(int x, int y, Color c, int font, std::string s);
void ShootingAnimate(float xPx, float yPx, float x, float y, int direction, Color c);


#endif
