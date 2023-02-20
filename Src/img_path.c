#include "../Incl/so_long.h"

void    create_img(t_data *my_struct)
{
    int x;
    int y;
    int index;

	my_struct->path = (void **)malloc(sizeof(void **) * 6);
	my_struct->img = (void **)malloc(sizeof(void **) * 6);
	my_struct->path[0] = "./image/layers.xpm"; //background
	my_struct->path[1] = "./image/wall.xpm"; // mur
	my_struct->path[2] = "./image/player.xpm"; // player
	my_struct->path[3] = "./image/open_exit.xpm"; // porte de sortie une fois tt manger.
	my_struct->path[4] = "./image/exit.xpm"; // la porte de sortie
	my_struct->path[5] = "./image/burger.xpm";
	index = -1;
	while (++index < 6)
	{
		my_struct->img[index] = mlx_xpm_file_to_image(my_struct->mlx, my_struct->path[index], &x, &y);
	}
	if (!my_struct->img[0]|| !my_struct->img[1] || !my_struct->img[2] || !my_struct->img[3]
 	|| !my_struct->img[4] || !my_struct->img[5])
 	{
		destroy_img(my_struct);
		printf("%s", "Error\n");
		exit(EXIT_FAILURE);
	}

}



void destroy_img(t_data *my_struct)
{
 if (my_struct->img[0])
     mlx_destroy_image(my_struct->mlx, my_struct->img[0]);
 if (my_struct->img[1])
     mlx_destroy_image(my_struct->mlx, my_struct->img[1]);
 if (my_struct->img[2])
     mlx_destroy_image(my_struct->mlx, my_struct->img[2]);
 if (my_struct->img[3])
     mlx_destroy_image(my_struct->mlx, my_struct->img[3]);
 if (my_struct->img[4])
     mlx_destroy_image(my_struct->mlx, my_struct->img[4]);
 if (my_struct->img[5])
     mlx_destroy_image(my_struct->mlx, my_struct->img[5]);
}
	
