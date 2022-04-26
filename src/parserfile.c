/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parserfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataverni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:59:04 by ataverni          #+#    #+#             */
/*   Updated: 2022/03/21 16:01:07 by ataverni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

int	ft_parseur_extension(char *path)
{
	int	i;

	i = -1;
	while (path[++i])
	{
		if (path[i] == '.')
			if (path[i + 1] && path[i + 1] == 'c')
				if (path[i + 2] && path[i + 2] == 'u')
					if (path[i + 3] && path[i + 3] == 'b')
						if (!path[i + 4])
							return (1);
	}
	return (0);
}

void	ft_tryopen(char *PATH, t_data *env)
{
	env->fd = open (PATH, O_DIRECTORY);
	if (env->fd > 0)
	{
		close(env->fd);
		ft_exit_error("Error\n this is a directory not a file\n");
	}
	env->fd = open(PATH, O_RDONLY);
	if (env->fd < 0)
	{
		close(env->fd);
		ft_exit_error("Error\n Invalid Path\n");
	}
}
