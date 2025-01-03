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

    memset(&game, 0, sizeof(t_game)); // Обнуляем структуру

    if (argc != 2)
        error_exit(NULL, "Usage: ./so_long <map_file>");

    game.mlx = mlx_init(1600, 1200, "so_long", true);
    if (!game.mlx)
        error_exit(&game, "Failed to initialize MLX");

    game.map = read_map(argv[1]); // Читаем карту
    validate_map(&game, game.map); // Проверяем и подсчитываем объекты

    printf("Players: %d, Exits: %d, Collectibles: %d\n",
           1, 1, game.collectibles); // Отладочная печать

    load_textures(&game);
    render_map(&game);

    mlx_loop_hook(game.mlx, game_loop, &game);
    mlx_loop(game.mlx);

    free_resources(&game); // Освобождаем ресурсы
    return (0);
}






