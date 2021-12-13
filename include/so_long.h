#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "../libft/include/libft.h"

#define WIN_W 40
#define WIN_H 40


// Estructuras

typedef struct s_vector {
	int x;
	int y;
}	t_vector;

// Imagen del map
typedef struct s_img_map {
	void 		*id;
	t_vector	imap_sz;
}	t_img_map;

typedef struct s_sprite {
	void 	*id;
	t_vector	sp_sz;
	char		*bits;
	int			bits_per_pixel;
	int			sz_line;
	int			endian;
}	t_sprite;

typedef struct s_game {
	void 		*mlx;
	void 		*wnd;
	t_vector	wnd_sz;	
	t_vector	map_size;
	t_img_map	wall_up_map;
	t_img_map	centro_map;
	t_sprite	sprite;
	t_vector	sprite_position;
	int			colle;
	int			p_start;
	char 		**map;
}	t_game;

//Map functions
t_game		init_map(char *map);
int			open_map(char *map);
t_game 		parse_map(int fd);
char *get_next_line(int fd);
int		check_map(t_game *game);
int valid_wall(char **str, int last);

// start game
void game_init(t_game *game);
void ft_new_window(t_game *game, char *msg);

// Misc
void error(char *s);


#endif

