#include "../includes/Cub3d.h"

int ft_cleanup(t_data *env)
{
    mlx_destroy_window(env->mlx, env->win);
    exit_free_data(env, "");
    return (0);
}

void ft_handle_rota_left(t_data *env)
{
	env->player->angle += 5;
	env->player->angle = fixAng(env->player->angle);
	printf("ton angle vaut %f \n", env->player->angle);
	env->player->pdx = cos(degToRad(env->player->angle));
	env->player->pdy = -sin(degToRad(env->player->angle));
}

void ft_handle_rota_right(t_data *env)
{
	env->player->angle -= 5;
	env->player->angle = fixAng(env->player->angle);
	printf("ton angle vaut %f \n", env->player->angle);
	env->player->pdx = cos(degToRad(env->player->angle));
	env->player->pdy = -sin(degToRad(env->player->angle));
}

int holdkey(int keycode, t_data *env)
{
    printf("ton keycode = %d\n", keycode);
    if (keycode == KEY_ESC)
        ft_cleanup(env);
	else if (keycode == 12)
		ft_handle_rota_left(env);
	else if (keycode == 14)
		ft_handle_rota_right(env);
    ft_draw(env);
    return (0);
}