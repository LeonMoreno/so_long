#include "so_long.h"

int control_player_x(t_game *game, int x)	
{
	if(game->map[game->p_position.y / 60][x / 60] == 49)
		return (0);
	else if(game->map[game->p_position.y / 60][x / 60] == 'C')
		game->map[game->p_position.y / 60][x / 60] = '0';
	return (1);
}

int control_player_y(t_game *game, int y)	
{
	if(game->map[y / 60][game->p_position.x / 60] == 49)
		return (0);
	else if(game->map[y / 60][game->p_position.x / 60] == 'C')
		game->map[y / 60][game->p_position.x / 60] = '0';
	return (1);
}

