#include "so_long.h"

t_sprite open_sprites(void *mlx, char *file)
{
	t_sprite	sprite;

	sprite.id = mlx_xpm_file_to_image(mlx, file, &sprite.size.x, &sprite.size.y);
	
	sprite.bits = mlx_get_data_addr(sprite.id, &sprite.bpp, &sprite.sz_line, &sprite.endian);
	
	return (sprite);
}

t_img_map open_img_map(void *mlx, char *file)
{
	t_img_map	img_map;

	img_map.id = mlx_xpm_file_to_image(mlx, file, &img_map.size.x, &img_map.size.y);

	return (img_map);
}

void xpm_image(t_game *game)
{

	// wall_up	
	game->edge_up = open_img_map(game->mlx, "sprites/grass1.xpm");
	
	// centro
	game->centro = open_img_map(game->mlx, "sprites/centre.xpm");
	
	// esq up derecha
	game->edge_up_dr = open_img_map(game->mlx, "sprites/grass_corner_right.xpm");

	// esq up iz
	game->edge_up_iz = open_img_map(game->mlx, "sprites/grass_corner_left.xpm");

	// borde dr
	game->edge_dr = open_img_map(game->mlx, "sprites/edge_right.xpm");

	// borde iz 
	game->edge_iz = open_img_map(game->mlx, "sprites/edge_left.xpm");

	// borde Inferior 
	game->edge_bottom = open_img_map(game->mlx, "sprites/edge_bottom.xpm");

	// Exit 
	game->exit = open_img_map(game->mlx, "sprites/exit.xpm");
	
	// Player 
	game->player = open_sprites(game->mlx, "sprites/ant_player.xpm");
	
	// Muro Inter 
	game->rock = open_img_map(game->mlx, "sprites/rock.xpm");
	
	// Coin 
	game->coin = open_img_map(game->mlx, "sprites/coin1.xpm");
}
