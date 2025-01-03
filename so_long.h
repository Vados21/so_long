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
    mlx_image_t *victory; // Изображение победы
    char        **map;
    int          player_x;
    int          player_y;
    int          collectibles;
    int          moves;
    int          key_pressed;
    int          game_won; // Флаг победы
} t_game;






//map validation
void validate_map(t_game *game, char **map);

int is_rectangular(char **map);
int is_surrounded_by_walls(char **map);
void count_objects(char **map, int *player, int *exit, int *collectibles);
 

//read map
char **read_map(const char *file_path);
void error_exit(t_game *game, const char *message);  
void render_map(t_game *game);
void load_textures(t_game *game);
void game_loop(void *param);
int count_collectibles(char **map);
void move_player(t_game *game);

//free memory
void free_map(char **map);
void free_resources(t_game *game);


#endif
