/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataverni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:49:14 by ataverni          #+#    #+#             */
/*   Updated: 2022/03/21 15:50:24 by ataverni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

void	ft_exit_error(char *str)
{
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}

void	exit_message_with_free(char *tmp, char **file, char **tab, char *str)
{
	ft_free(tmp);
	ft_free_tab(file);
	ft_free_tab(tab);
	ft_exit_error(str);
}

void	exit_message_with_free_cleanup(t_data *env, char **file, \
		char **tab, char *str)
{
	ft_free_tab(env->param);
	ft_free(env->pathea);
	ft_free(env->pathno);
	ft_free(env->pathso);
	ft_free(env->pathwe);
	ft_free(env->color1);
	ft_free(env->color2);
	ft_free_tab(file);
	ft_free_tab(tab);
	ft_exit_error(str);
}

void	exit_free_data(t_data *env, char *str)
{
	ft_free_tab(env->param);
	ft_free_tab(env->map);
	ft_exit_error(str);
}
