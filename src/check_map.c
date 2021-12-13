#include "so_long.h"

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

int valid_point_p(char **str, int last)
{
	int i;

	i = 1;
	while(i < (last - 1))
	{
		if (ft_strchr(str[i], 'P'))
			return (1);
		i++;
	}
	return (0);
}

int valid_point_e(char **str, int last)
{
	int i;

	i = 1;
	while(i < (last - 1))
	{
		if (ft_strchr(str[i], 'E'))
			return (1);
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
	if(!valid_point_p(game->map, game->map_size.y))
	{
		error("There must be at least one P");
		return(0);
	}
	if(!valid_point_e(game->map, game->map_size.y))
	{
		error("There must be at least one Point 'E' Exit");
		return(0);
	}
	return (1);
}
