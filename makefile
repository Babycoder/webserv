SRC=main.cpp utils.cpp parser.cpp server_parser.cpp

FLAGS=-Wall -Wextra -Werror -std=c++98

NAME=webserv

$(NAME):
	g++ $(FLAGS) $(SRC) -o $(NAME)

all: $(NAME)

re: fclean all

clean:
	rm -rf $(NAME)

fclean: clean
