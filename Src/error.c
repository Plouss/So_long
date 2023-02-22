#include "../Incl/so_long.h"

int	error_display(int error_num, int nb_argc)
{
	if (error_num == 1)
		ft_printf("Error\nVous avez entré %d arguments au lieu de 2.\n", nb_argc);
	exit(EXIT_FAILURE);
}

int	verif_ber(char *str)
{
	// int	i;
	// int	j;
	int	x;

	// i = 0;
	ft_strlen(str);
	// i--;
	// j = 0;
	x = strlen(str);
	x--;
	printf("x:%d\n", x);
	if (str[x] == 'r')
	{
		printf("r:%c\n", str[x]);
		x--;
		if (str[x] == 'e')
		{
			printf("e:%c\n", str[x]);
			x--;
			if (str[x] == 'b')
			{
				printf("b:%c\n", str[x]);
				x--;
				if (str[x] == '.')
				{
					printf(".:%c\n", str[x]);
				}
			}
		}
	}
	else
	{
		printf("\nError\nLa map doit  de type .ber\n");
		exit(EXIT_FAILURE);
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