#include "../Incl/so_long.h"

bool check_walls(t_data my_struct)
{
    int i;

    i = -1;
    while (++i < my_struct.width)
    {
        if (my_struct.matrix[0][i] != '1' || my_struct.matrix[my_struct.height - 1][i] != '1')
            return (false);
    }
    i = 0;
    while (++i < my_struct.height - 1) // Check les colones aux extremité
    {
        if (my_struct.matrix[i][0] != '1' || my_struct.matrix[i][my_struct.width - 1] != '1')
            return (false);
    }
    return (true);
}

bool check_different(t_data my_struct)
{
	int	i;
	int	j;

	i = -1;
	while (++i < my_struct.height)
	{
		j = -1;
		while (++j < my_struct.width)
		{
			if (my_struct.matrix[i][j] != '1' && my_struct.matrix[i][j] != 'C'
			&& my_struct.matrix[i][j] != 'P'
			&& my_struct.matrix[i][j] != 'E' && my_struct.matrix[i][j] != '0')
				return (false);
		}
	}
	return (true);
}
int	check_rectangle(t_data my_struct)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < my_struct.height)
	{
		j = 0;
		while (my_struct.matrix[i][j] != '\0')
			j++;
		if (j != my_struct.width)
			return (0);
		i++;
	}
	return (1);
}
bool	check_exit_player_coin(t_data *my_struct)
{
	int x = -1;
	int y;
	while (++x < my_struct->height)
	{
		y = -1;
		while (++y < my_struct->width)
		{
			if (my_struct->matrix[x][y] == 'P')
			{
				my_struct->i = x;
				my_struct->j = y;
				my_struct->check_p++;
			}
			if (my_struct->matrix[x][y] == 'E')
				my_struct->check_e++;
			if (my_struct->matrix[x][y] == 'C')
				my_struct->coin++;
		}
	}
	if (my_struct->check_p != 1 || my_struct->check_e < 1 || my_struct->coin == 0)
		return (false);
	return (true);
}