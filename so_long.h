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

// Включение библиотек
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include </home/vshpilev/Documents/so_long/MLX42/include/MLX42/MLX42.h>

// Макросы для управления
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define TILE_SIZE 64

// Структуры данных
typedef struct s_game {
    mlx_t       *mlx;       // Основной объект MLX42
    mlx_image_t *player;    // Изображение игрока
    mlx_image_t *map;       // Изображение карты
    int          player_x;  // Координата игрока X
    int          player_y;  // Координата игрока Y
    char         **map_data; // Данные карты
}               t_game;

// Функции для управления игрой
void    init_game(t_game *game);
//void    load_map(t_game *game, const char *file_path);
//void    render_map(t_game *game);
//void    handle_input(t_game *game, int key);

// Вспомогательные функции
void    error_exit(const char *message);
void    free_resources(t_game *game);

#endif
