# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 14:36:43 by abettini          #+#    #+#              #
#    Updated: 2023/03/12 14:14:19 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

NAME = libft.a

PT1 :=	part_1/ft_atoi.c \
	part_1/ft_bzero.c \
	part_1/ft_calloc.c \
	part_1/ft_isalnum.c \
	part_1/ft_isalpha.c \
	part_1/ft_isascii.c \
	part_1/ft_isdigit.c \
	part_1/ft_isprint.c \
	part_1/ft_memchr.c \
	part_1/ft_memcmp.c \
	part_1/ft_memcpy.c \
	part_1/ft_memmove.c \
	part_1/ft_memset.c \
	part_1/ft_strchr.c \
	part_1/ft_strdup.c \
	part_1/ft_strlcat.c \
	part_1/ft_strlcpy.c \
	part_1/ft_strlen.c \
	part_1/ft_strncmp.c \
	part_1/ft_strnstr.c \
	part_1/ft_strrchr.c \
	part_1/ft_tolower.c \
	part_1/ft_toupper.c

PT2 :=	part_2/ft_itoa.c \
	part_2/ft_putchar_fd.c \
	part_2/ft_putendl_fd.c \
	part_2/ft_putnbr_fd.c \
	part_2/ft_putstr_fd.c \
	part_2/ft_split.c \
	part_2/ft_striteri.c \
	part_2/ft_strjoin.c \
	part_2/ft_strmapi.c \
	part_2/ft_strtrim.c \
	part_2/ft_substr.c

BNS :=	bonus/ft_lstadd_back.c \
	bonus/ft_lstadd_front.c \
	bonus/ft_lstclear.c \
	bonus/ft_lstdelone.c \
	bonus/ft_lstiter.c \
	bonus/ft_lstlast.c \
	bonus/ft_lstmap.c \
	bonus/ft_lstnew.c \
	bonus/ft_lstsize.c
	
PTF :=	ft_printf/ft_printf.c \
	ft_printf/ft_print_chr.c \
	ft_printf/ft_print_str.c \
	ft_printf/ft_print_dec.c \
	ft_printf/ft_print_uns.c \
	ft_printf/ft_print_hex.c \
	ft_printf/ft_print_ptr.c

GNL :=	get_next_line/get_next_line.c

OBJ_S = $(PT1:.c=.o) $(PT2:.c=.o) $(PTF:.c=.o) $(GNL:.c=.o)

OBJ_B = $(BNS:.c=.o)

CFLAG = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(OBJ_S)
	ar -rcs $@ $^
	echo "$(TCOL)$(NAME) $(CMP)"

%.o:%.c
	$(CC) -c $(CFLAG) -I. $< -o $@

clean:
	if [ `find . -name "*.o" | wc -l` != 0 ]; then\
		/bin/rm -f part_1/*.o;\
		/bin/rm -f part_2/*.o;\
		/bin/rm -f bonus/*.o;\
		/bin/rm -f ft_printf/*.o;\
		/bin/rm -f get_next_line/*.o;\
		echo "$(TCOL)object files ($(NAME)) $(RMD)";\
	fi
	

fclean: clean
	if [ -f $(NAME) ]; then\
		/bin/rm -f $(NAME);\
		echo "$(TCOL)$(NAME) $(RMD)";\
	fi

re: fclean all

bonus: $(OBJ_B)
	ar -rcs $(NAME) $^
	echo "$(TCOL)$(NAME) w/ bonus $(CMP)"

.PHONY: all clean fclean re bonus

.SILENT: