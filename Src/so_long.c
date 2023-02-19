#include "../Incl/so_long.h"

void initialize(t_data  *my_struct)
{
    my_struct->check_e = 0;
    my_struct->check_p = 0;
    my_struct->coin = 0;
    // my_struct->x = 0;
    // my_struct->y = 0;
    my_struct->count_step = 0;
}

int main(int argc, char **argv)
{
    t_data my_struct;

    if (argc != 2)
        error_display(1, argc);
    error_argc2(argc, argv);
    initialize(&my_struct);
    my_struct.map = argv[1]; // Je définis ma map en lui donnant la valeur d'argv[1], je vais ensuite l'utiliser pour open().
    if (matrix_filling(&my_struct) == 0) // S'il ya une erreur, return 0.
        return (0);
    my_struct.mlx = mlx_init();
        printf("\n%d\n ; ", my_struct.coin);
    create_img    (&my_struct); // Je mets mes chemins dans my_struct->path pour ensuite l'utiliser dans mlx_xpm_file_to_image( void *mlx_ptr, char *filename, int *width, int *height )
        printf("\n%d\n ; ", my_struct.coin);
    my_struct.win = mlx_new_window(my_struct.mlx, my_struct.width * 32, my_struct.height * 32, "So_long"); // Affiche la nouvel fenêtre.
        printf("\n%d\n ; ", my_struct.coin);
    put_map(&my_struct);
        printf("\n%d\n ; ", my_struct.coin);
    my_struct.loop = 0;
    mlx_hook(my_struct.win, 3, 0, check, &my_struct);
    mlx_loop(my_struct.mlx);
}