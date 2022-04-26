/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataverni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:44:32 by ataverni          #+#    #+#             */
/*   Updated: 2021/04/14 11:33:11 by ataverni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmp2;

	if (lst && *lst && del)
	{
		tmp = *lst;
		while (tmp)
		{
			tmp2 = tmp;
			tmp = tmp->next;
			del(tmp2->content);
			free(tmp2);
		}
		*lst = NULL;
	}	
}	
