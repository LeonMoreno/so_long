#include "so_long.h"

int main(int argc, char **argv)
{
	t_game game;

	if (argc == 2)
	{
		game = init_map(argv[1]);	
		game_init(&game);
	}
	else
		error("Invalid number of arguments");
	//ft_printf("Lineas game.map.size.y %d \n", game.map_size.y); 
	
	return (0);	
}
