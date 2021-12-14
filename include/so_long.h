#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <fcntl.h>

#include "../libft/include/libft.h"

#define WIN_W 60
#define WIN_H 60


// Estructuras

typedef struct s_vector {
	int x;
	int y;
}	t_vector;

// Imagen del map
typedef struct s_img_map {
	void 		*id;
	t_vector	size;
}	t_img_map;

typedef struct s_sprite {
	void 	*id;
	t_vector	size;
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
	t_img_map	edge_up;
	t_img_map	centro;
	t_img_map	edge_up_dr;
	t_img_map	edge_up_iz;
	t_img_map	edge_dr;
	t_img_map	edge_iz;
	t_img_map	edge_bottom;
	t_img_map	exit;
	t_sprite	player;
	t_vector	p_position;
	t_vector	e_position;
	int			colle;
	int			p_start;
	char 		**map;
}	t_game;

//Map functions
t_game		init_map(char *map);
int			open_map(char *map);
void 		parse_map(int fd, t_game *game);
char *get_next_line(int fd);
int		check_map(t_game *game);
int valid_wall(char **str, int last);
int get_map_size_y(int fd);

// start game
void game_init(t_game *game);
void new_window(t_game *game, char *msg);
void xpm_image(t_game *game);
void render_start(t_game *game);

// Misc
void error(char *s);


#endif

