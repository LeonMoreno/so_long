#include "so_long.h"

int ft_close()
{
	exit(0);
}

void ft_new_window(t_game *game, char *msg)
{
	game->wnd_sz.x = game->map_size.x * WIN_W;
	game->wnd_sz.y = game->map_size.y * WIN_H;
	game->wnd = mlx_new_window(game->mlx, game->wnd_sz.x, game->wnd_sz.y, msg);

	mlx_hook(game->wnd, 17, 0, ft_close, 0);
	printf("x %s\n", msg);
	printf("x %d\n", game->wnd_sz.x);
	printf("mlx %p\n", game->mlx);
	printf("y %d\n", game->wnd_sz.y);
}
