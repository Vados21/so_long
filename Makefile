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

# Путь к библиотеке MLX42
MLX42_DIR = /home/vshpilev/Documents/so_long/MLX42
MLX42_LIB = -L$(MLX42_DIR) -lmlx42 -lglfw
MLX42_INC = -I$(MLX42_DIR)/include

# Исходные файлы и объектные файлы
SRC = main.c init_game.c free_resources.c error_exit.c
OBJ = $(SRC:.c=.o)

# Правило для сборки
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX42_LIB) $(MLX42_INC) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка объектных файлов
clean:
	rm -f $(OBJ)

# Полная очистка (включая исполняемый файл)
fclean: clean
	rm -f $(NAME)

# Пересборка
re: fclean all
