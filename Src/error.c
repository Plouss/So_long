#include "../Incl/so_long.h"

int	error_display(int error_num, int nb_argc)
{
	if (error_num == 1)
		ft_printf("Error\nVous avez entré %d arguments au lieu de 2.\n", nb_argc);
	return (0);
}

int	verif_ber(char *str)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	while (str[i])
		i++;
	i--;
	j = 0;
	x = i - 4;
	while (j <= x)
		j++;
	while (j <= i)
	{
		if ((str[i] != 'r' && (str[i - 1] != 'e') && (str[i - 2] != 'b'))
			|| (str[i - 3] != '.'))
		{
			printf("%c %c %c", str[i], str[i - 1], str[i - 2]);
			printf("Error\nLa map doit  de type .ber\n");
			exit(EXIT_FAILURE);
			return (0);
		}
		i++;
	}
	return (1);
}

int	error_argc2(int argc, char **argv)
{
	int	i;
	int	x;

	i = 1;
	x = 0;
	while (i < argc)
	{
		if (i == 1)
		{
			while (argv[x])
			{
				verif_ber(argv[i]);
				x++;
			}
		}
		i++;
	}
	return (0);
}