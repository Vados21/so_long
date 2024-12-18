/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:06:17 by vshpilev          #+#    #+#             */
/*   Updated: 2024/05/08 12:06:20 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char *s1, char *set)
{
	int		i;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, (s1[i])) && i <= end)
		i++;
	if (i > end)
		return (ft_strdup(s1 + end + 1));
	while (ft_strchr(set, s1[end]) && end >= 0)
		end--;
	str = malloc(end - i + 2);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[i], end - i + 2);
	return (str);
}
