#include "so_long.h"


void render_sprites(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->wnd, game->player.id, game->p_position.x, game->p_position.y);


	mlx_put_image_to_window(game->mlx, game->wnd, game->exit.id, game->e_position.x, game->e_position.y);



}

void render_map(t_game *game)
{
	int x;
	int y;

	x = 32;
	y = 32;
	// esq iz
	mlx_put_image_to_window(game->mlx, game->wnd, game->edge_up_iz.id, 10, 20);

	// edge up
	while (x < (game->wnd_sz.x - 74))
	{
		mlx_put_image_to_window(game->mlx, game->wnd, game->edge_up.id, x, 20);
		x += 32;;
	}

	// esq dr
	mlx_put_image_to_window(game->mlx, game->wnd, game->edge_up_dr.id, x, 20);

	// edge IZ 
	while (y < (game->wnd_sz.y))
	{
		mlx_put_image_to_window(game->mlx, game->wnd, game->edge_iz.id, 10, y);
		y += 32;;
	}
	
	// edge DR 
	y = 32;
	while (y < (game->wnd_sz.y))
	{
		mlx_put_image_to_window(game->mlx, game->wnd, game->edge_dr.id, x, y);
		y += 32;;
	}

	//centro
	y = 52;
	while (y < game->wnd_sz.y)
	{
		x = 34;
		while (x < game->wnd_sz.x - 70) 
		{
			mlx_put_image_to_window(game->mlx, game->wnd, game->centro.id, x, y);
			x += 32;
		}
		y += 32;
	}
}


void render_start(t_game *game)
{
	render_map(game);
	render_sprites(game);
}
