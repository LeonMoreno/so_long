#include "so_long.h"

int main(int argc, char **argv)
{
	t_game game;

	if (argc == 2)
	{
		game = init_map(argv[1]);	
		if(game.map == NULL)
			return (0);
		game_init(&game);
	}
	else
		error("Invalid number of arguments");
	return (0);	
}
