# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 12:46:56 by sycourbi          #+#    #+#              #
#    Updated: 2023/11/27 13:45:36 by sycourbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D


SRC_DIR = src/
OBJ_DIR = obj/

SRC = $(SRC_DIR)main.c $(SRC_DIR)init.c $(SRC_DIR)error.c $(SRC_DIR)creat_copy_file.c \
	$(SRC_DIR)check_arg.c $(SRC_DIR)utils.c $(SRC_DIR)creat_map.c $(SRC_DIR)text_infile.c\
	$(SRC_DIR)color_infile.c $(SRC_DIR)verif_map.c $(SRC_DIR)text_color_check.c \
	$(SRC_DIR)pos_player.c \

OBJ = $(SRC:.c=.o)

LIB = ./libft/libft.a

CC = gcc

CFLAG = -Wall -Wextra -Werror -g3

all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAG) $< -o $@ -I.
# -c sert a creer fichier objet
# -o sert a creer le fichier executable
# -I. sert a inclure les header (.h)

$(NAME): $(OBJ)
	make -C ./libft
# -C pour rajouter la direction (faire make dans le dossier libft)
	$(CC) $(CFLAG) -o $(NAME) $(OBJ) $(LIB) -I.
	
$(MLX) : 
	git clone https://github.com/42Paris/minilibx-linux.git minilibx-linux
	make -C ./minilibx-linux

clean:
	cd libft && make clean
	rm -rf $(OBJ_DIR) $(OBJ)
# -r sert a effacer recursivement les sous repertoires
# -f sert a ne pas demander de confirmation d'effacement, et ne pas renvoyer de code erreur quand le fichier n'existe pas

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
