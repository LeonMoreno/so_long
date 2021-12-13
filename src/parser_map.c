#include "so_long.h"


int get_map_size_x(t_game *game, int y)
{
	int i;
	int x;

	x = 0;
	i = 0;
	while(i < y)
	{
		x = ft_strlen(game->map[1]);
		i++;
	}	
	return (x);
}

char *get_next_line(int fd)
{
	char *line;
	char *tmp;
	char c;
	int lu;
	int gx;
	int i;
	
	gx = 1;
	line = malloc(sizeof(char) * gx);
	if (!line)
		return (NULL);
	line[0] = '\0';
	while((lu = read(fd, &c, 1)) && c != '\n')
	{
		gx++;
		tmp = malloc(sizeof(char) * gx);
		if (!tmp)
		{
			free(line);
			return(NULL);
		}
		i = 0;
		while (i < gx -2)
		{
			tmp[i] = line[i];
			i++;
		}
		tmp[i] = c;
		tmp[++i] = '\0';
		free(line);
		line = tmp;
	}
	if (line[0] == '\0')
		return (NULL);
	return (line);
}

t_game parse_map(int fd)
{
	t_game game;
	char *line;
	int gx;
	int i;
	int last;

	i = 0;	
	last = 0;
	gx = 1;
	line = malloc(sizeof(char *) * 1);
	game.map = malloc(sizeof(char *) * 0);
	while ((line = get_next_line(fd)) != NULL)
	{
		game.map = realloc(game.map, sizeof(char *) * gx);
		game.map[i] = line;
		gx++;
		i++;
	}
	game.map_size.y = i;
	game.map[i] = NULL;
	game.map_size.x = get_map_size_x(&game, i);
	return (game);
}
