/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsermap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataverni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:54:07 by ataverni          #+#    #+#             */
/*   Updated: 2022/03/21 15:40:17 by ataverni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

int	ft_biggest_line(char **tab)
{
	int	i;
	int	cmpt;

	i = 0;
	cmpt = -1;
	if (tab)
	{
		while (tab[++cmpt])
		{
			if (ft_strlen_map(tab[cmpt]) > i)
				i = ft_strlen_map(tab[cmpt]);
		}
	}
	return (i);
}

int	ft_handler_posjoueur(char type, t_data *env, int posx, int posy)
{
	static int	save = 0;
	printf("yo jai trouver un joueur en x : %d  y : %d \n", posx, posy);
	if (type == 'W' && save == 0)
	{
		env->player->angle = 180;
		env->player->pdx = cos(degToRad(env->player->angle));
		env->player->pdy = sin(degToRad(env->player->angle));
		printf("tu set ton angle a %f ton pdx a %f & ton pdy a %f\n", env->player->angle, env->player->pdx, env->player->pdy);
	}
	else if (type == 'N' && save == 0)
	{
		env->player->angle = 90;
		env->player->pdx = cos(degToRad(env->player->angle));
		env->player->pdy = sin(degToRad(env->player->angle));
		printf("tu set ton angle a %f ton pdx a %f & ton pdy a %f\n", env->player->angle, env->player->pdx, env->player->pdy);
	}
	else if (type == 'E' && save == 0)
	{
		env->player->angle = 0;
		env->player->pdx = cos(degToRad(env->player->angle));
		env->player->pdy = sin(degToRad(env->player->angle));
		printf("tu set ton angle a %f ton pdx a %f & ton pdy a %f\n", env->player->angle, env->player->pdx, env->player->pdy);
	}
	else if (type == 'S' && save == 0)
	{	
		env->player->angle = 270;
		env->player->pdx = cos(degToRad(env->player->angle));
		env->player->pdy = sin(degToRad(env->player->angle));
		printf("tu set ton angle a %f ton pdx a %f & ton pdy a %f\n", env->player->angle, env->player->pdx, env->player->pdy);
	}
	else
		return (0);
	if (save == 0)
	{
		env->player->x = posx;
		env->player->y = posy;
		save++;
	}
	else
		return (0);
	return (1);
}

int	ft_read_char(char **tab, t_data *env)
{
	int	i;
	int	j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] != 32 && !(tab[i][j] >= '\t' && tab[i][j] <= '\r') && \
					tab[i][j] != '1' && tab[i][j] != '0' && \
					!ft_handler_posjoueur(tab[i][j], env, i, j))
				return (0);
		}
	}
	return (1);
}

int	ft_read_line(char **tab)
{
	int	open;
	int	tmp;
	int	i;
	int	j;

	i = -1;
	open = 0;
	tmp = 0;
	while (tab[++i])
	{
		j = -1;
		if (!tab[i][0])
			return (0);
		while (tab[i][++j])
		{
			if (tab[i][j] == '1' && open == 0)
				open++;
			else if ((tab[i][j] != '1' && tab[i][j] != 32 && \
						!(tab[i][j] >= '\t' && tab[i][j] <= '\r')) && open == 0)
				return (0);
			else if (tab[i][j] == '1' && open == 1 && tmp == 0)
				tmp++;
			else if (tab[i][j] == '0' && open == 1 && tmp == 1)
				tmp--;
			else if (tab[i][j] == '0' && open == 0)
				return (0);
			else if ((tab[i][j] == 32 || (tab[i][j] >= '\t' && \
							tab[i][j] <= '\r')) && open == 1 && tmp == 0)
				return (0);
			else if ((tab[i][j] == 32 || (tab[i][j] >= '\t' && \
							tab[i][j] <= '\r')) && open == 1 && tmp == 1)
			{
				open--;
				tmp--;
			}
			else if ((tab[i][j] == 'N' || tab[i][j] == 'S' || tab[i][j] == 'O' \
						|| tab[i][j] == 'W') && open == 1 && tmp == 0)
				continue ;
			else if ((tab[i][j] == 'N' || tab[i][j] == 'S' || tab[i][j] == 'O' \
						|| tab[i][j] == 'W') && tmp == 1 && open == 1)
				tmp--;
		}
		if (open == 1 && j > 0 && tab[i][j - 1] && tab[i][j - 1] != '1')
			return (0);
	}
	return (1);
}

char	*ft_strndup_free(char *str, int size)
{
	char	*new;
	int		i;

	new = malloc(size + 1);
	if (!new)
		return (NULL);
	i = 0;
	if (str)
	{
		while (str[i])
		{
			new[i] = str[i];
			i++;
		}
		ft_free(str);
	}
	new[i] = 0;
	return (new);
}

char	*ft_prepare_for_parser(char *str, int size)
{
	char	*new;
	int		i;
	int		cmpt;

	i = 0;
	cmpt = 0;
	new = malloc(size + 2);
	if (!new)
		return (NULL);
	if (str)
	{
		while (str[i])
		{
			if (str[i] == '\t')
			{
				i++;
				new[cmpt++] = 32;
				new[cmpt++] = 32;
				new[cmpt++] = 32;
				new[cmpt++] = 32;
			}
			else
				new[cmpt++] = str[i++];
		}
	}
	while (cmpt <= size)
		new[cmpt++] = 32;
	new[cmpt] = 0;
	return (new);
}

char	**ft_preparejesus(char **tab, int sizemax, int size)
{
	int		i;
	char	**new;

	i = -1;
	if (!tab)
		return (NULL);
	new = malloc(sizeof(char *) * (sizemax + 2));
	if (!new)
		return (NULL);
	while (tab[++i])
		new[i] = ft_prepare_for_parser(tab[i], size);
	new[i] = NULL;
	ft_print_map(new);
	return (new);
}

void	ft_print_map_line(char **tab, int size, int sizemax)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < size + 1)
	{
		j = -1;
		while (++j < sizemax)
			printf("%c", tab[j][i]);
		printf(" ton j %d \n", j);
	}
	printf("ton i %d\n", i);
}

int	ft_read_colum(t_data *env, char **tab, int size, int sizemax)
{
	char	**new;
	int		i;
	int		j;
	int		open;
	int		tmp;

	i = -1;
	open = 0;
	tmp = 0;
	printf("yo jesus \n");
	new = ft_preparejesus(tab, size, sizemax);
	ft_print_tab(new);
	printf("jesus ok \n");
	while (++i < sizemax - 1)
	{
		j = -1;
		open = 0;
		while (++j < size)
		{
			printf("tu es sur ce char la %c  %d ton i %d & ton j %d \n", new[j][i], new[j][i], i , j);
			printf("ton size %d et ton sizemax %d \n", size, sizemax);
			if (new[j][i] == '1' && open == 0)
				open++;
			else if ((new[j][i] == 32 || \
						(new[j][i] >= '\t' && new[j][i] <= '\r')) && \
						open == 1 && tmp == 0)
			{
				ft_free_tab(new);
				printf("cas 1 a la position %d %d\n", j, i);
				return (0);
			}
			else if ((new[j][i] == 32 || \
					(new[j][i] >= '\t' && new[j][i] <= '\r')) \
					&& open == 1 && tmp == 1)
			{
				open--;
				tmp--;
			}
			else if (new[j][i] == '1' && open == 1 && tmp == 0)
				tmp++;
			else if (new[j][i] == 0 && open == 1 && tmp == 1)
				tmp--;
			else if (new[j][i] == '0' && open == 0)
			{
				ft_free_tab(new);
				printf("cas 2 a la position %d %d\n", j, i);
				return (0);
			}
			else if ((new[j][i] == 'N' || new[j][i] == 'S' || new[j][i] == 'O' \
						|| new[j][i] == 'W') && open == 1 && tmp == 0)
				continue ;
			else if ((new[j][i] == 'N' || new[j][i] == 'S' || new[j][i] == 'O' \
						|| new[j][i] == 'W') && tmp == 1 && open == 1)
				tmp--;
		}
	}
	env->map = ft_cpy_tab(new, sizemax);
	ft_free_tab(new);
	return (1);
}

int	ft_parser_map(t_data *env, char **tab ,int size)
{
	if (!ft_read_char(tab, env))
		return (0);
	if (!ft_read_line(tab))
		return (0);
	if (!ft_read_colum(env, tab, size, ft_biggest_line(tab)))
		return (0);
	return (1);
}
