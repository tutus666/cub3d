/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataverni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:48:47 by ataverni          #+#    #+#             */
/*   Updated: 2022/03/21 15:49:10 by ataverni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

void	ft_free(void *content)
{
	if (content)
	{
		free(content);
		content = NULL;
	}
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = -1;
	if (tab)
	{
		while (tab[++i])
			;
		while (i >= 0)
		{
			ft_free(tab[i]);
			tab[i--] = NULL;
		}
		ft_free(tab);
		tab = NULL;
	}
}
