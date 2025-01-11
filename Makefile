# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/11 14:07:37 by vshpilev          #+#    #+#              #
#    Updated: 2025/01/11 14:07:41 by vshpilev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

MLX_PATH = ./MLX42
MLX_LIB = $(MLX_PATH)/build/libmlx42.a
MLX_INC = $(MLX_PATH)/include

GET_NEXT_PATH = ./get_next_line
GET_NEXT_SRCS = $(GET_NEXT_PATH)/get_next_line.c $(GET_NEXT_PATH)/get_next_line_utils.c
GET_NEXT_OBJS = $(GET_NEXT_SRCS:.c=.o)

LIBFT_PATH = ./libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a

SRCS = main.c \
       logic/read_map.c \
       logic/map_validation.c \
       logic/map_validation_2.c \
       logic/render_map.c \
       logic/move_player.c \
       logic/utils.c \
       logic/free_memory.c

INCLUDES = -I$(MLX_INC) -I$(LIBFT_PATH) -I$(GET_NEXT_PATH)

OBJS = $(SRCS:.c=.o) $(GET_NEXT_OBJS) $(LIBFT_LIB)

LIBS = -L$(LIBFT_PATH) -lft -L$(PRINTF_PATH) -lftprintf -L$(MLX_PATH) -lmlx42 -lglfw -ldl -pthread -lm

all: $(LIBFT_LIB) $(PRINTF_LIB) $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_PATH)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)


$(GET_NEXT_OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS) $(GET_NEXT_OBJS)
	$(MAKE) clean -C $(LIBFT_PATH)
	
fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re
