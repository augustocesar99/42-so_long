# include "../include/so_long.h"

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

int main(void)
{
    void	*mlx_ptr;

    mlx_ptr = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!", true);
	mlx_loop(mlx_ptr);
	mlx_terminate(mlx_ptr);
    free(mlx_ptr);
}