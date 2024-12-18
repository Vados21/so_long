/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:00:14 by vshpilev          #+#    #+#             */
/*   Updated: 2024/05/07 16:00:17 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(const char *stash, const char *buf)
{
	char	*res;
	int		i;
	int		j;
	size_t	len;

	if (!stash && !buf)
		return (NULL);
	len = ft_strlen(stash) + ft_strlen(buf);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (stash && stash[i] != 0)
	{
		res[i] = stash[i];
		i++;
	}
	j = 0;
	while (buf && buf[j] != 0)
		res[i++] = buf[j++];
	res[len] = '\0';
	return (res);
}
