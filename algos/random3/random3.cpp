#include "../game.h"

int									main(int argc, char **argv) // argv[1] - m argv[2] - n argv[3] - id argv[4]
{
	GameState	map(argv);
	int			action = rand() % 9;

	//srand (time(NULL));
	switch (action)
	{
		case 3 :
			map.MoveUp();
			break;
		case 4 :
			map.MoveDown();
			break;
		case 1 :
			map.MoveLeft();
			break;
		case 2 :
			map.MoveRight();
			break;
		case 7 :
			map.ShootUp();
			break;
		case 8 :
			map.ShootDown();
			break;
		case 5 :
			map.ShootLeft();
			break;
		case 6 :
			map.ShootRight();
			break;
		default :
			break;
	}
	return (0);
}
