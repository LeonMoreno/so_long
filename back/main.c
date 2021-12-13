#include "so_long.h"

int main(void)
{
	//Declaro variable tipo struct prog
	t_game game;
	
	// inicializo mlx - save return void en estructura
	game.mlx_ptr = mlx_init();

	// creo la ventana - save return struc
	game.window = ft_new_window(game.mlx_ptr, 1280, 240, "lmoreno so_Long");

	// Imagen mapa
	game.map = ft_new_map(game.mlx_ptr, "wall.xpm");
	game.map_position.x = 0;
	game.map_position.y = 0;
	mlx_put_image_to_window(game.mlx_ptr, game.window.id, game.map.id, game.map_position.x, game.map_position.y);
	
	// Imagen sprite
	game.sprite = ft_new_sprite(game.mlx_ptr, "lion.xpm");
	game.sprite_position.x = 60;
	game.sprite_position.y = 79;
//	mlx_put_image_to_window(game.mlx_ptr, game.window.id, game.sprite.id, game.sprite_position.x, game.sprite_position.y);

	game.wall_r = ft_new_map(game.mlx_ptr, "wall_r.xpm");
	game.wall_dr = ft_new_map(game.mlx_ptr, "wall_dr.xpm");
	game.wall_iz = ft_new_map(game.mlx_ptr, "wall_iz.xpm");
	game.wall_cen = ft_new_map(game.mlx_ptr, "centre.xpm");
	
	ft_render(&game);
	//printf("sprite.position.x = %d\n", game.sprite_position.x);
	//printf("game.sprite.size.x = %d\n", game.sprite.size.x);

	// hook the input() a la tecla oprimida
	mlx_key_hook(game.window.id, *ft_input, &game);

	mlx_loop_hook(game.mlx_ptr, *ft_update, &game);	

	// funcion loop que espera eventos
	mlx_loop(game.mlx_ptr);
	return (0);
}
