/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:52:12 by Ruslan            #+#    #+#             */
/*   Updated: 2020/11/07 06:39:06 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYERS_H

# define PLAYERS_H
# include <string>
/* for reading filenames */
# include <fstream>
# include <iostream>
# include <experimental/filesystem>
# include <vector>
# include <cstdio> //for file deletion
# define EXTENSION ".player" //algo extension
# define EXTLEN 7 //it's len
# include "color.h"
namespace fs = std::experimental::filesystem;

class	Player
{
private:
	std::string				algoName;
	int						id, hp, x, y, action, score;
	bool					isAlive, died;
	Color					c;
public:
	Player(std::string aName, int iid, int hhp);
	int						getId();
	int						getHP();
	Color					getColor();
	void					getNewAction(std::string algoFolder,
			int alivePlayers, int maxX, int maxY);
	bool					getAlive();
	void					plusScore(int bal);
	bool					getDied();
	int						getScore();
	std::string				getAlgoName();
	std::pair<int, int>		getPos();
	int						getAction();
	int						getX();
	int						getY();
	std::string				getName();
	void					setY(int newY);
	void					setX(int newX);
	void					setDied(bool tmp);
	void					decreaseHealth();
	void					updatePos(std::pair<int, int> coords);
};

class	PlayerVec : public std::vector<Player>
{
public:
	PlayerVec(std::string algofolder);
	void	writeToFile(std::string algoFolder);
	void	decreaseHealth(int id);
	int		getAlivePlayersNum();
};

#endif
