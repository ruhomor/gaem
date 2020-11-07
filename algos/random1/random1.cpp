#include "../game.h"

int									main(int argc, char **argv) // argv[1] - m argv[2] - n argv[3] - id argv[4]
{
	GameState	map(argv);
	int			action = rand() % 9;

	//srand (time(NULL));
	switch (action)
	{
		case 1 :
			map.MoveUp();
			break;
		case 2 :
			map.MoveDown();
			break;
		case 3 :
			map.MoveLeft();
			break;
		case 4 :
			map.MoveRight();
			break;
		case 5 :
			map.ShootUp();
			break;
		case 6 :
			map.ShootDown();
			break;
		case 7 :
			map.ShootLeft();
			break;
		case 8 :
			map.ShootRight();
			break;
		default :
			break;
	}
	return (0);
}
