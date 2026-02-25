# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csamundi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/11 20:54:48 by csamundi          #+#    #+#              #
#    Updated: 2026/02/11 20:56:00 by csamundi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Base
CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

FILES = Base.cpp \
	main.cpp

HEADERS = Base.hpp

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
