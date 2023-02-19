#include "../Incl/so_long.h"

int	check(int keycode, t_data *my_struct)
{
	if (keycode == 36)
		my_struct->start = 1;
	if (keycode == 53 || keycode == 12)
		quit(my_struct);
	else if (my_struct->start != 0)
	{
		if (my_struct->end == 1)
			return (0); 
		if (keycode ==  13 || keycode == 126)
			move_up(my_struct);
		if (keycode == 0 || keycode == 123)
			move_left(my_struct); // Si j'appuie sur q, alors move_left.
		if (keycode == 1 || keycode == 125)
			move_down(my_struct);
		if (keycode == 2 || keycode == 124)
			move_right(my_struct);
		put_map(my_struct);
		return (1);
	}
	return (0);
}

void	quit(t_data *my_struct)
{
	mlx_destroy_window(my_struct->mlx, my_struct->win);
	exit (0);
}

void	move_right(t_data *my_struct)
{
	// ft_printf("%d", my_struct->matrix[my_struct->i])
	if (my_struct->matrix[my_struct->i][my_struct->j + 1] == '1')
		return ;
	else if (my_struct->matrix[my_struct->i][my_struct->j + 1] == 'C')
	{
		my_struct->coin--;
		my_struct->matrix[my_struct->i][my_struct->j] = '0';
		my_struct->matrix[my_struct->i][my_struct->j + 1] = 'P';
	}
	else if (my_struct->matrix[my_struct->i][my_struct->j + 1] == 'E' && my_struct->coin == 0)
		return (quit(my_struct));
	else if (my_struct->matrix[my_struct->i][my_struct->j + 1] == 'E')
		return ;
	else
	{
		my_struct->matrix[my_struct->i][my_struct->j] = '0';
		my_struct->matrix[my_struct->i][my_struct->j + 1] = 'P';
	}
	// my_struct->count_step++;
	my_struct->j++;
}

void	move_left(t_data *my_struct)
{
	if (my_struct->matrix[my_struct->i][my_struct->j - 1] == '1')
		return ;
	else if (my_struct->matrix[my_struct->i][my_struct->j - 1] == 'C')
	{
		my_struct->coin--;
		my_struct->matrix[my_struct->i][my_struct->j] = '0';
		my_struct->matrix[my_struct->i][my_struct->j - 1] = 'P';
	}
	else if (my_struct->matrix[my_struct->i][my_struct->j - 1] == 'E' && my_struct->coin == 0)
		return (quit(my_struct));
	else if (my_struct->matrix[my_struct->i][my_struct->j - 1] == 'E')
		return ;
	else
	{
		my_struct->matrix[my_struct->i][my_struct->j] = '0';
		my_struct->matrix[my_struct->i][my_struct->j - 1] = 'P';
	}
	// my_struct->count_step++;
	my_struct->j--;
}

void	move_up(t_data *my_struct)
{
	if (my_struct->matrix[my_struct->i - 1][my_struct->j] == '1')
		return ;
	// else if (my_struct->matrix[my_struct->i - 1][my_struct->j] == 'M')
	// {
	// 	my_struct->matrix[my_struct->i][my_struct->j] = '0';
	// 	return (game_over(my_struct, my_struct->i - 1, my_struct->j));
	// }
	else if (my_struct->matrix[my_struct->i - 1][my_struct->j] == 'C')
	{
		my_struct->coin--;
		my_struct->matrix[my_struct->i][my_struct->j] = '0';
		my_struct->matrix[my_struct->i - 1][my_struct->j] = 'P';
	}
	else if (my_struct->matrix[my_struct->i - 1][my_struct->j] == 'E' && my_struct->coin == 0)
		return (quit(my_struct));
	else if (my_struct->matrix[my_struct->i - 1][my_struct->j] == 'E')
		return ;
	else
	{
		my_struct->matrix[my_struct->i][my_struct->j] = '0';
		my_struct->matrix[my_struct->i - 1][my_struct->j] = 'P';
	}
	// my_struct->count_step++;
	my_struct->i--;
}

void	move_down(t_data *my_struct)
{
	if (my_struct->matrix[my_struct->i + 1][my_struct->j] == '1')
		return ;
	// else if (my_struct->matrix[my_struct->i + 1][my_struct->j] == 'M')
	// {
	// 	my_struct->matrix[my_struct->i][my_struct->j] = '0';
	// 	return (game_over(my_struct, my_struct->i + 1, my_struct->j));
	// }
	else if (my_struct->matrix[my_struct->i + 1][my_struct->j] == 'C')
	{
		my_struct->coin--;
		my_struct->matrix[my_struct->i][my_struct->j] = '0';
		my_struct->matrix[my_struct->i + 1][my_struct->j] = 'P';
	}
	else if (my_struct->matrix[my_struct->i + 1][my_struct->j] == 'E' && my_struct->coin == 0)
		return (quit(my_struct));
	else if (my_struct->matrix[my_struct->i + 1][my_struct->j] == 'E')
		return ;
	else
	{
		my_struct->matrix[my_struct->i][my_struct->j] = '0';
		my_struct->matrix[my_struct->i + 1][my_struct->j] = 'P';
	}
	// my_struct->count_step++;
	my_struct->i++;
}
