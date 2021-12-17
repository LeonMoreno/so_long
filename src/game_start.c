/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:55:00 by lmoreno           #+#    #+#             */
/*   Updated: 2021/12/17 13:00:16 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	new_window(game, "lmoreno So_Long");
	xpm_image(game);
	render_start(game);
	mlx_key_hook(game->wnd, key_hook, game);
	ft_printf("% mlx : %p\n", game->mlx);
	ft_printf("% windw : %p\n", game->wnd);
	ft_printf("Rock : %p\n", game->rock.id);
	ft_printf("% map size_X : %d\n", game->map_size.x);
	ft_printf("% map size_Y : %d\n", game->map_size.y);
	ft_printf("edge_up_iz size  X: %d\n", game->edge_up_iz.size.x);
	ft_printf("edge_up_iz size  Y: %d\n", game->edge_up_iz.size.y);
	ft_printf("% Win size_X : %d\n", game->wnd_sz.x);
	ft_printf("% Win size_Y : %d\n", game->wnd_sz.y);
	ft_printf("#### P Pos_X : %d\n", game->p_position.x);
	ft_printf("#### P Pos_Y : %d\n", game->p_position.y);
	ft_printf("EE  Pos_X : %d\n", game->e_position.x);
	ft_printf("EE  Pos_Y : %d\n", game->e_position.y);
	ft_printf("Valor colle : %d\n", game->colle);
	mlx_loop(game->mlx);
}
