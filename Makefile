# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mxaba <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/20 10:40:54 by mxaba             #+#    #+#              #
#    Updated: 2018/08/27 14:09:20 by mxaba            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	ft_ls

SRC		 =	main.c aff_l.c sort_file.c command_list.c dir_cpy.c\
			file_list.c ft_ls.c other_command.c parsing.c read_a_dir.c rec_ls.c\
			help_menu.c time_add.c aff_l_second.c check_and_sort.c sort_dir.c display_ls.c\
			size_and_link.c path_name.c color.c

OBJ		=	$(SRC:.c=.o)

GCCF 	= 	-Wall -Werror -Wextra

all		:	$(NAME)

$(NAME)	: 	$(OBJ) 
			make -C libft
			gcc -o $(NAME) $(OBJ) -L libft -lft

%.o: %.c libft/libft.h
			gcc -c -I libft $< -o $@

.PHONY	:	clean fclean re

clean:
			make -C libft fclean
			@rm -rf $(OBJ)

fclean	: 	clean
			@rm -rf $(NAME)

re		: 	fclean all
