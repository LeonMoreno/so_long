#include "so_long.h"

int open_map(char *map)
{
	int fd;

	if(!ft_strnstr(map, "ber", 20))
	{
			error("Invalid extension");
			return(0);
	}
	fd = open(map, O_RDONLY);
	return (fd);
}

t_game init_map(char *map)
{
	t_game game;
	int fd;

	fd = open_map(map);
	if (fd == 0)
	{
		game.map = NULL;
		return (game);
	}
	game = parse_map(fd);
	if(!check_map(&game))
	{
		game.map = NULL;
		return (game);
	}
	return (game);
}
