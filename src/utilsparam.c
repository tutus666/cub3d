#include "../includes/Cub3d.h"

int ft_handler_no(t_data *env, char *path)
{
	if (!env->boolno)
	{
		env->boolno++;
		env->pathno = ft_strdup(path);
		return (1);
	}
	return (0);
}

int ft_handler_so(t_data *env, char *path)
{
	if (!env->boolso)
	{
		env->boolso++;
		env->pathso = ft_strdup(path);
		return (1);
	}
	return (0);
}

int ft_handler_we(t_data *env, char *path)
{
	if (!env->boolso)
	{
		env->boolso++;
		env->pathso = ft_strdup(path);
		return (1);
	}
	return (0);
}

int ft_handler_ea(t_data *env, char *path)
{
	if (!env->boolso)
	{
		env->boolso++;
		env->pathso = ft_strdup(path);
		return (1);
	}
	return (0);
}

int ft_handler_sky(t_data *env, char *color)
{
	if (!env->boolc)
	{
		env->boolc++;
		env->color2 = ft_strdup(color);
		return (1);
	}
	return (0);
}

int ft_handler_floor(t_data *env, char *color)
{
	if (!env->boolf)
	{
		env->boolf++;
		env->color1 = ft_strdup(color);
		return (1);
	}
	return (0);
}