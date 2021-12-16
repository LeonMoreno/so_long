/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:51:38 by lmoreno           #+#    #+#             */
/*   Updated: 2021/12/16 16:53:11 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	control_player_x(t_game *game, int x)
{
	if (game->map[game->p_position.y / 60][x / 60] == 49)
		return (0);
	else if (game->map[game->p_position.y / 60][x / 60] == 'C')
		game->map[game->p_position.y / 60][x / 60] = '0';
	else if (game->map[game->p_position.y / 60][x / 60] == 'E')
		exit(0);
	return (1);
}

int	control_player_y(t_game *game, int y)
{
	if (game->map[y / 60][game->p_position.x / 60] == 49)
		return (0);
	else if (game->map[y / 60][game->p_position.x / 60] == 'C')
		game->map[y / 60][game->p_position.x / 60] = '0';
	else if (game->map[y / 60][game->p_position.x / 60] == 'E')
		mlx_destroy_window(game->mlx, game->wnd);
	return (1);
}
