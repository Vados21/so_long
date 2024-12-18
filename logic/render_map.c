/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:54:03 by vshpilev          #+#    #+#             */
/*   Updated: 2024/12/18 15:54:05 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

// Загрузка изображений и их привязка к символам карты
void render_map(t_game *game)
{
    int y = 0;
    int x;

    while (game->map[y]) // Проходим по строкам карты
    {
        x = 0;
        while (game->map[y][x]) // Проходим по каждому символу в строке
        {
            if (game->map[y][x] == '1') // Стена
                mlx_image_to_window(game->mlx, game->wall, x * 64, y * 64);
            else if (game->map[y][x] == '0') // Пустое пространство
                mlx_image_to_window(game->mlx, game->floor, x * 64, y * 64);
            else if (game->map[y][x] == 'P') // Игрок
            {
                mlx_image_to_window(game->mlx, game->player, x * 64, y * 64);
                game->player_x = x;
                game->player_y = y;
            }
            else if (game->map[y][x] == 'C') // Коллекция
                mlx_image_to_window(game->mlx, game->collectible, x * 64, y * 64);
            else if (game->map[y][x] == 'E') // Выход
                mlx_image_to_window(game->mlx, game->exit, x * 64, y * 64);
            x++;
        }
        y++;
    }
}

void load_textures(t_game *game)
{
    game->wall = mlx_texture_to_image(game->mlx, mlx_load_png("textures/wall.png"));
    game->floor = mlx_texture_to_image(game->mlx, mlx_load_png("textures/floor.png"));
    game->player = mlx_texture_to_image(game->mlx, mlx_load_png("textures/dog.png"));
    game->collectible = mlx_texture_to_image(game->mlx, mlx_load_png("textures/pizza.png"));
    game->exit = mlx_texture_to_image(game->mlx, mlx_load_png("textures/exit.png"));

    if (!game->wall || !game->floor || !game->player || !game->collectible || !game->exit)
        error_exit("Failed to load textures");
}
