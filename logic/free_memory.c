/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:22:11 by vshpilev          #+#    #+#             */
/*   Updated: 2024/12/20 18:22:14 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void free_map(char **map)
{
    int i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

void free_resources(t_game *game)
{
    // Освобождение карты
    if (game->map)
    {
        int i = 0;
        while (game->map[i])
        {
            free(game->map[i]);
            i++;
        }
        free(game->map);
    }

    // Освобождение текстур
    if (game->wall)
        mlx_delete_image(game->mlx, game->wall);
    if (game->floor)
        mlx_delete_image(game->mlx, game->floor);
    if (game->player)
        mlx_delete_image(game->mlx, game->player);
    if (game->collectible)
        mlx_delete_image(game->mlx, game->collectible);
    if (game->exit)
        mlx_delete_image(game->mlx, game->exit);
    if (game->victory)
        mlx_delete_image(game->mlx, game->victory);

    // Завершение работы MLX
    if (game->mlx)
        mlx_terminate(game->mlx);
}

