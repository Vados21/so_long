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

static int is_rectangular(char **map)
{
    int i = 0;
    int len = 0;

    if (!map || !map[0])
        return (0);
    len = strlen(map[0]); // Длина первой строки
    while (map[i])
    {
        if ((int)strlen(map[i]) != len)
            return (0);
        i++;
    }
    return (1);
}

static int is_surrounded_by_walls(char **map)
{
    int i = 0;
    int j;

    while (map[0][i]) // Проверка верхней строки
        if (map[0][i++] != '1')
            return (0);

    i = 0;
    while (map[i]) // Проверка левой и правой границ
    {
        if (map[i][0] != '1' || map[i][strlen(map[i]) - 1] != '1')
            return (0);
        i++;
    }

    j = 0;
    while (map[i - 1][j]) // Проверка нижней строки
        if (map[i - 1][j++] != '1')
            return (0);

    return (1);
}

static void count_objects(char **map, int *player, int *exit, int *collectibles)
{
    int i = 0;
    int j;

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

void validate_map(char **map)
{
    int player = 0;
    int exit = 0;
    int collectibles = 0;

    if (!is_rectangular(map))
        error_exit("Error: The map is not rectangular.");
    if (!is_surrounded_by_walls(map))
        error_exit("Error: The map is not surrounded by walls.");
    count_objects(map, &player, &exit, &collectibles);
    if (player != 1)
        error_exit("Error: There must be exactly one player (P).");
    if (exit < 1)
        error_exit("Error: There must be at least one exit (E).");
    if (collectibles < 1)
        error_exit("Error: There must be at least one collectible (C).");
}

