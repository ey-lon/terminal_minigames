#----------------------------------------------

NOCOL = \e[0m
GREEN = \e[1;92m
RED = \e[1;31m
CYAN = \e[1;36m
BULE = \e[1;34m
YELL = \e[0;33m
TCOL = $(CYAN)
RMD = $(GREEN)successfully $(RED)removed$(NOCOL)
CMP = $(GREEN)successfully compiled$(NOCOL)
ALC = $(YELL)already compiled$(NOCOL)

#----------------------------------------------

CC = cc

RM = /bin/rm -f

FLAGS = -Wall -Werror -Wextra -g

NAME = terminal_minigames

#paths-----------------------------------------

LIBFT_F = Libft/
MAIN_F = main_src/
TTT_F = tictactoe/
GSN_F = guess_n/
UTS_F = utils/

#libft-----------------------------------------

LIBFT = libft.a

#main------------------------------------------

MAIN = main.c

#guess_n---------------------------------------

GSN = main.c \
	game.c \
	rules.c \
	options.c \
	set_range.c \
	set_att_limit.c \
	status_update.c

#tictactoe-------------------------------------

TTT = main.c \
	game.c \
	move.c \
	cpu.c \
	rules.c \
	options.c \
	set_grid_size.c \
	set_players_color.c \
	status_update.c \
	win_check.c \
	print_mat_ttt.c

#utils-----------------------------------------

UTS = err_check.c \
	mat_chars.c \
	mat_functions.c \
	get_n.c \
	get_min_max.c \
	get_color.c

#prefix----------------------------------------

LIBFT := $(addprefix $(LIBFT_F),$(LIBFT))
MAIN := $(addprefix $(MAIN_F),$(MAIN))
GSN := $(addprefix $(GSN_F),$(GSN))
TTT := $(addprefix $(TTT_F),$(TTT))
UTS := $(addprefix $(UTS_F),$(UTS))

SRC = $(MAIN) $(GSN) $(TTT) $(UTS)

#rules-----------------------------------------

all: $(NAME)

$(NAME): libcomp
		if [ -f $(NAME) ]; then\
			echo "$(TCOL)$(NAME) $(ALC)";\
		else\
			$(CC) $(FLAGS) $(SRC) $(LIBFT) -o $(NAME);\
			echo "$(TCOL)$(NAME) $(CMP)";\
		fi

libcomp:
		@make -C $(LIBFT_F)

libclean:
		@make clean -C $(LIBFT_F)

clean:		libclean

libfclean:
		@make fclean -C $(LIBFT_F)

fclean:   	libfclean
		if [ -f $(NAME) ]; then\
			$(RM) $(NAME);\
			echo "$(TCOL)$(NAME) $(RMD)";\
		fi

re: fclean all

.PHONY: $(NAME) all re clean fclean

.SILENT: