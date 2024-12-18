# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 17:31:33 by vshpilev          #+#    #+#              #
#    Updated: 2024/11/26 17:31:35 by vshpilev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# Имя исполняемого файла
NAME = so_long

# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Пути
MLX_PATH = ./MLX42
MLX_LIB = $(MLX_PATH)/build/libmlx42.a
MLX_INC = $(MLX_PATH)/include

GET_NEXT_PATH = ./get_next_line
GET_NEXT_SRCS = $(GET_NEXT_PATH)/get_next_line.c $(GET_NEXT_PATH)/get_next_line_utils.c
GET_NEXT_OBJS = $(GET_NEXT_SRCS:.c=.o)

LIBFT_PATH = ./libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a

# Исходные файлы
SRCS = main.c \
       logic/read_map.c \
       logic/map_validation.c \
       logic/errors.c \
       logic/render_map.c \
       logic/move_player.c \
       logic/utils.c	\


# Заголовочные файлы
INCLUDES = -I$(MLX_INC) -I$(LIBFT_PATH) -I$(GET_NEXT_PATH)

# Объектные файлы
OBJS = $(SRCS:.c=.o) $(GET_NEXT_OBJS)

# Библиотеки
LIBS = -L$(MLX_PATH) -lmlx42 -lglfw -ldl -pthread -lm $(LIBFT_LIB)

# Основное правило
all: $(LIBFT_LIB) $(NAME)

# Сборка so_long
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

# Правило для компиляции object-файлов get_next_line
$(GET_NEXT_OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

# Сборка libft
$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_PATH)

# Очистка объектных файлов
clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_PATH)

# Полная очистка
fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_PATH)

# Пересборка
re: fclean all
