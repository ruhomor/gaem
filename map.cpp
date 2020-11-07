#include "map.h"
#include "rules.h"

Map::Map(int m, int n) //Matrix[n][m]
{
	this->resize(n, std::vector<int>(m));
	init = true;
}

Map::Map() //Matrix[n][m]
{
	srand((unsigned int)time(0));
	init = false;
}

void					Map::display()
{
	for (int i = 0; i < (*this).size(); i++)
	{
		for (int j = 0; j < (*this)[i].size(); j++)
			std::cout << (*this)[i][j] << ' ';
		std::cout << '\n';
	}
}

void					Map::writeToFile(std::string algoFolder)
{
	std::ofstream	fael(GAMEMAP);

	if (fael.is_open())
	{
		for (int i = 0; i < (*this).size(); i++)
		{
			for (int j = 0; j < (*this)[i].size(); j++)
				fael << (*this)[i][j] << ' ';
			fael << '\n';
		}
		fael.close();
	}
	else
		std::cout << "Unable to open file\n";
}

std::pair<int, int>		Map::findPos(int id)
{
	std::pair<int, int>		coords;

	for (int i = 0; i < (*this).size(); i++)
	{
		for (int j = 0; j < (*this)[i].size(); j++)
		{
			if ((*this)[i][j] == id)
			{
				coords.first = j; //x
				coords.second = i; //y
			}
		}
	}
	return (coords);
}

std::pair<int, int>		Map::randPlace(int id) //TODO refactor
{
	std::pair<int, int>		coords;
	int						x, y;

	y = rand() % (*this).size();
	x = rand() % (*this)[0].size();
	std::cout << "random placement x: "
		<< x << " y " << y << '\n';
	while ((*this)[y][x] != 0)
	{
		y = rand() % (*this).size();
		x = rand() % (*this)[0].size();
		std::cout << "random placement x: "
			<< x << " y " << y << '\n';
	}
	(*this)[y][x] = id;
	coords.first = x;
	coords.second = y;
	return (coords);
}

std::pair<int, int>		Map::move(int id, int action)
{
	std::pair<int, int>		coords;
	std::pair<int, int>		newCoords;

	coords = (*this).findPos(id);
	newCoords = coords;
	switch (action)
	{
		case MOVE_UP :
			newCoords.second--; //move up is to decrease coord
			break;
		case MOVE_DOWN :
			newCoords.second++; //move down is to increase coord
			break;
		case MOVE_LEFT :
			newCoords.first--;
			break;
		case MOVE_RIGHT :
			newCoords.first++;
			break;
		default:
			break;
	}
	if ((newCoords.first < 0) || (newCoords.first >= (*this)[0].size()))
	{
		std::cout << "damnnn1111111nnn\n";
		return (coords);
	}
	if ((newCoords.second < 0) || (newCoords.second >= (*this).size()))
	{
		std::cout << "damnnn1222222222nnn\n";
		return (coords);
	}
	if ((*this)[newCoords.second][newCoords.first] != 0)
		return (coords);
	std::cout << "i am moving on map!!!\n";
	(*this)[coords.second][coords.first] = 0;
	(*this)[newCoords.second][newCoords.first] = id;
	std::cout << "SETTING Y: " << newCoords.second << ", X: " << newCoords.first << "to ID: " << id << '\n';
	return (newCoords);
}

int						Map::shoot(int id, int action)
{
	std::pair<int, int>		coords;
	int						hitId;
	//std::pair<int, int>		hitCoords;

	coords = (*this).findPos(id);
	switch (action)
	{
		case SHOOT_UP :
				for (int i = coords.second - 1; i >= 0; i--)
					if ((*this)[i][coords.first] != 0)
						return ((*this)[i][coords.first]);
			break;
		case SHOOT_DOWN :
			for (int i = coords.second + 1; i < (*this).size(); i++) //shoot up is to increase coord
				if ((*this)[i][coords.first] != 0)
					return ((*this)[i][coords.first]);
			break;
		case SHOOT_LEFT :
			for (int i = coords.first - 1; i >= 0; i--)
				if ((*this)[coords.second][i] != 0)
					return ((*this)[coords.second][i]);
			break;
		case SHOOT_RIGHT :
			for (int i = coords.first + 1;
					i < (*this)[coords.second].size(); i++)
				if ((*this)[coords.second][i] != 0)
					return ((*this)[coords.second][i]);
			break;
		default:
			break;
	}
	return (-1); //ray animation???
}

bool					Map::isInit()
{
	return (init);
}

void					Map::setInit()
{
	init = true;
}
