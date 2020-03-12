# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anikkane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 10:36:26 by anikkane          #+#    #+#              #
#    Updated: 2020/02/19 10:42:33 by anikkane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol
SRCS	=	./src/main.c ./src/fractal.c
OBJS	=	./*.o
MLX	=	./minilibx/
MLX_LIB	=	$(addprefix $(MLX),mlx.a)
MLX_INC	=	-I ./minilibx
MLX_LNK	=	-L ./minilibx -l mlx -framework OpenGL -framework AppKit
HDR	=	./sources/
LIBFT	=	libft/
FLAGS	=	-Wall -Werror -Wextra
all: $(NAME)
$(NAME):
	make -C $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $(MLX_INC) $(MLX_LNK) $(SRCS) -I $(HDR) -L. libft/libft.a
	gcc $(FLAGS) -I ./ -c $(SRCS)
clean:
	/bin/rm -f $(OBJS) 
	make -C $(LIBFT) clean
fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean
re: fclean all
