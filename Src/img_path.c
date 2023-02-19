#include "../Incl/so_long.h"

void    create_img(t_data *my_struct)
{
    int x;
    int y;
	int index;

	my_struct->path = (void **)malloc(sizeof(void **) * 9);
	my_struct->img = (void **)malloc(sizeof(void **) * 9);
	my_struct->path[0] = "./image/layers.xpm"; //background
	my_struct->path[1] = "./image/wall.xpm"; // mur
	my_struct->path[2] = "./image/player.xpm"; // player
	my_struct->path[3] = "./image/open_exit.xpm"; // porte de sortie une fois tt manger.
	my_struct->path[4] = "./image/exit.xpm"; // la porte de sortie
	my_struct->path[5] = "./image/pizza.xpm";
	my_struct->path[6] = "./image/burger.xpm";
	my_struct->path[7] = "./image/burrito.xpm";
	my_struct->path[8] = "./image/cookies.xpm";
	index = -1;
	while (++index < 10)
		my_struct->img[index] = mlx_xpm_file_to_image(my_struct->mlx, my_struct->path[index], &x, &y);
}

	
	
