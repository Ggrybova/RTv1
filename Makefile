# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/16 15:42:13 by ggrybova          #+#    #+#              #
#    Updated: 2017/10/28 18:42:11 by ggrybova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

SRC = main.c color.c read_input.c read_input2.c vector_algebra1.c \
	vector_algebra2.c vector_algebra3.c vector_algebra4.c \
    sphere.c cylinder.c cone.c plane.c\
    intersection.c shadow.c hook.c
INC = -I rtv1.h -I minilibx_macos/mlx.h

OBJ = $(SRC:.c=.o)

LIBOBJ = make -C libft/

CFLAGS = -c -Wall -Werror -Wextra
MLXFLAGS = -framework OpenGL -framework AppKit

LIBINC = -L./libft -lft minilibx_macos/libmlx.a

LIB = libft/libft.a

all: $(NAME)

obj: $(OBJ)

$(NAME) : $(LIB) $(OBJ)
	gcc $(OBJ) $(LIBINC) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	gcc $(CFLAGS) -o $@ $<

clean:
	make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all

$(LIB):
	make -j4 -C libft/ all
