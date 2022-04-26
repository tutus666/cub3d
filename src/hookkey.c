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
}

void ft_handle_rota_right(t_data *env)
{
	env->player->angle -= 5;
	env->player->angle = fixAng(env->player->angle);
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
	else if (keycode == 13) // up
        ft_move_up(env, 0);
    else if (keycode == 0) // right
        ft_move_left(env, 0);
    else if (keycode == 1)    // down
        ft_move_down(env, 0);
    else if (keycode == 2)// left
        ft_move_left(env, 0);
    ft_draw(env);
    return (0);
}