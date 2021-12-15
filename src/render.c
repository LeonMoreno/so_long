#include "so_long.h"

void render_muro_inter(t_game *game)
{
	int y;
	int x;

	y = 1;

	while(y < game->map_size.y - 1)
	{
		x = 1;
		while(x < game->map_size.x - 1)
		{
			if(game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->wnd, game->rock.id, x * WIN_W, y * WIN_H);
			x++;
		}
		y++;
	}
}

void render_coin(t_game *game)
{
	int y;
	int x;

	y = 1;

	while(y < game->map_size.y - 1)
	{
		x = 1;
		while(x < game->map_size.x - 1)
		{
			if(game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->wnd, game->coin.id, x * WIN_W, y * WIN_H);
			x++;
		}
		y++;
	}
}


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
	mlx_clear_window(game->mlx, game->wnd);
	render_map(game);
	render_sprites(game);
	render_muro_inter(game);
	render_coin(game);
}
