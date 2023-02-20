#include "../Incl/so_long.h"
void	put_img(t_data *my_struct, int i, int j)
{
    if (my_struct->matrix[i][j] == '0') // If 0, display background
        mlx_put_image_to_window(my_struct->mlx, my_struct->win, my_struct->img[0], j * 32, i * 32);
    if (my_struct->matrix[i][j] == '1') // If 1, display walls
        mlx_put_image_to_window(my_struct->mlx, my_struct->win, my_struct->img[1], j * 32, i * 32);
    if (my_struct->matrix[i][j] == 'C') //If C, display coin
		mlx_put_image_to_window(my_struct->mlx, my_struct->win, my_struct->img[5], j * 32, i * 32);
	if (my_struct->matrix[i][j] == 'P') // If P, display player
		mlx_put_image_to_window(my_struct->mlx, my_struct->win, my_struct->img[2], j * 32, i * 32);
	if (my_struct->coin == 0 && my_struct->matrix[i][j] == 'E') // If E and there are no more coin, display exit door
		mlx_put_image_to_window(my_struct->mlx, my_struct->win, my_struct->img[3], j * 32, i * 32);
	else if (my_struct->matrix[i][j] == 'E') // If E, display simple door
		mlx_put_image_to_window(my_struct->mlx, my_struct->win, my_struct->img[4], j * 32, i * 32);
}

void    put_map(t_data  *my_struct)
{
    int i;
    int j; 

    i = -1;
    while (++i < my_struct->height)
    {
        j = -1;
		while (++j < my_struct->width)
			put_img(my_struct, i, j); // Display my width;
    }
    
}



















// bool	check_exit_and_player(t_data *v)
// {
//   	v->y = -1;
// 	while (++v->y < v->height)
// 	{
// 		v->x = -1;
// 		while (++v->x < v->width)
// 		{
// 			if (v->matrix[v->y][v->x] == 'P')
// 			{
// 				v->i = v->y;
// 				v->j = v->x;
// 				v->check_p++;
// 			}
// 			if (v->matrix[v->y][v->x] == 'E')
// 				v->check_e++;
// 			if (v->matrix[v->y][v->x] == 'C')
// 				v->coin++;
// 		}
// 	}
// 	if (v->check_p != 1 || v->check_e < 1 || v->coin == 0)
// 		return (false);
// 	return (true);
// }

















