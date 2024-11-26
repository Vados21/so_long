/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:19:47 by vshpilev          #+#    #+#             */
/*   Updated: 2024/11/26 17:19:49 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void init_game(t_game *game) {
    // Инициализация графической библиотеки MLX42
    game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "so_long", false);
    if (!game->mlx)
        error_exit("Failed to initialize MLX42");

    // Инициализация указателей
    game->player = NULL;
    game->map = NULL;
    game->map_data = NULL;

    // Инициализация начальных координат игрока
    game->player_x = -1; // Значения по умолчанию до загрузки карты
    game->player_y = -1;

    // Проверка, что карта будет корректно загружена позже
    game->map_data = NULL;

    // Проверка корректности ресурсов (например, текстур)
    // Текстура игрока
    mlx_texture_t *player_texture = mlx_load_png("textures/player.png");
    if (!player_texture)
        error_exit("Failed to load player texture");
    game->player = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
    mlx_image_to_window(game->mlx, game->player, game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);

    // Текстура карты и другие элементы инициализируются позже
    // Т.к. они зависят от карты (например, стены)

    // Вывод успешной инициализации (необязательно)
    printf("Game initialized successfully!\n");
}
