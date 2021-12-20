/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:15:17 by lmoreno           #+#    #+#             */
/*   Updated: 2021/12/20 13:24:02 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_start(t_game *game)
{
	int	x;

	x = 0;
	mlx_clear_window(game->mlx, game->wnd);
	x = render_map_x(game);
	render_map_y(game, x);
	render_sprites(game);
	render_muro_inter(game);
	render_coin(game);
	count_moves(game);
	if (game->control_exit == 1)
	{
		string_put(game);
		game->control_exit = 0;
	}
}

