# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kachiote <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/03 14:53:22 by kachiote          #+#    #+#              #
#    Updated: 2020/11/06 22:41:43 by Ruslan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = g++

NAME = game

INC = game.h

#SRCS = $(filter-out game.cpp, $(wildcard *.cpp))
SRCS = $(filter-out game.cpp, $(wildcard */*.cpp))

#SUBDIRS = $(wildcard */.)

OUT = $(SRCS:%.cpp=%)

PLAYERS = $(SRCS:%.cpp=%.player)

PLAYERSFCL = $(notdir $(PLAYERS))

CXXFLAGS = -std=c++17 -O3# -Werror -Wextra -Wall

all: $(PLAYERS)

$(PLAYERS): $(OUT)
	mv $(@:%.player=%) $@
	mv $@ $(notdir $@)

$(NAME).o: $(INC)

$(OUT): $(NAME).o

clean:
	@rm -f $(NAME).o

love:
	@echo "not war"

fclean: clean
	@rm -f $(PLAYERSFCL)

re: fclean all

.PHONY: all clean fclean re
