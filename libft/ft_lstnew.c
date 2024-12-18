/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:46:53 by vshpilev          #+#    #+#             */
/*   Updated: 2024/05/13 13:46:55 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list
	*ft_lstnew(void *content)
{
	t_list	*my_list;

	my_list = (t_list *)malloc(sizeof(*my_list));
	if (!my_list)
		return (NULL);
	my_list->content = content;
	my_list->next = NULL;
	return (my_list);
}
