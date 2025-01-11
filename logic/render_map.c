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

static void	render_tile(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map[y][x];
	if (tile == '1')
		mlx_image_to_window(game->mlx, game->wall, x * 64, y * 64);
	else if (tile == '0')
		mlx_image_to_window(game->mlx, game->floor, x * 64, y * 64);
	else if (tile == 'P')
	{
		mlx_image_to_window(game->mlx, game->player, x * 64, y * 64);
		game->player_x = x;
		game->player_y = y;
	}
	else if (tile == 'C')
		mlx_image_to_window(game->mlx, game->collectible, x * 64, y * 64);
	else if (tile == 'E')
		mlx_image_to_window(game->mlx, game->exit, x * 64, y * 64);
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
}

void	load_textures(t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("textures/wall.png");
	game->wall = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("textures/floor.png");
	game->floor = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("textures/dog.png");
	game->player = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("textures/pizza.png");
	game->collectible = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("textures/exit.png");
	game->exit = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("textures/victory.png");
	game->victory = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	if (!game->wall || !game->floor || !game->player
		|| !game->collectible || !game->exit || !game->victory)
		error_exit(game, "Failed to load textures");
}
