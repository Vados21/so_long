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
#include "so_long.h"

void	game_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->game_won)
	{
		if (game->delay++ > 180)
		{
			mlx_close_window(game->mlx);
		}
		return ;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(game->mlx);
		return ;
	}
	move_player(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.delay = 0;
	memset(&game, 0, sizeof(t_game));
	if (argc != 2)
		error_exit(NULL, "Usage: ./so_long <map_file>");
	game.mlx = mlx_init(1600, 1200, "so_long", true);
	if (!game.mlx)
		error_exit(&game, "Failed to initialize MLX");
	game.map = read_map(argv[1]);
	validate_map(&game, game.map);
	ft_printf("Players: %d, Exits: %d, Collectibles: %d\n",
		1, 1, game.collectibles);
	load_textures(&game);
	render_map(&game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	free_resources(&game);
	return (0);
}
