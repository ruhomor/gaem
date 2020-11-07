#include "gaem.h"

static void		key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) // key -- код клавиши
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

static void		printUsage()
{
	std::cout << "Usage: ./Application {algo folder name} OPTIONAL: {map size x} {map size y}\n";
}

static void		printWrong()
{
	std::cout << "Wrong Number of Arguments\n"; //TODO print to errorstream?
}

static void		gameStep(Map &gameMap, char **argv, PlayerVec &playersTable, int &m, int &n)
{
	usleep(SLEEP);
	//DONE write game step
	/* game step */
	gameMap.display();
	//DONE write map to file map.txt
	gameMap.writeToFile(argv[1]);
	//DONE write playerinfo to file players.txt
	playersTable.writeToFile(argv[1]);
	//DONE write getNewAction which will get action from binaries
	int		alivePlayers = playersTable.getAlivePlayersNum();
	int		tmpAction;
	for (int i = 0; i < playersTable.size(); i++) //1 to skip no_algo
	{
		tmpAction = 0;
		//std::cout << i << '\n';
		if (playersTable[i].getAlive())
		{
			//std::cout << "getting action for: " + playersTable[i].getName() + '\n';
			playersTable[i].getNewAction(argv[1], alivePlayers, m, n);
			std::cout << "ALIVE PLAYERS NUMBER : " << alivePlayers << '\n';
			std::cout << playersTable[i].getAlgoName() << '\n';
			tmpAction = playersTable[i].getAction();
			std::cout << "ACTION: " << tmpAction << '\n';
			if ((tmpAction > 0) && (tmpAction < 5)) //0 1 2 3 4 are MOVE_UP MOVE_DOWN etc
				playersTable[i].updatePos(gameMap.move(playersTable[i].getId(), tmpAction));
		}
	}
	//DONE write move step
	//std::cout << "TableSize: " << playersTable.size() << '\n';
	for (int i = 0; i < playersTable.size(); i++)
	{
		if (playersTable[i].getAlive())
		{
			tmpAction = playersTable[i].getAction();
			int		hitId = gameMap.shoot(playersTable[i].getId(), tmpAction);
			if ((tmpAction > 4) && (tmpAction < 9))
			{
				playersTable.decreaseHealth(hitId);
				if (hitId > 0)
				{
					if (playersTable[hitId].getDied())
					{
						playersTable[i].plusScore(KILLSCORE);
						std::cout << playersTable[i].getAlgoName()
							<< " killed " << playersTable[hitId].getAlgoName();
					}
					else
					{
						playersTable[i].plusScore(SHOTSCORE);
						std::cout << playersTable[i].getAlgoName()
							<< " hit " << playersTable[hitId].getAlgoName();
					}
				}
			}
		}
	}
	//DONE write shoot step

	for (int i = 0; i < playersTable.size(); i++)
	{
		std::pair<int, int>		corpse;

		if (playersTable[i].getDied())
		{
			corpse = gameMap.findPos(playersTable[i].getId());
			gameMap[corpse.second][corpse.first] = 0;
			playersTable[i].setDied(false);
		}
	}
}

int		main(int argc, char **argv) //TODO map size x[2] y[3] algofolder [1]
{
	GLFWwindow*		window;
	Map				gameMap;
	int				m = MAPX, n = MAPY;

	/* reading map size from command line */
	if (argc != 2)
	{
		if (argc == 4)
		{
			m = atoi(argv[2]);
			n = atoi(argv[3]);
			gameMap.resize(n, std::vector<int>(m));
			gameMap.setInit();
		}
		else
		{
			printWrong();
			printUsage();
			return (-2);
		}
	}

	/* reading algorithms to playerTable */
	PlayerVec		playersTable(argv[1]);

	if (!(gameMap.isInit()))
		gameMap.resize(MAPY, std::vector<int>(MAPX));

	//DONE compiling algoes
	//DONE create player entity out of algo
	//DONE MAP PLACER FUNCTION

	gameMap.display(); //debug

	/* placing players on map */
	for (int i = 1; i < playersTable.size(); i++)
	{
		playersTable[i].updatePos(gameMap.randPlace(playersTable[i].getId()));
		gameMap.display(); //debug
	}

	/* Initialize the library */
	if (!glfwInit())
		return (-1);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(WINX, WINY, "GAEM", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return (-1);
	}

	/* knopka */
	glfwSetKeyCallback(window, key_callback); //windows -- окно key_callback -- функция обрабатывающая кнопки

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	int 	step = 0;
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		step++;
		if (step >= MAXSTEP)
			glfwSetWindowShouldClose(window, GLFW_TRUE);
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		int width, height;
		glfwGetWindowSize(window, &width, &height);

		//float		SidePx = std::min(WINX / m, WINY / n); //Px
		//float		xPx = 2.0 / WINX * SidePx, yPx = 2.0 / WINY * SidePx; //Doli

		float		SidePx = std::min(width / m, height / n); //Px
		float		xPx = 2.0 / width * SidePx, yPx = 2.0 / height * SidePx; //Doli

		glBegin(GL_LINES);
		//horizontal

		for (int i = 0; i <= n; i++)
		{
			float		start = -1.0f;

			start += i * yPx;
			glVertex2f(-1.0f, start);
			glVertex2f(m * xPx - 1.0f, start);
		}

		//vertical
	    for (int i = 0; i <= m; i++)
		{
			float		start = -1.0f;

			start += i * xPx;
			glVertex2f(start, -1.0f);
			glVertex2f(start, n * yPx - 1.0f);
		}
		glEnd();

		//DrawEllipse(xPx / 2, yPx / 2, xPx / 2, yPx / 2); //left bottom
		//DrawEllipse(xPx / 2, yPx / 2, xPx / 2 * 3, yPx / 2 * 3); //left bottom

		//DONE write game step
		/* game step */
		gameStep(gameMap, argv, playersTable, m, n);

		/* display on screen */
		for (int i = 1; i < playersTable.size(); i++)
		{
			std::pair<int, int>		coords;

			coords = playersTable[i].getPos();
			coords.second = n - coords.second - 1;
			std::cout << "x: " << coords.first << "y: " << coords.second << '\n';
			if (playersTable[i].getAlive())
			{
				DrawEllipse(xPx / 2, yPx / 2,
						xPx * coords.first + xPx / 2,
						yPx * coords.second + yPx / 2,
						playersTable[i].getColor());
				/*output(xPx / 2, yPx / 2,
						(Color){.r = 0.0f, .g = 0.0f, .b = 0.0f},
						,
						std::to_string(playersTable[i].getHP()));*/
				/*
				glColor3f (1.0, 0.0, 0.0);
				glRasterPos2f(0, 0); //define position on the screen
				char *string = "Text";
				while(*string)
				{
					glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *string++);
				}
				*/
			}

			if (playersTable[i].getAction() > 4)
			{
				ShootingAnimate(xPx, yPx, xPx * coords.first + xPx / 2, yPx * coords.second + yPx / 2, playersTable[i].getAction());
			}
		}
		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}
