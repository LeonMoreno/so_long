/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:51:38 by lmoreno           #+#    #+#             */
/*   Updated: 2021/12/17 14:26:11 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	control_player_x(t_game *game, int x)
{
	if (game->map[game->p_position.y / 60][x / 60] == 49)
		return (0);
	else if (game->map[game->p_position.y / 60][x / 60] == 'C')
	{
		game->colle--;
		ft_printf("Colle : %d\n", game->colle);
		game->map[game->p_position.y / 60][x / 60] = '0';
	}
	else if (game->map[game->p_position.y / 60][x / 60] == 'E')
	{
		if (game->colle != 0)
			return (1);
		else if (game->colle == 0)
		exit(0);
	}
	return (1);
}

int	control_player_y(t_game *game, int y)
{
	if (game->map[y / 60][game->p_position.x / 60] == 49)
		return (0);
	else if (game->map[y / 60][game->p_position.x / 60] == 'C')
	{
		game->colle--;
		ft_printf("Colle : %d\n", game->colle);
		game->map[y / 60][game->p_position.x / 60] = '0';
	}
	else if (game->map[y / 60][game->p_position.x / 60] == 'E')
	{
		if (game->colle != 0)
		{
			string_put(game);
			ft_printf("No puedes Salir\n");
		}
		else if (game->colle == 0)
		exit(0);
	}
	return (1);
}
