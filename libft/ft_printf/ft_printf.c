/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:02:47 by vshpilev          #+#    #+#             */
/*   Updated: 2024/05/22 12:02:50 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_type(va_list args, char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len = ft_print_char((char)va_arg(args, int));
	else if (format == 's')
		len = ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		len = ft_print_pointer(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		len = ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		len = ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		len = ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		len = ft_print_percent();
	else
		return (-1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;
	int		temp_len;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			temp_len = ft_type(args, str[++i]);
		else
			temp_len = ft_print_char(str[i]);
		if (temp_len < 0)
		{
			va_end(args);
			return (-1);
		}
		print_length += temp_len;
		i++;
	}
	va_end(args);
	return (print_length);
}
