/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:07:50 by vshpilev          #+#    #+#             */
/*   Updated: 2024/12/18 17:07:52 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int count_collectibles(char **map)
{
    int y = 0;
    int x;
    int count = 0;

    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'C')
                count++;
            x++;
        }
        y++;
    }
    return (count);
}
