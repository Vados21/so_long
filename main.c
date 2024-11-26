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
#include <mlx.h>

#define WIDTH 512
#define HEIGHT 512

static mlx_image_t* image;

// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------

#include "so_long.h"

int main(void) {
    t_game game;

    // Инициализация игры
    init_game(&game);

    // Запуск цикла обработки событий
    mlx_loop(game.mlx);

    // Завершение программы (по завершении работы окна)
    free_resources(&game);
    return (0);
}

