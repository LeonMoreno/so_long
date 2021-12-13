#include "so_long.h"

void game_init(t_game *game)
{
	game->mlx = mlx_init();
	ft_new_window(game, "lmoreno So_Long");

	mlx_loop(game->mlx);
}
		   	
