#include "so_long.h"

int ft_close()
{
	exit(0);
}

void new_window(t_game *game, char *msg)
{
	game->wnd_sz.x = game->map_size.x * WIN_W;
	game->wnd_sz.y = game->map_size.y * WIN_H;
	game->wnd = mlx_new_window(game->mlx, game->wnd_sz.x, game->wnd_sz.y, msg);
	//game->wnd = mlx_new_window(game->mlx, 200, 800, msg);

	mlx_hook(game->wnd, 17, 0, ft_close, 0);
}
