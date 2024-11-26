/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:19:17 by vshpilev          #+#    #+#             */
/*   Updated: 2024/11/26 17:19:21 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_resources(t_game *game) {
    if (game->mlx)
        mlx_terminate(game->mlx); // Завершение работы MLX42
}
