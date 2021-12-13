#include "so_long.h"

void ft_render(t_game *game)
{
	int i;

	i = 0;
	mlx_clear_window(game->mlx_ptr, game->window.id);

	mlx_put_image_to_window(game->mlx_ptr, game->window.id, game->sprite.id, game->sprite_position.x, game->sprite_position.y);

	while (i < 1280)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window.id, game->map.id, i, game->map_position.y);

		i += 30;
	}
	
	i = 0;
	while (i < 1280)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window.id, game->wall_r.id, i, 210);
		i += 30;
	}

	i = 30;
	while (i <= 210)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window.id, game->wall_dr.id, 0, i);
		i += 30;
	}
	i = 30;
	while (i <= 210)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window.id, game->wall_iz.id, 1250, i);
		i += 30;
	}
	
	i = 30;
	while (i <= 1250)
	{
		int j = 30;
		while (j < 210)
		{
		mlx_put_image_to_window(game->mlx_ptr, game->window.id, game->wall_cen.id, i, j);
		j += 30;
		}
		i += 30;
	}
	
}


