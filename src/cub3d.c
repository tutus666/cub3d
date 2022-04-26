/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataverni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:43:18 by ataverni          #+#    #+#             */
/*   Updated: 2022/03/21 15:48:43 by ataverni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

void	ft_get_map(t_data *env, char **tab, int size, int startpos)
{
	int	i;
	int	j;
	char **tmp;

	i = startpos;
	j = 0;
	tmp = malloc(sizeof(char *) * size + 1);
	if (!tmp)
		return ;
	while (tab[i] && i < size)
	{
		tmp[j++] = ft_strdup(tab[i]);
		i++;
	}
	tmp[j] = NULL;
	if (!ft_parser_map(env, tmp, j - 1))
		exit_message_with_free_cleanup(env, tmp, NULL, "error\n parsing map\n");
	else
		ft_print_tab(env->map);
}

void	ft_looking_for_map(t_data *env, char **tab)
{
	int	index;
	int	i;
	int	size;
	int	totalsize;

	i = -1;
	index = 0;
	size = 0;
	totalsize = ft_strlen_2d(tab);
	while (tab[++i])
	{
		if (ft_isonly_one(tab[i]) && index == 0)
			index = i;
	}
	totalsize -= 1;
	while (tab[totalsize] && totalsize >= index)
	{
		if (ft_isonly_one(tab[totalsize]) && size == 0)
			size = totalsize;
		totalsize--;
	}
	if (index == 0 && size == 0)
		printf("gestion sortie ya pas de map\n");
	ft_get_map(env, tab + index - 1, size, index);
}

int	ft_handle_arg(char **tab, t_data *env)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (!strncmp(tab[i], "NO ", 3))
		{
			if (!ft_handler_no(env, tab[i]))
				return (1);
		}
		else if (!strncmp(tab[i], "SO ", 3))
		{
			if (!ft_handler_so(env, tab[i]))
				return (1);
		}
		else if (!strncmp(tab[i], "WE ", 3))
		{
			if (!ft_handler_we(env, tab[i]))
				return (1);
		}
		else if (!strncmp(tab[i], "EA ", 3))
		{
			if (!ft_handler_ea(env, tab[i]))
				return (1);
		}
		else if (!strncmp(tab[i], "F ", 2))
		{
			if (!ft_handler_floor(env, tab[i]))
				return (1);
		}
		else if (!strncmp(tab[i], "C ", 2))
		{
			if (!ft_handler_sky(env, tab[i]))
				return (1);
		}
		else
			return (0);
	}
	return (1);
}

char	**ft_handler_param(t_data *env, char **tab)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = malloc(sizeof(char *) * 7);
	if (!new)
		return (NULL);
	while (tab[i] && j < env->nbofarg)
	{
		if (!ft_isonlyspace(tab[i]))
			new[j++] = ft_strdup(tab[i]);
		i++;
	}
	new[j] = 0;
	//ft_print_tab(new);
	if (!ft_handle_arg(new, env)) // reste a tester la validiter des path et la couleur des rgb pour le sol et ciel
		exit_message_with_free_cleanup(env, tab, new, "Error\n Bad param\n"); // tester les leaks pas sur de tout gerer
	//printf("ton PATHNO:%s\n ton PATHSO:%s\n ton PATHWE:%s\n ton PATHEA:%s\n ton Color1:%s\n ton Color2:%s\n", env->pathno, env->pathso, env->pathwe, env->pathea, env->color1, env->color2);
	ft_looking_for_map(env, tab + i); //  sortie avec free a revoir men ballec de ton exit(1);
	ft_print_map(new);
	ft_free_tab(tab);
	return (new);
}

void	ft_parse_map(t_data *env, char *path)
{
	char	*line;
	int		index;
	char	**new;

	line = NULL;
	index = ft_return_nb_of_line(env->fd, line);
	new = malloc(sizeof(char *) * (index + 1));
	if (!new)
		return ;
	close(env->fd);
	env->fd = open(path, O_RDONLY);
	index = 0;
	while (get_next_line(env->fd, &line) > 0)
	{
		new[index++] = ft_strdup(line);
		ft_free(line);
	}
	new[index++] = ft_strdup(line);
	ft_free(line);
	new[index] = 0;
	env->param = ft_handler_param(env, new);
	return ;
}

int	main(int ac, char **av)
{
	t_data		env;
	t_player	oui;

	env.player = &oui;
	env.player->dir = 0;
	ft_init_env(&env);
	if (ac != 2)
		ft_exit_error("Invalid number of arguments\n");
	if (!ft_parseur_extension(av[1]))
		ft_exit_error("Invalid argument\n");
	ft_tryopen(av[1], &env);
	ft_parse_map(&env, av[1]);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 800, 600, "Cub3d");
	ft_draw(&env);
	mlx_hook(env.win, 2, 0, holdkey, &env);
	mlx_hook(env.win, 17, 0 , ft_cleanup, &env);
	mlx_loop(env.mlx);
}
