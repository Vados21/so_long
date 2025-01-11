/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:31:39 by vshpilev          #+#    #+#             */
/*   Updated: 2024/06/03 15:31:41 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	int		len;
	char	*num;

	num = ft_itoa(n);
	if (!num)
		return (-1);
	len = ft_print_str(num);
	free(num);
	return (len);
}
