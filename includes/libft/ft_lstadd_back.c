/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataverni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:41:18 by ataverni          #+#    #+#             */
/*   Updated: 2021/04/14 11:32:46 by ataverni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*lst;

	if (alst && *alst)
	{
		lst = *alst;
		while (lst->next)
		{
			lst = lst->next;
		}	
		lst->next = new;
	}
	else if (alst)
		*alst = new;
}
