#include "../game.h"

int									main(int argc, char **argv) // argv[1] - m argv[2] - n argv[3] - id argv[4]
{
	GameState	map(argv);

	//map.GetMyHP(); - to get your health points
	//map.GetMyX(); - to get your X coord
	//map.GetMyY(); - to get your Y coord
	//
	//map[y][x]; - to check map.
	//0 means cell is empty
	//not 0 means theres somebody with that amount of hp
	//
	//map.size(); - to check map max_y coord
	//map[0].size(); to check map max_x coord
	//nothing 0 - stand still
	//map.MoveUp() - move up
	//map.MoveDown() - move down
	//map.MoveLeft() - move left
	//map.MoveRight() - move right
	//map.ShootUp - shoot up
	//map.ShootDown - shoot down
	//map.ShootLeft - shoot left
	//map.ShootRight - shoot right
	return (0);
}
