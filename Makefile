# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kachiote <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/03 14:53:22 by kachiote          #+#    #+#              #
#    Updated: 2020/11/07 16:51:15 by Ruslan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = g++

ALGOFOLDER = algos

NAME = Application

SRCS = map \
	   players

GRSRCS = graphics

GRHEADERS = $(patsubst %, %.h, $(GRSRCS))

GROBJ = $(patsubst %, %.o, $(GRSRCS))

HEADERS = $(patsubst %, %.h, $(SRCS))

INC = gaem.h

OBJS = $(patsubst %, %.o, $(SRCS))

CXXFILES = $(patsubst %, %.cpp, $(SRCS))

CXXFLAGS = -std=c++17 -O3

LDFLAGS="-L/usr/local/opt/freetype/lib"

#LENUX = -lGL -lGLU -lglfw -lX11 -lXrandr -lpthread -ldl -lstdc++fs
FRAMEWORKS = -lglfw -lglew -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo -framework GLUT

$(NAME): $(OBJS) $(NAME).o $(GROBJ)
	@make --ignore-errors -C $(ALGOFOLDER)
	$(CXX) $(NAME).o $(OBJS) $(GROBJ) $(CXXFLAGS) $(FRAMEWORKS) -o $(NAME)

$(NAME).o: $(INC)
	$(CXX) $(CXXFLAGS) $(NAME).cpp -c

$(OBJS): $(HEADERS)

$(GROBJ): $(GRHEADERS)
	$(CXX) $(LENUX) $(CXXFLAGS) $(@:%.o=%.cpp) -c

$(NAME).cpp: $(INC)

all: $(NAME)

clean:
	@make --ignore-errors -C $(ALGOFOLDER) clean
	@rm -f $(OBJS) $(NAME).o $(GROBJ)

love:
	@echo "not war"

fclean: clean
	@make --ignore-errors -C $(ALGOFOLDER) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
