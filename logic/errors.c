/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:38:50 by vshpilev          #+#    #+#             */
/*   Updated: 2024/12/18 14:38:53 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	error_exit(t_game *game, const char *message)
{
	if (message)
		printf("Error\n%s\n", message);
	if (game)
		free_resources(game);
	exit(EXIT_FAILURE);
}
