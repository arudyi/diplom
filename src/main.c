# include "../inc/diplom.h"


int ft_exit(t_project *project)
{
	exit(1);
	return (0);
}

void ft_matrix_x(t_project *project, int key)
{
	int i;

	i = -1;
	project->angle = (key == 65361) ? + 2 : - 2;
	project->angle = project->angle / 180 * 3.14;
	while (++i < 8)
	{
		///cube
		project->cube->arr_x[i] -= 300;
		project->cube->arr_y[i] -= 300;
		project->cube->arr_z[i] -= 150;
		project->cube->new_arr_x[i] = project->cube->arr_x[i];
		project->cube->new_arr_y[i] = project->cube->arr_y[i] * cos(project->angle) + project->cube->arr_z[i] * sin(project->angle);
		project->cube->new_arr_z[i] = -project->cube->arr_y[i] * sin(project->angle) + project->cube->arr_z[i] * cos(project->angle);
		project->cube->arr_x[i] = project->cube->new_arr_x[i] + 300;
		project->cube->arr_y[i] = project->cube->new_arr_y[i] + 300;
		project->cube->arr_z[i] = project->cube->new_arr_z[i] + 150;
	}
	i = -1;
	while (++i < 5981)
	{
			//dots
		project->dot->arr_x[i] -= 300;
		project->dot->arr_y[i] -= 300;
		project->dot->arr_z[i] -= 150;
		project->dot->new_arr_x[i] = project->dot->arr_x[i];
		project->dot->new_arr_y[i] = project->dot->arr_y[i] * cos(project->angle) + project->dot->arr_z[i] * sin(project->angle);
		project->dot->new_arr_z[i] = -project->dot->arr_y[i] * sin(project->angle) + project->dot->arr_z[i] * cos(project->angle);
		project->dot->arr_x[i] = project->dot->new_arr_x[i] + 300;
		project->dot->arr_y[i] = project->dot->new_arr_y[i] + 300;
		project->dot->arr_z[i] = project->dot->new_arr_z[i] + 150;
	}
}

void ft_matrix_y(t_project *project, int key)
{
	int i;

	i = -1;

	project->angle = (key == 65362) ? + 2 : - 2;
	project->angle = project->angle / 180 * 3.14;
	while (++i < 8)
	{
		//cube
		project->cube->arr_x[i] -= 300;
		project->cube->arr_y[i] -= 300;
		project->cube->arr_z[i] -= 150;
		project->cube->new_arr_x[i] = project->cube->arr_x[i] * cos(project->angle) + project->cube->arr_z[i] * sin(project->angle);
		project->cube->new_arr_y[i] = project->cube->arr_y[i];
		project->cube->new_arr_z[i] = -project->cube->arr_x[i] * sin(project->angle) + project->cube->arr_z[i] * cos(project->angle);
		project->cube->arr_x[i] = project->cube->new_arr_x[i] + 300;
		project->cube->arr_y[i] = project->cube->new_arr_y[i] + 300;
		project->cube->arr_z[i] = project->cube->new_arr_z[i] + 150;
	}
	i = -1;
	while (++i < 5981)
	{
		project->dot->arr_x[i] -= 300;
		project->dot->arr_y[i] -= 300;
		project->dot->arr_z[i] -= 150;
		project->dot->new_arr_x[i] = project->dot->arr_x[i] * cos(project->angle) + project->dot->arr_z[i] * sin(project->angle);
		project->dot->new_arr_y[i] = project->dot->arr_y[i];
		project->dot->new_arr_z[i] = -project->dot->arr_x[i] * sin(project->angle) + project->dot->arr_z[i] * cos(project->angle);
		project->dot->arr_x[i] = project->dot->new_arr_x[i] + 300;
		project->dot->arr_y[i] = project->dot->new_arr_y[i] + 300;
		project->dot->arr_z[i] = project->dot->new_arr_z[i] + 150;
	}
}

void ft_matrix_z(t_project *project, int key)
{
	int i;

	i = -1;
	project->angle = (key == 65436) ? + 2 : - 2;
	project->angle = project->angle / 180 * 3.14;
	while (++i < 8)
	{
		//cube
		project->cube->arr_x[i] -= 300;
		project->cube->arr_y[i] -= 300;
		project->cube->arr_z[i] -= 150;

		project->cube->new_arr_x[i] = project->cube->arr_x[i] * cos(project->angle) + project->cube->arr_y[i] * sin(project->angle);
		project->cube->new_arr_y[i] = -project->cube->arr_x[i] * sin(project->angle) + project->cube->arr_y[i] * cos(project->angle);
		project->cube->new_arr_z[i] = project->cube->arr_z[i];

		project->cube->arr_x[i] = project->cube->new_arr_x[i] + 300;
		project->cube->arr_y[i] = project->cube->new_arr_y[i] + 300;
		project->cube->arr_z[i] = project->cube->new_arr_z[i] + 150;
	}
	i = -1;
	while (++i < 5981)
	{
		project->dot->arr_x[i] -= 300;
		project->dot->arr_y[i] -= 300;
		project->dot->arr_z[i] -= 150;

		project->dot->new_arr_x[i] = project->dot->arr_x[i] * cos(project->angle) + project->dot->arr_y[i] * sin(project->angle);
		project->dot->new_arr_y[i] = -project->dot->arr_x[i] * sin(project->angle) + project->dot->arr_y[i] * cos(project->angle);
		project->dot->new_arr_z[i] = project->dot->arr_z[i];

		project->dot->arr_x[i] = project->dot->new_arr_x[i] + 300;
		project->dot->arr_y[i] = project->dot->new_arr_y[i] + 300;
		project->dot->arr_z[i] = project->dot->new_arr_z[i] + 150;
	}
}

void ft_refresh(t_project *project)
{
	int bits_per_pixel;
	int endian;

	project->angle = 0;
	mlx_destroy_image(project->mlx_ptr, project->image_ptr);

	project->image_ptr = mlx_new_image(project->mlx_ptr, 1920, 1080);
	project->begin_str_image = mlx_get_data_addr(project->image_ptr, &bits_per_pixel, &project->size_line, &endian);
}

void ft_start_again(t_project *project)
{
	project->cube->arr_x[0] = 200;
	project->cube->arr_x[1] = 500; //1000
	project->cube->arr_x[2] = 200;
	project->cube->arr_x[3] = 500;
	project->cube->arr_x[4] = 200;
	project->cube->arr_x[5] = 500;
	project->cube->arr_x[6] = 200;
	project->cube->arr_x[7] = 500;

	project->cube->arr_y[0] = 200;
	project->cube->arr_y[1] = 200;
	project->cube->arr_y[2] = 500; //1000;
	project->cube->arr_y[3] = 500;
	project->cube->arr_y[4] = 200;
	project->cube->arr_y[5] = 200;
	project->cube->arr_y[6] = 500;
	project->cube->arr_y[7] = 500;

	project->cube->arr_z[0] = 0;
	project->cube->arr_z[1] = 0;
	project->cube->arr_z[2] = 0;
	project->cube->arr_z[3] = 0;
	project->cube->arr_z[4] = 300; //900
	project->cube->arr_z[5] = 300;
	project->cube->arr_z[6] = 300;
	project->cube->arr_z[7] = 300;
	ft_prepare_dots(project);
}

int ft_key_press(int key, t_project *project)
{
	if (key == 65307)
		exit(1);
	if (key == 65361 || key == 65363)
		ft_matrix_x(project, key);
	if (key == 65362 || key == 65364)
		ft_matrix_y(project, key);
	if (key == 65436 || key == 65435)
		ft_matrix_z(project, key);
	if (key == 65288)
		ft_start_again(project);
	ft_refresh(project);
	ft_main_draw(project);
	return (0);
}

void	ft_pixel_to_image(t_project *project, int x, int y, int color)
{
	int index;

	if (!(x > 1919 || x < 0 || y > 1078 || y < 0))
	{
		index = project->size_line * y + (x << 2);
		*(unsigned *)(project->begin_str_image + index) = color;
	}
}

void ft_brezen(int x0, int y0, int x1, int y1, int color, t_project *project)
{
  int dx = abs(x1 - x0);
  int dy = abs(y1 - y0);
  int sx = x1 >= x0 ? 1 : -1;
  int sy = y1 >= y0 ? 1 : -1;
  
  if (dy <= dx)
  {
    int d = (dy << 1) - dx;
    int d1 = dy << 1;
    int d2 = (dy - dx) << 1;
    ft_pixel_to_image(project, x0, y0, color);
    for (int x = x0 + sx, y = y0, i = 1; i <= dx; i++, x += sx)
    {
      if ( d >0)
      {
        d += d2;
        y += sy;
      }
      else
        d += d1;
      ft_pixel_to_image(project, x, y, color);
    }
  }
  else
  {
    int d = (dx << 1) - dy;
    int d1 = dx << 1;
    int d2 = (dx - dy) << 1;
    ft_pixel_to_image(project, x0, y0, color);
    for (int y = y0 + sy, x = x0, i = 1; i <= dy; i++, y += sy)
    {
      if ( d >0)
      {
        d += d2;
        x += sx;
      }
      else
        d += d1;
      ft_pixel_to_image(project, x, y, color);
    }
  }
}

void ft_draw_cube(t_project *project)
{
	// down
	ft_brezen(project->cube->arr_x[0], project->cube->arr_y[0], project->cube->arr_x[1], project->cube->arr_y[1], 0xFFFF00, project);
	ft_brezen(project->cube->arr_x[0], project->cube->arr_y[0], project->cube->arr_x[2], project->cube->arr_y[2], 0xFFFF00, project);
	ft_brezen(project->cube->arr_x[2], project->cube->arr_y[2], project->cube->arr_x[3], project->cube->arr_y[3], 0xFFFF00, project);
	ft_brezen(project->cube->arr_x[1], project->cube->arr_y[1], project->cube->arr_x[3], project->cube->arr_y[3], 0xFFFF00, project);
	////////////////////////////// up
	ft_brezen(project->cube->arr_x[4], project->cube->arr_y[4], project->cube->arr_x[5], project->cube->arr_y[5], 0xFFFF00, project);
	ft_brezen(project->cube->arr_x[4], project->cube->arr_y[4], project->cube->arr_x[6], project->cube->arr_y[6], 0xFFFF00, project);
	ft_brezen(project->cube->arr_x[6], project->cube->arr_y[6], project->cube->arr_x[7], project->cube->arr_y[7], 0xFFFF00, project);
	ft_brezen(project->cube->arr_x[5], project->cube->arr_y[5], project->cube->arr_x[7], project->cube->arr_y[7], 0xFFFF00, project);
	///////////// from down to up
	ft_brezen(project->cube->arr_x[0], project->cube->arr_y[0], project->cube->arr_x[4], project->cube->arr_y[4], 0xFFFF00, project);
	ft_brezen(project->cube->arr_x[1], project->cube->arr_y[1], project->cube->arr_x[5], project->cube->arr_y[5], 0xFFFF00, project);
	ft_brezen(project->cube->arr_x[2], project->cube->arr_y[2], project->cube->arr_x[6], project->cube->arr_y[6], 0xFFFF00, project);
	ft_brezen(project->cube->arr_x[3], project->cube->arr_y[3], project->cube->arr_x[7], project->cube->arr_y[7], 0xFFFF00, project);
}

void ft_dots_on_screen(t_project *project)///////////////////////////////////////////////////
{
	int i;

	i = -1;
	while (++i < 5891)
	{
		ft_pixel_to_image(project, project->dot->arr_x[i], project->dot->arr_y[i], 0x00FFFF);
	}
}

void ft_draw_dots(t_project *project)
{
	ft_draw_cube(project);
	ft_dots_on_screen(project);
	mlx_put_image_to_window(project->mlx_ptr, project->win_ptr, project->image_ptr, 0, 0);
}

void	ft_main_draw(t_project *project)
{
	ft_draw_dots(project);
	mlx_hook(project->win_ptr, 2, 5, ft_key_press, project);
	mlx_hook(project->win_ptr, 17, 1L << 17, ft_exit, project);
	mlx_loop(project->mlx_ptr);
}

void ft_prepare_cube(t_project *project)
{
	project->cube->arr_x[0] = 200;
	project->cube->arr_x[1] = 500; //1000
	project->cube->arr_x[2] = 200;
	project->cube->arr_x[3] = 500;
	project->cube->arr_x[4] = 200;
	project->cube->arr_x[5] = 500;
	project->cube->arr_x[6] = 200;
	project->cube->arr_x[7] = 500;

	project->cube->arr_y[0] = 200;
	project->cube->arr_y[1] = 200;
	project->cube->arr_y[2] = 500; //1000;
	project->cube->arr_y[3] = 500;
	project->cube->arr_y[4] = 200;
	project->cube->arr_y[5] = 200;
	project->cube->arr_y[6] = 500;
	project->cube->arr_y[7] = 500;

	project->cube->arr_z[0] = 0;
	project->cube->arr_z[1] = 0;
	project->cube->arr_z[2] = 0;
	project->cube->arr_z[3] = 0;
	project->cube->arr_z[4] = 300; //900
	project->cube->arr_z[5] = 300;
	project->cube->arr_z[6] = 300;
	project->cube->arr_z[7] = 300;
}

void ft_prepare_dots(t_project *project)
{
	int fd;

	fd = open("./coord.txt", O_RDONLY);
	char *line;
	int i = 0;
	char **mas;
	while (get_next_line(fd, &line))
	{
		mas = ft_strsplit(line, ',');
		project->dot->arr_x[i] = ft_atoi(mas[0]) + 350;
		project->dot->arr_y[i] = ft_atoi(mas[1]) + 300;
		project->dot->arr_z[i] = ft_atoi(mas[2]) + 50; // + 300
		/*if (project->dot->arr_x[i] > project->max_x)
			project->max_x = project->dot->arr_x[i];
		if (project->dot->arr_y[i] > project->max_y)
			project->max_y = project->dot->arr_y[i];
		if (project->dot->arr_z[i] > project->max_z)
			project->max_z = project->dot->arr_z[i];*/
		free(mas[0]);
		free(mas[1]);
		free(mas[2]);
		//free(&mas);
		free(line);
		i++;
	}
	/*project->max_x += 50;
	project->max_y += 50;
	project->max_z += 50;
	printf("%d , %d , %d \n", project->max_x, project->max_y, project->max_z);*/
	close(fd);
}

void ft_prepare_program(t_project *project)
{
	int bits_per_pixel;
	int endian;

	project->mlx_ptr = mlx_init();
	project->win_ptr = mlx_new_window(project->mlx_ptr, 1000, 600, "diplom");
	project->image_ptr = mlx_new_image(project->mlx_ptr, 1000, 600);
	project->begin_str_image = mlx_get_data_addr(project->image_ptr, &bits_per_pixel, &project->size_line, &endian);
	ft_prepare_cube(project);
	ft_prepare_dots(project);
	project->angle = 0;
	project->max_x = 0;
	project->max_y = 0;
	project->max_z = 0;
}

int main(void)
{
	t_project *project;

	if (!(project = (t_project *)malloc(sizeof(t_project))))
		exit(0);
	if (!(project->dot = (t_dot *)malloc(sizeof(t_dot))))
		exit(0);
	if (!(project->cube = (t_cube *)malloc(sizeof(t_cube))))
		exit(0);
	ft_prepare_program(project);
	ft_main_draw(project);
	return (0);
}
