#include "../Incl/so_long.h"
int	error_display(int error_num, int nb_argc)
{
	if (error_num == 1)
		ft_printf("Error: Vous avez entré %d arguments, il en faut 2 pour la compilation.\n", nb_argc);
    return (0); 
}

int	verif_ber(char *str)
{
    int	i, j, x;

	i = 0;
	while (str[i])
		i++;
    i--;
    // printf("\ni: %d", i);
    j = 0;
    x = i - 4;
    // printf("\nx: %d\n", x);
    while(j <= x)
    {
        j++;
    }
    // printf("\nj: %d\n", j);
	while (j <= i)
	{
            if(str[i] != 'r' || (str[i - 1] != 'e') || (str[i - 2] != 'b') || (str[i - 3] != '.'))
            {
                printf("Error: Votre deuxieme argument doit être une carte de type .ber\n");
                return (0);
            }
            i++;
        return(1);
    }
    return (1);
}

int error_argc2(int argc, char **argv)
{
	int	i, x;

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