#include "../includes/Cub3d.h"

void ft_set_next_pos(t_player *tmp, float angle)
{
    tmp->angle = angle;
    tmp->angle = fixAng(tmp->angle);
    tmp->pdx = cos(degToRad(tmp->angle));
	tmp->pdy = sin(degToRad(tmp->angle));
}

void ft_move_up(t_data *env, int vitesse)
{
    t_player tmp;

    printf("avant x %f y  %f\n", env->player->x, env->player->y);
    tmp.angle = env->player->angle;
    tmp.x = env->player->x;
    tmp.y = env->player->y;
    ft_set_next_pos(&tmp, 90);
    env->player->x = ((tmp.pdx * vitesse) + tmp.x)/ SIZE;
    env->player->y = ((tmp.pdy * vitesse) + tmp.y)/ SIZE;
    printf("apres x %f y %f \n", env->player->x, env->player->y);
}

void ft_move_left(t_data *env, int vitesse)
{
    t_player tmp;

    printf("avant x %f y  %f\n", env->player->x, env->player->y);
    tmp.angle = env->player->angle;
    tmp.x = env->player->x;
    tmp.y = env->player->y;
    ft_set_next_pos(&tmp, 180);
    env->player->x = ((tmp.pdx * vitesse) + tmp.x)/ SIZE;
    env->player->y = ((tmp.pdy * vitesse) + tmp.y)/ SIZE;
    printf("apres x %f y %f \n", env->player->x, env->player->y);
}

void ft_move_right(t_data *env, int vitesse)
{
    t_player tmp;

    printf("avant x %f y  %f\n", env->player->x, env->player->y);
    tmp.angle = env->player->angle;
    tmp.x = env->player->x;
    tmp.y = env->player->y;
    ft_set_next_pos(&tmp, 0);
    env->player->x = ((tmp.pdx * vitesse) + tmp.x)/ SIZE;
    env->player->y = ((tmp.pdy * vitesse) + tmp.y)/ SIZE;
    printf("apres x %f y %f \n", env->player->x, env->player->y);
}

void ft_move_down(t_data *env, int vitesse)
{
    t_player tmp;
    
    printf("avant x %f y  %f\n", env->player->x, env->player->y);
    tmp.angle = env->player->angle;
    tmp.x = env->player->x;
    tmp.y = env->player->y;
    ft_set_next_pos(&tmp, 270);
    env->player->x = ((tmp.pdx * vitesse) + tmp.x)/ SIZE;
    env->player->y = ((tmp.pdy * vitesse) + tmp.y)/ SIZE;
    printf("apres x %f y %f \n", env->player->x, env->player->y);
}