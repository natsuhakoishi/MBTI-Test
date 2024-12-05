NAME = mbti
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = mbti.c gnl.c gnl_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(SRC) $(CFLAGS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
