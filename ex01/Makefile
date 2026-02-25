# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csamundi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/11 15:05:36 by csamundi          #+#    #+#              #
#    Updated: 2026/02/11 15:05:46 by csamundi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Serializer
CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

FILES = main.cpp \
	Serializer.cpp

HEADERS = Data.hpp \
	  Serializer.hpp

OBJS = $(FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
