#include "so_long.h"

int ft_close()
{
	exit(0);
}

t_window ft_new_window(void *mlx, int wd, int high, char *title)
{
	t_window window;

	window.id = mlx_new_window (mlx, wd, high, title);
	window.size.x = wd;
	window.size.y = high;
	mlx_hook(window.id, 17, 0, ft_close, 0);
	return (window);
}
