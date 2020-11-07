#include "../game.h"

int									main(int argc, char **argv) // argv[1] - m argv[2] - n argv[3] - id argv[4]
{
	GameState	map(argv);

	std::cout << "GOTmy HP: " << map.GetMyHP() << '\n';
	std::cout << "GOTmy X: " << map.GetMyX() << '\n';
	std::cout << "GOTmy Y: " << map.GetMyY() << '\n';
	bebe;
	// 0 - stand still
	// 1 - move up
	// 2 - move down
	// 3 - move left
	// 4 - move right
	// 5 - shoot up
	// 6 - shoot down
	// 7 - shoot left
	// 8 - shoot right
	return (0);
}
