/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:08:12 by vshpilev          #+#    #+#             */
/*   Updated: 2024/05/22 12:08:18 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_hex_len(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	ft_put_hex(unsigned int num, const char format)
{
	int	ret_value;

	if (num >= 16)
	{
		ret_value = ft_put_hex(num / 16, format);
		if (ret_value < 0)
			return (-1);
		ret_value = ft_put_hex(num % 16, format);
		return (1);
	}
	if (num <= 9)
		ret_value = ft_print_char(num + '0');
	else
	{
		if (format == 'x')
			ret_value = ft_print_char(num - 10 + 'a');
		else if (format == 'X')
			ret_value = ft_print_char(num - 10 + 'A');
		else
			ret_value = 0;
	}
	if (ret_value < 0)
		return (-1);
	return (1);
}

int	ft_print_hex(unsigned int num, const char format)
{
	int	len;

	if (num == 0)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		return (1);
	}
	else
	{
		if (ft_put_hex(num, format) < 0)
			return (-1);
	}
	len = ft_hex_len(num);
	return (len);
}
