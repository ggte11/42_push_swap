# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/18 16:08:39 by mcardoso          #+#    #+#              #
#    Updated: 2025/07/09 19:17:36 by mcardoso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# compiler e flags
CC = cc
FLAGS = -g -Wall -Wextra -Werror

# apagar ficheiros e cria ficheiros .a
RM = rm -f
LIB = ar -rcs

SRCS =  push_swap.c parsing_utils.c utils.c list_utils.c stack_a.c \
		stack_b.c stack_both.c sorting_utils.c sorting_utils2.c sorting_b.c

# trasforma .c para .o
OBJS = $(SRCS:.c=.o)

all: ${NAME}

# o touch cria um ficheiro para o make saber que ja foi adicionado
${NAME}: ${OBJS}
		${CC} ${FLAGS} ${OBJS} -o ${NAME}
		@echo "Executable created"

# compila qualquer .c em .o ($< ficheiro de entrada .c, $@ de saida)
%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

# remove os .o
clean:
	@$(RM) $(OBJS)
	echo "Cleaned up Objs"

# fclean remove tudo incluindo o push_swap.a
fclean: clean
	@$(RM) $(NAME)
	@echo "ALL Cleaned, $(NAME) Removed"

# make re: limpa tudo e recompila
re: fclean all

#estas palavras sao tratadas como comandos e nao ficheiros
.PHONY: all clean fclean re