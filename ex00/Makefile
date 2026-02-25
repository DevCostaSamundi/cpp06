# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csamundi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/11 10:03:08 by csamundi          #+#    #+#              #
#    Updated: 2026/02/11 10:03:46 by csamundi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ScalarConverter
CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

FILES = main.cpp \
	ScalarConverter.cpp

HEADERS = ScalarConverter.hpp

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
