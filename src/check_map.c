#include "so_long.h"

int ft_strchrx(char *str, char c)
{
	int i;
	
	i = 0;
	while(str[i])
	{
		if(str[i] == c)
			return (i);
		i++;
	}
	return (0);
}


int valid_collec(char **str, int last)
{
	int i;

	i = 1;
	while(i < (last - 1))
	{
		if (ft_strchr(str[i], 'C'))
			return (1);
		i++;
	}
	return (0);
}

int valid_point_p(t_game *game)
{
	int i;
	int x;
	
	i = 1;
	while(i < (game->map_size.y - 1))
	{
		if ((x = (ft_strchrx(game->map[i], 'P'))))
		{
			game->p_position.y = i * WIN_H;
			game->p_position.x  = x * WIN_W;
			return (1);
		}
		i++;
	}
	return (0);
}

int valid_point_e(t_game *game)
{
	int i;
	int x;

	i = 1;
	while(i < (game->map_size.y - 1))
	{
		if ((x = (ft_strchrx(game->map[i], 'E'))))
		{
			game->e_position.y = i * WIN_H;
			game->e_position.x = x * WIN_W;
			return (1);
		}
		i++;
	}
	return (0);
}


int valid_wall_inter(char **str, int last)
{
	int i;

	i = 1;
	while (i < (last - 1))
	{
		if (str[i][0] != 49 || str[i][ft_strlen(str[i]) - 1] != 49)
			return (0);
		i++;
	}
	return (1);
}

int valid_wall(char **str, int last)
{
	int i;

	i = 0;
	while (str[0][i] && str[last -1][i])
	{
		if (str[0][i] != 49 || str[last -1][i] != 49)
			return (0);
		i++;
	}
	return (1);
}

int check_map(t_game *game)
{
	if(!valid_wall(game->map, game->map_size.y))
	{
		error("Wall not Valid");
		return(0);
	}
	if(!valid_wall_inter(game->map, game->map_size.y))
	{
		error("Wall not Valid");
		return(0);
	}
	if(!valid_collec(game->map, game->map_size.y))
	{
		error("There must be at least one C");
		return(0);
	}
	if(!valid_point_p(game))
	{
		error("There must be at least one P");
		return(0);
	}
	if(!valid_point_e(game))
	{
		error("There must be at least one Point 'E' Exit");
		return(0);
	}
	return (1);
}
