/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataverni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:57:42 by ataverni          #+#    #+#             */
/*   Updated: 2021/04/14 11:37:57 by ataverni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{	
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{	
		i++;
		lst = lst->next;
	}
	return (i);
}