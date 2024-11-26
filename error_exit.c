/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:19:07 by vshpilev          #+#    #+#             */
/*   Updated: 2024/11/26 17:19:09 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

void error_exit(const char *message)
 {
    if (message)
        fprintf(stderr, "Error\n%s\n", message);
    exit(EXIT_FAILURE);
}
