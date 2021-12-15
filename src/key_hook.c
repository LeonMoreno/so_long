#include "so_long.h"

int key_hook(int key, t_game *game)
{
	int j;

	j = 0;
	if(key == 124)
	{//game->p_position.x += game->player.size.x;
		if(control_player_x(game, j = game->p_position.x + WIN_W))
			game->p_position.x += WIN_W;
	}

	if(key == 123) 
		//game->p_position.x -= game->player.size.x;
		if(control_player_x(game, j = game->p_position.x - WIN_W))
			game->p_position.x -= WIN_W;
	
	if(key == 125)
		if(control_player_y(game, j = game->p_position.y + WIN_H))
			game->p_position.y += WIN_H;

	if(key == 126)
		if(control_player_y(game, j = game->p_position.y - WIN_H))
			game->p_position.y -= WIN_H;
	
	if(key == 53)
		exit(0);
	
	ft_printf("Key press: %d\n", key);
	ft_printf("PLayer.Pos.X.Y : %d.%d\n", game->p_position.x, game->p_position.y);

	render_start(game);
	return (0);
}
