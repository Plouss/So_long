#include "../Incl/so_long.h"
#include <time.h>
#include <stdio.h>

int	matrix_filling(t_data *my_struct)
{
	int		fd;
	char	*line;

	my_struct->width = 0;
	my_struct->end = 0;
	fd = open(my_struct->map, O_RDONLY);
	line = get_next_line(fd);
	my_struct->matrix = ft_split(line, '\n', my_struct);
	my_struct->matrix_path_find = ft_split(line, '\n', my_struct);
	while (my_struct->matrix[0][my_struct->width] != '\0')
		my_struct->width++;
	if (!check_walls(*my_struct) || !check_exit_player_coin(my_struct)
		|| !check_different(*my_struct) || !check_rectangle(*my_struct))
		exit(EXIT_FAILURE);
	if (path_find(my_struct, my_struct->i, my_struct->j) < 0)
	{
		ft_printf("Error\nIl n'y a pas de chemin pour sortir du labyrinthe");
		exit (EXIT_FAILURE);
	}
	close(fd);
	free(line);
	return (1);
}
