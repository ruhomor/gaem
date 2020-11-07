#include "game.h"

PlayersState::PlayersState()
{
//	printf("creating PlayersState");
}

void	PlayersState::init(int pnum)
{
	playersnum = pnum;
	std::ifstream		player(PLAYERS); //tmp player_file name

	for (int i = 0; i < playersnum; i++)
	{
		int		key, value;

		player >> key; //id
		player >> value; //helth points
		//std::cout << "key " << key << " value " << value << '\n';
		this->insert(std::pair<int, int>(key, value));
	}
}

GameState::GameState(char **argv)
{
	const int				m = atoi(argv[1]);
	const int				n = atoi(argv[2]);
	std::ifstream			mapstate(GAMEMAP); //tmp map_file name
	PlayersState			lifes;

	srand(time(NULL)); // for random algos to work
	id = atoi(argv[3]);
	lifes.init(atoi(argv[4]));
	this->resize(n, std::vector<int>(m));
	action = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int		someid;

			mapstate >> someid;
			if (someid == id)
			{
				x = j;
				y = i;
				//std::cout << "my x " << x << " my y " << y << '\n';
			}
			(*this)[i][j] = lifes[someid];
			//std::cout << someid << " has " << lifes[someid] << " lifes" << '\n'; //debug
		}
	}
	/* DEBUG */
	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			std::cout << (*this)[i][j] << ' '; //debug
		std::cout << '\n';
	}
	*/
}

int		GameState::GetMyX()
{
	return (x);
}

int		GameState::GetMyY()
{
	return (y);
}

int		GameState::GetMyHP()
{
	return ((*this)[y][x]);
}

void	GameState::MoveUp()
{
	action = 1;
}

void	GameState::MoveDown()
{
	action = 2;
}

void	GameState::MoveLeft()
{
	action = 3;
}

void	GameState::MoveRight()
{
	action = 4;
}

void	GameState::ShootUp()
{
	action = 5;
}

void	GameState::ShootDown()
{
	action = 6;
}

void	GameState::ShootLeft()
{
	action = 7;
}

void	GameState::ShootRight()
{
	action = 8;
}

GameState::~GameState()
{
	std::string		filename(STEPFILE);
	std::ofstream	file_out;

	file_out.open(filename, std::ios_base::app);
	file_out << id << ' ' << action << '\n';
	file_out.close();
}
