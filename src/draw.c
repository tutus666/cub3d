#include "../includes/Cub3d.h"

// void draw_square(int x, int y, t_data *env, unsigned int color )
// {
//     int startposx;
//     int startposy;
//     int stopx;
//     int stopy;

//     startposx = x * SIZE;
//     startposy = y * SIZE;
//     stopx = startposx + SIZE;
//     stopy = startposy + SIZE;
//     while(startposx < stopx)
//     {
//         startposy = y * SIZE;
//         while(startposy < stopy)
//         {
//             my_mlx_pixel_put(env, startposx, startposy, color);
//             startposy++;
//         }
//         startposx++;
//     }
//     env->draw->sizemax = startposy;
//     env->draw->heightmax = startposx;
// }


// void ft_draw_line(t_data *env, int sizeline, int posline)
// {
//     int i;

//     i = -1;
//     while (++i < sizeline)
//         my_mlx_pixel_put(env, posline, i, RED);
// }

// void ft_draw_colum(t_data *env, int sizeline, int posline)
// {
//     int i;

//     i = -1;
//     while(++i < posline)
//         my_mlx_pixel_put(env, i, sizeline, RED);
// }
// void ft_draw_lines(t_data *env)
// {
//     int startx;
//     int limitx;

//     startx = 0;
//     limitx = env->draw->scalex;

//     while (startx < limitx)
//     {
//         ft_draw_line(env, env->draw->scaley * SIZE, startx * SIZE);
//         startx++;
//     }

//     limitx = env->draw->scaley;
//     startx = 0;
//     while (startx < limitx)
//     {
//         ft_draw_colum(env, startx * SIZE, env->draw->scalex * SIZE);
//         startx++;
//     }
// }

// void ft_draw_map(t_data *env)
// {
//     int i;
//     int j;
//     int tmpy;
//     int tmpx;

//     i = 0;
//     j = 0;
//     tmpx = env->draw->startx;
//     while (i < env->draw->scalex)
//     {   
//         tmpy = env->draw->starty;
//         j = 0;
//         while (j < env->draw->scaley)
//         {
//             draw_square(j, i, env, ft_get_color_map(tmpx, tmpy, env));
//             j++;
//             tmpy++;
//         }
//         printf("ton i : %d ton j : %d \n", tmpx, tmpy);
//         i++;
//         tmpx++;
//     }
   
// }

// void ft_get_first_angle(t_data *env, t_player *tmp)
// {
//     int i;

//     i = 0;
//     tmp->angle = env->player->angle;
//     tmp->pdx = env->player->pdx;
//     tmp->pdy = env->player->pdy;
//     tmp->x = env->player->x;
//     tmp->y = env->player->y;
//     printf("ton angle au debut %f\n", tmp->angle);
//     while (i < 6)
//     {
//         tmp->angle += 5;
//         tmp->angle = fixAng(tmp->angle);
//         tmp->pdx = cos(degToRad(tmp->angle));
//         tmp->pdy = -sin(degToRad(tmp->angle));
//         i++;
//     }
//      printf("ton angle a la fin %f\n", tmp->angle);
// }
// void ft_get_last_angle(t_data *env, t_player *last)
// {
//     int i;

//     i = 0;
//     last->angle = env->player->angle;
//     last->pdx = env->player->pdx;
//     last->pdy = env->player->pdy;
//     last->x = env->player->x;
//     last->y = env->player->y;
//     printf("ton angle au debut %f\n", last->angle);
//     while (i < 6)
//     {
//         last->angle -= 5;
//         last->angle = fixAng(last->angle);
//         last->pdx = cos(degToRad(last->angle));
//         last->pdy = -sin(degToRad(last->angle));
//         i++;
//     }
//      printf("ton angle a la fin %f\n", last->angle);
// }

// void ft_add_angle(t_player *last)
// {
//     last->angle -= 1;
//     last->angle = fixAng(last->angle);
//     last->pdx = cos(degToRad(last->angle));
//     last->pdy = -sin(degToRad(last->angle));

// }

// void ft_print_col(t_data *env, t_player *actuel, int distance)
// {
//     int d;
//     int x;
//     static int angle = 120;
//     int y;
//     t_player tmp;

//     d = distance / SIZE;
//     x = 400;
//     y = 599;
//     (void) actuel;
//     tmp.angle = angle;
//     tmp.pdx = cos(degToRad(tmp.angle));
// 	tmp.pdy = -sin(degToRad(tmp.angle));
//     tmp.x = ((tmp.pdx * distance) + x) / SIZE;
//     tmp.y = ((tmp.pdy * distance) + y) / SIZE;
//     printf("ton pdx %f et ton pdy %f\n", tmp.pdx, tmp.pdy);
//     my_mlx_pixel_put_ray(env, x, y, WHITE);
//     my_mlx_pixel_put_ray(env, (tmp.pdy * distance) + y, (tmp.pdx * distance) + x, WHITE);
//     // while (d < distance)
//     // {
//     //     tmp.x = ((tmp.pdx * d) + tmp.x)/ SIZE;
//     //     tmp.y = ((tmp.pdy * d) + tmp.y) / SIZE;
//     //     my_mlx_pixel_put_ray(env, (tmp.pdy * distance) + tmp.y, (tmp.pdx * distance) + tmp.x, WHITE);
//     //     d++;
//     // }
//     mlx_put_image_to_window(env->mlx, env->win, env->raycast->data, 0, 0);
//     angle = fixAng(angle);
//     angle++;
// }

// void ft_draw_line_tutus(t_data *env, float x, float y)
// {
//     int hit;
//     int distance;
//     t_player tmp;
//     t_player last;

//     hit = 0;
//     ft_get_first_angle(env, &tmp);
//     ft_get_last_angle(env, &last);
//     distance = 5;
//     my_mlx_pixel_put(env, (last.pdy * 5) + y, (last.pdx * 5) + x, WHITE);
//     while (tmp.angle != last.angle)
//     { 
//         distance = 5;
//         hit = 0;
//         while (!hit)
//         {
//             tmp.x = ((tmp.pdx * distance) + x) / SIZE;
//             tmp.y = ((tmp.pdy * distance) + y) / SIZE;
//             if (!env->map[(int)tmp.x + env->decalagex][(int)tmp.y + env->decalagey])
//                 hit++;
//             else if (env->map[(int)tmp.x + env->decalagex][(int)tmp.y + env->decalagey] == '1')
//                 hit++;
//             else if (distance < 400)
//                 my_mlx_pixel_put(env, (tmp.pdy * distance) + y, (tmp.pdx * distance) + x, BLACK);
//             distance++;
//         }
//         printf("angle = %f distance = %d\n", tmp.angle, distance);
//         env->posx = x;
//         env->posy = y;
//         ft_print_col(env, &tmp, distance);
//         ft_add_angle(&tmp);
//     }
// }

// void ft_draw_camera(t_data *env, float x, float y)
// {
//     int hit;
//     int tmp;
//     int distance;
//     int tmpx;
//     // int tmp2x;
//     int tmpy;
//     // int tmp2y;

//     hit = 0;
//     distance = 5;
//     tmp = x / SIZE;
// 	my_mlx_pixel_put(env, y, x, WHITE);
// 	my_mlx_pixel_put(env, (env->player->pdy * 5) + y, (env->player->pdx * 5) + x, WHITE);
//     while (!hit && distance < 400)
//     {
//         tmpx = ((env->player->pdx * distance) + x) / SIZE;
//         tmpy = ((env->player->pdy * distance) + y) / SIZE;
//         //printf(" test 1 coordonnees x: %f y : %f \n", (((env->player->pdx * distance) + x) / SIZE), ((env->player->pdy * distance) + y) / SIZE);
//         // printf("tu te trouve sur ce char la %c valeur int %d et ta coord x %d et ta coord %d\n", env->map[tmpx + env->decalagex][tmpy + env->decalagey], env->map[tmpx + env->decalagex][tmpy + env->decalagey], tmpx + env->decalagex, tmpy + env->decalagey);
//         if (env->map[tmpx + env->decalagex][tmpy + env->decalagey] == '1')
//             hit++;
//         else
//             my_mlx_pixel_put(env, (env->player->pdy * distance) + y, (env->player->pdx * distance) + x, BLACK);
//         distance++;
//     }
//     ft_draw_line_tutus(env, x, y);
//     // tmp2x = ((env->player->pdx) + x) / SIZE;
//     // tmp2y = ((env->player->pdy) + y) / SIZE;    
//     // printf("test coord 2 tu es en x %d et y %d  && ton decalagex %d  && ton decallagey %d \n", tmpx, tmpy, env->decalagex, env->decalagey);
//     // printf("test coord 3 tu es en x %d et y %d  && ton decalagex %d  && ton decallagey %d \n", tmp2x, tmp2y + env->decalagey, env->decalagex, env->decalagey);
//     // printf("tu te trouve sur ce char la %c valeur int %d\n test pos joueurs %c \n", env->map[tmpx + env->decalagex][tmpy + env->decalagey], env->map[tmpx + env->decalagex][tmpy + env->decalagey], env->map[tmp2x][tmp2y + env->decalagey]);
//     //printf("tu as une distance de %d \n", (distance / 64));
// }

// void ft_draw_player(t_data *env)
// {
//     float posx;
//     float posy;
//     float endx;
//     float endy;
//     //printf("ma map fait %d sur %d pixel \n", env->draw->sizemax, env->draw->heightmax);
//     //printf("je veux que mon personnage soit print a cette position %f %f test : %f \n", env->player->x * SIZE, (env->draw->endy - env->player->y) * SIZE, ((env->draw->endy - env->player->y) + 0.5) * SIZE);

//     posx = env->player->x;
//     posy = (env->draw->endy - env->player->y);
//     endx = (posx + 0.1) * SIZE;
//     endy = (posy + 0.1) * SIZE;
//     posx *= SIZE;
//     posy *= SIZE;
//     while (posx < endx)
//     {
//         posy = (env->draw->endy - env->player->y) * SIZE;
//         while (posy < endy)
//         {
//             //printf("je veux print a cette coordonees %f %f \n", posx, posy);
//             //printf("tu compare %f a %f && %f a %f \n", posx, endx, posy, endy);
//             my_mlx_pixel_put(env, posy, posx, BLACK);
//             posy++;
//         }
//         posx++;
//     }
// 	ft_draw_camera(env, (env->player->x + 0.05) * SIZE, (env->draw->endy - env->player->y + 0.05) * SIZE);

// }

// void   ft_draw_all(int x, int y, t_data *env)
// {
//     t_draw  draw;

//     env->draw = &draw;
// 	env->draw->endy = ft_get_vertical_cam(y, env);
//     env->draw->endx = ft_get_horizontal_cam(x, env);
// 	env->draw->startx = x - 5;
// 	if (env->draw->startx < 0)
// 		env->draw->startx = 0;
// 	env->draw->starty = y - 5;
// 	if (env->draw->starty < 0)
// 		env->draw->starty = 0;
//     printf("je veux dessiner de startx %d a endx %d et de starty %d a endy %d \n", env->draw->startx, env->draw->endx, env->draw->starty, env->draw->endy);
//     env->draw->scalex = env->draw->endx - env->draw->startx;
//     env->draw->scaley = env->draw->endy - env->draw->starty;
//     //printf("on veux commencer a print x depuis cette coordonnees %d et fini a %d on commence y a %d et on fini a %d\n", env->draw->startx, env->draw->endx, env->draw->starty, env->draw->endy);
//     ft_draw_map(env);
//     ft_draw_lines(env);
//     ft_draw_player(env);
	
// }

void	ft_init_draw(t_data *env)
{
	env->draw->sizemax = 960;
	env->draw->heightmax = 600;
	env->draw->centerx = env->draw->sizemax / 2;
	env->draw->centery = env->draw->heightmax / 2;
	env->draw->angle = 60;
	env->draw->distancetoplane = env->draw->centerx / tan(env->draw->angle);
	env->draw->sizeangle = (float)env->draw->angle / (float)env->draw->sizemax;
}

float	ft_return_distance_horizontal(t_data *env, float angle)
{
	int	x;
	int	y;
	int	xa;
	int	ya;

	xa = SIZE / tan(degToRad(angle));
	if (xa > 0 && angle > 90 && angle < 270)
		xa *= -1;
	else if (xa < 0 && ((angle > 0 && angle < 90) || (angle > 270 && angle < 360)))
		xa *= -1;
	if (angle > 0.0 && angle < 180.0)
	{
		ya = -SIZE;
		y = env->player->x * SIZE - 1;
	}
	else
	{
		ya = SIZE;
		y = env->player->x * SIZE + SIZE;
	}
	x = env->player->y * SIZE + (env->player->x * SIZE - y) / tan(degToRad(angle));
	printf("xa = %d ya = %d\n", xa, ya);
	printf("x = %d y = %d\n", x / SIZE, y / SIZE);
	while (x > 0 && y > 0 && x / SIZE < 9 && y / SIZE < 6 && env->map[y / SIZE][x / SIZE] != '1')
	{
		fprintf(stderr, "coord : x = %d y = %d\n", x / SIZE, y / SIZE);
		fprintf(stderr, "pxl   : x = %d y = %d\n", x, y);
		x += xa;
		y += ya;
	}
	fprintf(stderr, "HIT WALL @ x = %d y = %d\n", x / SIZE, y / SIZE);
	fprintf(stderr, "Distance h = %f\n", sqrt((pow(env->player->y * SIZE - x, 2) + pow(env->player->x - y, 2))));
	return (sqrt(pow(env->player->y * SIZE - x, 2) + pow(env->player->x * SIZE - y, 2)));
}

float ft_return_distance_vertical(t_data *env, float angle)
{
	int	x;
	int	y;
	int	xa;
	int	ya;

	ya = SIZE * tan(degToRad(angle));
	if (ya > 0 && angle > 0 && angle < 180)
		ya *= -1;
	else if (ya < 0 && angle > 180 && angle < 360)
		ya *= -1;
	if (angle > 90.0 && angle < 270.0)
	{
		xa = -SIZE;
		x = env->player->y * SIZE - 1;
	}
	else
	{
		xa = SIZE;
		x = env->player->y * SIZE + SIZE;
	}
	y = env->player->x * SIZE + (env->player->y * SIZE - x) * tan(degToRad(angle));
	printf("xa = %d ya = %d\n", xa, ya);
	printf("x = %d y = %d\n", x / SIZE, y / SIZE);
	while (x > 0 && y > 0 && x / SIZE < 9 && y / SIZE < 6 && env->map[y / SIZE][x / SIZE] != '1')
	{
		x += xa;
		y += ya;
		fprintf(stderr, "coord : x = %d y = %d\n", x / SIZE, y / SIZE);
		fprintf(stderr, "pxl   : x = %d y = %d\n", x, y);
	}
	fprintf(stderr, "HIT WALL @ x = %d y = %d\n", x / SIZE, y / SIZE);
	fprintf(stderr, "Distance v = %f\n", sqrt((pow(env->player->y * SIZE - x, 2) + pow(env->player->x - y, 2))));
	return (sqrt(pow(env->player->y * SIZE - x, 2) + pow(env->player->x * SIZE - y, 2)));
}

float ft_give_distance(t_data *env, float angle)
{
	float	distance_h;
	float	distance_v;

	distance_h = ft_return_distance_horizontal(env, angle);
	distance_v = ft_return_distance_vertical(env, angle);
	if (distance_h <= distance_v)
		return (distance_h);
	return (distance_v);
}

void draw_col(t_data *env, int x, int h)
{
	int i;
	int	start;

	start = env->draw->heightmax / 2 - h / 2;
	i = -1;
	while (++i < env->draw->heightmax)
	{
		if (i < start)
			my_mlx_pixel_put(env, x, i, BLACK);
		else if (i >= start && i <= start + h)
			my_mlx_pixel_put(env, x, i, MAROON);
		else
			my_mlx_pixel_put(env, x, i, WHITE);
	}
}

void ft_draw(t_data *env)
{
	t_img	img;
	t_draw	raycast;
	int		x;
	int		d;
	float	h;
	float	a;

	env->img = &img;
	env->draw = &raycast;
	ft_init_draw(env);
	a = -env->draw->angle / 2;
	
	env->img->data = mlx_new_image(env->mlx, env->draw->sizemax, env->draw->heightmax);
	env->img->addr = mlx_get_data_addr(env->img->data, &env->img->bpp, &env->img->line_lght, &env->img->endian);
	x = -1;
	while (++x <= env->draw->sizemax)
	{
		printf("ray number %d with angle %f\n", x, fixAng(env->player->angle + a));
		d = ft_give_distance(env, fixAng(env->player->angle + a));
		fprintf(stderr, "distorted distance = %d\n", d);
		h = SIZE / (float)d * env->draw->distancetoplane;
		printf("h = %f\n", h);
		draw_col(env, x, h);
		a += env->draw->sizeangle;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img->data, 0, 0);
}