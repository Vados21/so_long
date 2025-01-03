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

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_textures_and_mlx(t_game *game)
{
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
	if (game->mlx)
		mlx_terminate(game->mlx);
}

void	free_resources(t_game *game)
{
	free_map(game->map);
	free_textures_and_mlx(game);
}
