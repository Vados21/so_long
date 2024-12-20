/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:19:59 by vshpilev          #+#    #+#             */
/*   Updated: 2024/11/26 17:20:01 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include </home/vshpilev/Documents/so_long/MLX42/include/MLX42/MLX42.h>
#include "so_long.h"

void game_loop(void *param)
{
    t_game *game = (t_game *)param;

    // Если игра завершена, ждём 3 секунды и закрываем окно
    if (game->game_won)
    {
        static int delay = 0;
        if (delay++ > 180) // Примерно 3 секунды при 60 FPS
        {
            mlx_close_window(game->mlx);
        }
        return;
    }

    // Закрытие окна при нажатии ESC
    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
    {
        mlx_close_window(game->mlx);
        return;
    }

    // Обработка движения игрока
    move_player(game);
}


int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
        error_exit("Usage: ./so_long <map_file>");

    // Инициализация структуры
    game.mlx = NULL;
    game.map = NULL;
    game.wall = NULL;
    game.floor = NULL;
    game.player = NULL;
    game.collectible = NULL;
    game.exit = NULL;
    game.victory = NULL;
    game.collectibles = 0;
    game.moves = 0;

    // Инициализация MLX
    game.mlx = mlx_init(1600, 1200, "so_long", true);
    if (!game.mlx)
        error_exit("Failed to initialize MLX");

    // Чтение карты
    game.map = read_map(argv[1]);
    validate_map(game.map);

    // Инициализация игры
    game.collectibles = count_collectibles(game.map);
    load_textures(&game);
    render_map(&game);

    // Установка игрового цикла
    mlx_loop_hook(game.mlx, game_loop, &game);

    // Запуск цикла MLX
    mlx_loop(game.mlx);

    // Очистка ресурсов перед завершением программы
    free_resources(&game);

    return (0);
}


