/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:08:55 by vshpilev          #+#    #+#             */
/*   Updated: 2024/05/22 12:08:56 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_put_ptr(unsigned long long num)
{
	int	ret_value;
	int	total_len;

	total_len = 0;
	if (num >= 16)
	{
		ret_value = ft_put_ptr(num / 16);
		total_len += ret_value;
		ret_value = ft_put_ptr(num % 16);
		if (ret_value < 0)
			return (-1);
		total_len += ret_value;
	}
	else
	{
		if (num <= 9)
			ret_value = ft_print_char(num + '0');
		else
			ret_value = ft_print_char(num - 10 + 'a');
		if (ret_value < 0)
			return (-1);
		total_len += ret_value;
	}
	return (total_len);
}

int	ft_print_pointer(unsigned long long ptr)
{
	int	print_length;
	int	ret_value;

	print_length = write(1, "0x", 2);
	if (print_length < 0)
		return (-1);
	if (ptr == 0)
	{
		ret_value = write(1, "0", 1);
		if (ret_value < 0)
			return (-1);
		print_length += ret_value;
	}
	else
	{
		ret_value = ft_put_ptr(ptr);
		if (ret_value < 0)
			return (-1);
		print_length += ret_value;
	}
	return (print_length);
}
