#include "so_long.h"

void game_init(t_game *game)
{
	game->mlx = mlx_init();
	new_window(game, "lmoreno So_Long");
	xpm_image(game);


	ft_printf("% mlx : %p\n", game->mlx);
	ft_printf("% windw : %p\n", game->wnd);
	ft_printf("ptr %p\n", game->edge_iz.id);
	
	mlx_loop(game->mlx);
}
		   	
