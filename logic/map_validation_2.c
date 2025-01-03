/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:23:38 by vshpilev          #+#    #+#             */
/*   Updated: 2024/12/23 14:23:48 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

static	char	**copy_map(char **map)
{
	int		i;
	int		height;
	char	**copy;

	i = 0;
	height = 0;
	while (map[height])
		height++;
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		error_exit(NULL, "Error: Memory allocation failed.");
	while (i < height)
	{
		copy[i] = strdup(map[i]);
		if (!copy[i])
			error_exit(NULL, "Error: Memory allocation failed.");
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

static int	are_all_objects_reachable(char **map, int start_x, int start_y)
{
	char	**map_copy;
	int		i;
	int		j;

	i = 0;
	map_copy = copy_map(map);
	flood_fill(map_copy, start_x, start_y);
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == 'C' || map_copy[i][j] == 'E')
			{
				free_map(map_copy);
				return (0);
			}
			j++;
		}
		i++;
	}
	free_map(map_copy);
	return (1);
}

static void	find_player(char **map, int *start_x, int *start_y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*start_x = j;
				*start_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
	error_exit(NULL, "Error: Player position not found.");
}

void	validate_map(t_game *game, char **map)
{
	int	player;
	int	exit;
	int	collectibles;
	int	start_x;
	int	start_y;

	player = 0;
	exit = 0;
	collectibles = 0;
	start_x = 0;
	start_y = 0;
	if (!is_rectangular(map))
		error_exit(game, "Error: The map is not rectangular.");
	if (!is_surrounded_by_walls(map))
		error_exit(game, "Error: The map is not surrounded by walls.");
	count_objects(map, &player, &exit, &collectibles);
	if (player != 1)
		error_exit(game, "Error: There must be exactly one player (P).");
	if (exit != 1)
		error_exit(game, "Error: There must be exactly one exit (E).");
	if (collectibles < 1)
		error_exit(game, "Error: There must be at least one collectible (C).");
	game->collectibles = collectibles;
	find_player(map, &start_x, &start_y);
	if (!are_all_objects_reachable(map, start_x, start_y))
		error_exit(game, "Error: Not all coins and exits are reachable.");
}
