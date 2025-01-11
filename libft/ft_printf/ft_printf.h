/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:07:17 by vshpilev          #+#    #+#             */
/*   Updated: 2024/05/21 15:07:18 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft.h"

int		ft_printf(const char *format, ...);
int		ft_type(va_list args, const char format);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_pointer(unsigned long long ptr);
int		ft_print_nbr(int nbr);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int num, const char format);
int		ft_print_percent(void);

#endif

