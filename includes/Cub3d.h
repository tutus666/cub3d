#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
//# include <mlx.h>
# include <../includes/mlx/mlx.h>
# include "../includes/libft/libft.h"
# include "../includes/gnl/get_next_line.h"
// define PI pour init rotation 
# define PI_2   6.2831853071795865
# define PI_3_4 4.7123889803846899



# define BLACK            0x00000000
# define GRAY             0x00808080
# define SILVER           0x00C0C0C0
# define WHITE            0x00FFFFFF
# define NAVY             0x00000080
# define BLUE             0x000000FF
# define TEAL             0x00008080
# define AQUA             0x0000FFFF
# define GREEN            0x00008000
# define LIME             0x0000FF00
# define OLIVE            0x00808000
# define YELLOW           0x00FFFF00
# define MAROON           0x00800000
# define RED              0x00FF0000
# define PURPLE           0x00800080
# define FUCHSIA          0x00FF00FF
# define DARK_BLUE        0x003e6358
# define LIGHT_CYAN       0x006eccc4

# define HEIGHT	1000
# define WIDTH 1200
# define SIZE 64
# define KEY_ESC 53
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_EVENT_PRESS 2
# define KEY_EVENT_EXIT 17
# define KEY_EVENT_RELEASE 3

typedef struct s_draw
{
	int centerx;
	int centery;
	int distancetoplane;
	int distance;
	int angle;
	float sizeangle;
    int sizemax;
    int heightmax;

}               t_draw;

typedef struct s_img
{
    void    *data;
    char    *addr;
    int     bpp;
    int     line_lght;
    int     endian;
}               t_img;

typedef struct s_player
{
	float 	x;
	float 	y;
	float 	pdx;
	float 	pdy;	// position camera
	float 	angle;	// angle camera
	float 	dir;
}			t_player;

typedef struct s_data 
{
    char **map;
	char **param;
    int  boolno;
    char *pathno;
    int  boolso;
    char *pathso;
    int  boolwe;
    char *pathwe;
    int  boolea;
    char *pathea;
    int  boolf;
    char *color1;
    int  boolc;
    char *color2;
    void *mlx;
    void *win;
    int fd;
    int  nbofarg;
    int decalagex;
    int decalagey;
    float posx;
    float posy;
	t_player 	*player;
    t_img       *img;
    t_draw       *raycast;
    t_draw      *draw;
}              t_data;			// struct a revoir peut etre faire une struct pour le parsing pour epurer la struct general

// parsing part
int     ft_get_arg(t_data *env, char **file, char **map);
void    ft_tryopen(char *PATH, t_data *env);
int     ft_parseur_extension(char *path);
int 	ft_parser_map(t_data *env, char **tab, int size);

// parsing param
int 	ft_handler_floor(t_data *env, char *color);
int 	ft_handler_sky(t_data *env, char *color);
int 	ft_handler_ea(t_data *env, char *path);
int 	ft_handler_we(t_data *env, char *path);
int 	ft_handler_so(t_data *env, char *path);
int 	ft_handler_no(t_data *env, char *path);

// init part
void ft_init_env(t_data *env);

// free part
void 	ft_free_tab(char **content);
void 	ft_free(void *content);

// join part
char 	*ft_strjoinfree(char *dst, char *src);
char 	*ft_strjoinwithchar(char *str, char *tmp, char c, char *new);
char 	*ft_strjoin_cub(char *src, char *dst);
char 	*ft_strjoin_space(char *str, int max);
char 	*ft_minijoint_size(char *src, char dst, int size);

//exit part
void 	exit_message_with_free(char *tmp, char **file, char **tab, char *str);
void 	ft_exit_error(char *str);
void  	exit_free_data(t_data *env, char *str);
void 	exit_message_with_free_cleanup(t_data *env, char **file, char **tab, char *str);

// utils part
int 	ft_strlen_cub(char *str);
int 	ft_strlen_2d(char **tab);
int 	ft_isonly_one(char *str);
void 	ft_print_tab(char **tab);
void 	ft_print_map(char **tab);
int 	ft_strlen_map(char *str);
int     ft_isonlyspace(char *str);
char    *ft_leavefirstspace(char *str);
char 	**ft_cpy_tab(char **tab, int sizetab);
int 	ft_return_nb_of_line(int fd, char *line);


// holdkey
int 	ft_cleanup(t_data *env);
int 	holdkey(int keycode, t_data *env);
void ft_move_up(t_data *env, int vitesse);
void ft_move_left(t_data *env, int vitesse);
void ft_move_right(t_data *env, int vitesse);
void ft_move_down(t_data *env, int vitesse);

// drawpart
void            ft_draw(t_data *env);
void	my_mlx_pixel_put_ray(t_data *env, int x, int y, unsigned int color);
int             ft_get_horizontal_cam(int x, t_data *env);
int             ft_get_vertical_cam(int y, t_data *env);
unsigned int    ft_get_color_map(int x, int y, t_data *env);
void	        my_mlx_pixel_put(t_data *env, int x, int y, unsigned int color);
float	fixAng(float a);
float 	degToRad(float a);

#endif