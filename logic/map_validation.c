/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:53:51 by vshpilev          #+#    #+#             */
/*   Updated: 2024/12/18 14:53:53 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	is_rectangular(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!map || !map[0])
		return (0);
	len = strlen(map[0]);
	while (map[i])
	{
		if ((int)strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	is_surrounded_by_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[0][i])
		if (map[0][i++] != '1')
			return (0);
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][strlen(map[i]) - 1] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (map[i - 1][j])
		if (map[i - 1][j++] != '1')
			return (0);
	return (1);
}

void	count_objects(char **map, int *player, int *exit, int *collectibles)
{
	int	i;
	int	j;

	*player = 0;
	*exit = 0;
	*collectibles = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				(*player)++;
			else if (map[i][j] == 'E')
				(*exit)++;
			else if (map[i][j] == 'C')
				(*collectibles)++;
			j++;
		}
		i++;
	}
}

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

void	validate_unknown_symbols(t_game *game, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != 'C' && map[y][x] != 'E' && map[y][x] != 'P' &&
				map[y][x] != '0' && map[y][x] != '1')
			{
				error_exit(game, "unknown symbol on the map");
			}
			x++;
		}
		y++;
	}
}
