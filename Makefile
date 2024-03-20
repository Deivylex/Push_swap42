# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzurita <dzurita@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 14:48:05 by dzurita           #+#    #+#              #
#    Updated: 2024/01/30 14:48:07 by dzurita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------Archive-------------------------------------#
NAME = push_swap
LIBFTNAME = libft.a

#---------------------------------Flags---------------------------------------#
CC = @cc
CFLAGS = -Wall -Wextra -Werror
RM = @rm -rf

#---------------------------------Directories---------------------------------#
LIBFT_DIR = ./libft

#---------------------------------Source Files--------------------------------#
SRC_FLS = basic_sort.c check_errors.c fill_stack.c ft_free_memori.c\
		  ft_instructions.c ft_rules.c push_swap.c sort_final_step.c\
		  sort_stack_utils.c sort_stack.c

#---------------------------------Colours-------------------------------------#
GREEN= \033[1;32m
CYAN= \033[1;36m
RED=\033[0;31m
END= \033[0m

#---------------------------------Rules---------------------------------------#
all: $(NAME)

OBJS = $(SRC_FLS:.c=.o)

$(NAME): $(OBJS)
	@echo "${RED}Compiling Libft${END}"
	@echo "${RED}Compiling Push_Swap${END}"
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/$(LIBFTNAME) -o $@ 
	@echo "${GREEN}Push_Swap Compiled Successfully${END}"

clean:
	$(RM) $(OBJS) $(OBJ_DIR)
	@make clean -C libft/
	@echo "${GREEN}Push_Swap Cleaned${END}"

fclean: clean
	$(RM) $(NAME)
	@rm -f libft/${LIBFTNAME}

re: fclean all

.PHONY: all clean fclean re