#include "../includes/Cub3d.h"

void	my_mlx_pixel_put(t_data *env, int x, int y, unsigned int color)
{
	char	*dst;
    if (x > 0 && y > 0 && x < 1000 && y < 1000)
	{
        //printf("ton x %d && ton y %d \n", x ,y);
		dst = env->img->addr + (y * env->img->line_lght + x * \
			(env->img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

float degToRad(float a) 
{ 
	return (a * M_PI/180.0);
}

float fixAng(float a)
{ 
	if (a >= 360)
		a -= 360;
	if (a < 0)
		a += 360;
	return (a);
}

unsigned int ft_get_color_map(int x, int y, t_data *env)
{
	if (x < 0 || y < 0 || x > ft_strlen_2d(env->map) || y > ft_strlen_cub(env->map[x]) || !(env->map[x]) || !env->map[x][y])
		return (BLACK);
    else if (env->map[x][y] == '1')
        return (WHITE);
    else if (env->map[x][y] == '0' || env->map[x][y] == 'W' || env->map[x][y] == 'N' || env->map[x][y] == 'E' || env->map[x][y] == 'S')
        return (BLUE);
	else 
		return (BLACK);
}

int ft_get_vertical_cam(int y, t_data *env)
{
    if (y >= 5)
    {
        env->decalagey = y - 5;
        return (y + 5);
    }
    return (10);
}

int ft_get_horizontal_cam(int x, t_data *env)
{

    if (x >= 5)
    {
        env->decalagex = x - 5;
        return (x + 5);
    }
    return (10);
}