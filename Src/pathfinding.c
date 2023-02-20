#include "../Incl/so_long.h"

int path_find(t_data *my_struct, int i, int j)
{
// (i:3 || j;1)(i:2 || j;1)(i:1 || j;1)(i:0 || j;1)(i:-1 || j;1)(i:-2 || j;1)(i:-3 || j;1)(i:-4 || j;1)(i:-5 || j;1)(i:-6 || j;1)(i:-7 || j;1)(i:-8 || j;1)(i:-9 || j;1)(i:-10 || j;1)(i:-11 || j;1)(i:-12 || j;1)(i:-13 || j;1)(i:-14 || j;1)(i:-15 || j;1)(i:-16 || j;1)(i:-17 || j;1)

    // char *up;
    // char *down;
    // char *left;
    // char *right;
    // int x;

    // x = my_struct->check_e;

    // up = &my_struct->matrix[my_struct->i - 1][my_struct->j];
    // down = &my_struct->matrix[my_struct->i + 1][my_struct->j];
    // left = &my_struct->matrix[my_struct->i][my_struct->j - 1];
    // right = &my_struct->matrix[my_struct->i][my_struct->j + 1];

    // if(my_struct->matrix[my_struct->i][my_struct->j] == 'C')
    //     return (0
    if (my_struct->check_e == 0)
    {
        printf("X:%d\n", my_struct->check_e);
        return (0);
    }
    if(my_struct->matrix_path_find[i][j] == 'E')
        my_struct->check_e--;
    my_struct->matrix_path_find[i][j] = '9';
    printf("(i:%d, j;%d)\n", i, j);
    if (my_struct->matrix_path_find[i - 1][j] != '1' && my_struct->matrix_path_find[i - 1][j] != '9')
        path_find(my_struct, i - 1, j);
    if (my_struct->matrix_path_find[i + 1][j] != '1' && my_struct->matrix_path_find[i + 1][j] != '9')
        path_find(my_struct, i + 1, j);
    if (my_struct->matrix_path_find[i][j - 1] != '1' && my_struct->matrix_path_find[i][j - 1] != '9')
        path_find(my_struct, i, j - 1);
    if (my_struct->matrix_path_find[i][j + 1] != '1' && my_struct->matrix_path_find[i][j + 1] != '9')
        path_find(my_struct, i, j + 1); 
    if (my_struct->check_e == 0)
    {
        // printf("X:%d\n", my_struct->check_e);
        return (0);
    }
    return (-1);
}
