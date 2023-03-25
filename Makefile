#----------------------------------------------

NOCOL = \e[0m
GREEN = \e[1;92m
RED = \e[1;31m
CYAN = \e[1;36m
TCOL = $(CYAN)
RMD = $(GREEN)successfully $(RED)removed$(NOCOL)
CMP = $(GREEN)successfully compiled$(NOCOL)

#----------------------------------------------

CC = cc

NAME = guess_n

LIBFT = Libft/libft.a

SRC = src/main.c \
	src/game.c \
	src/rules.c \
	src/options.c \
	src/range.c \
	src/att_limit.c \
	src/err_check.c

FLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): libcomp
		$(CC) $(FLAGS) $(SRC) $(LIBFT) -o $(NAME)
		echo "$(TCOL)$(NAME) $(CMP)"

libcomp:
		@make -C Libft	

libclean:
		@make clean -C Libft

clean:		libclean

libfclean:
		@make fclean -C Libft

fclean:   	libfclean
		if [ -f $(NAME) ]; then\
			rm -rf $(NAME);\
			echo "$(TCOL)$(NAME) $(RMD)";\
		fi

re: fclean all

.PHONY: all re clean fclean

.SILENT: