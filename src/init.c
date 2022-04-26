/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataverni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:57:43 by ataverni          #+#    #+#             */
/*   Updated: 2022/03/21 15:58:42 by ataverni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

void	ft_init_env(t_data *env)
{
	env->fd = 0;
	env->map = NULL;
	env->nbofarg = 6;
	env->param = NULL;
	env->boolno = 0;
	env->pathno = NULL;
	env->boolso = 0;
	env->pathso = NULL;
	env->boolwe = 0;
	env->pathwe = NULL;
	env->boolea = 0;
	env->pathea = NULL;
	env->boolf = 0;
	env->color1 = NULL;
	env->boolc = 0;
	env->color2 = NULL;
}
