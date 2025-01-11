/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:06:31 by vshpilev          #+#    #+#             */
/*   Updated: 2024/12/18 17:06:33 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

static int	process_tile(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'C')
	{
		game->collectibles--;
		ft_printf("%d coins remaining\n", game->collectibles);
		game->map[new_y][new_x] = '0';
		mlx_image_to_window(game->mlx, game->floor, new_x * 64, new_y * 64);
		return (0);
	}
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->collectibles == 0)
		{
			game->game_won = 1;
			mlx_image_to_window(game->mlx, game->victory, 400, 300);
			ft_printf("Game won in %d moves!\n", game->moves);
			return (1);
		}
		else
		{
			ft_printf("You need to collect all collectibles first!\n");
			return (1);
		}
	}
	return (0);
}

static void	check_and_move(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == '1')
		return ;
	if (process_tile(game, new_x, new_y))
		return ;
	mlx_image_to_window(game->mlx, game->floor,
		game->player_x * 64, game->player_y * 64);
	game->player_x = new_x;
	game->player_y = new_y;
	mlx_image_to_window(game->mlx, game->player, new_x * 64, new_y * 64);
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
}

static void	handle_key_input(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		check_and_move(game, game->player_x, game->player_y - 1);
		game->key_pressed = 1;
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		check_and_move(game, game->player_x, game->player_y + 1);
		game->key_pressed = 1;
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		check_and_move(game, game->player_x - 1, game->player_y);
		game->key_pressed = 1;
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		check_and_move(game, game->player_x + 1, game->player_y);
		game->key_pressed = 1;
	}
}

static int	is_key_released(t_game *game)
{
	return (!mlx_is_key_down(game->mlx, MLX_KEY_W)
		&& !mlx_is_key_down(game->mlx, MLX_KEY_S)
		&& !mlx_is_key_down(game->mlx, MLX_KEY_A)
		&& !mlx_is_key_down(game->mlx, MLX_KEY_D));
}

void	move_player(t_game *game)
{
	if (game->key_pressed == 0)
	{
		handle_key_input(game);
	}
	else if (is_key_released(game))
	{
		game->key_pressed = 0;
	}
}
