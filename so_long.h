/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:20:21 by vshpilev          #+#    #+#             */
/*   Updated: 2024/11/26 17:20:28 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
// Включение библиотек
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include </home/vshpilev/Documents/so_long/MLX42/include/MLX42/MLX42.h>

// Макросы для управления
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define TILE_SIZE 64

typedef struct s_game {
    mlx_t       *mlx;
    mlx_image_t *wall;
    mlx_image_t *floor;
    mlx_image_t *player;
    mlx_image_t *collectible;
    mlx_image_t *exit;
    char        **map;
    int          player_x;
    int          player_y;
    int          collectibles;
    int          key_pressed; // Флаг для блокировки движения
} t_game;




//map validation
int validate_map_elements(char **map, int rows, int cols);
int is_map_closed(char **map, int rows, int cols);
void free_map(char **map, int rows);

//read map
char **read_map(const char *file_path);
void error_exit(const char *message);
void validate_map(char **map);
void render_map(t_game *game);
void load_textures(t_game *game);
void game_loop(void *param);
int count_collectibles(char **map);
void move_player(t_game *game);


#endif
