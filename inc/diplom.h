#ifndef DIPLOM_H
# define DIPLOM_H
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../lib/libft/includes/libft.h"
# include "../minilibx/mlx.h"

typedef struct s_dot
{
    double arr_x[6000];
	double arr_y[6000];
	double arr_z[6000];
	double new_arr_x[6000];
	double new_arr_y[6000];
	double new_arr_z[6000];

}				t_dot;

typedef struct s_cube
{
    double arr_x[8];
	double arr_y[8];
	double arr_z[8];

	double new_arr_x[8];
	double new_arr_y[8];
	double new_arr_z[8];

}				t_cube;

typedef struct s_project
{
	void *mlx_ptr;
	void *win_ptr;
	void *image_ptr;
	char *begin_str_image;
	int size_line;
	double angle;
	t_dot *dot;
	t_cube *cube;

}				t_project; 

void	ft_main_draw(t_project *project);
#endif
