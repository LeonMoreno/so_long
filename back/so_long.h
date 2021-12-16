#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

// ----------------------------------
// MACROS

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif

// ----------------------------------

typedef struct s_vector {
	int x;
	int y;
}	t_vector;

typedef struct s_image {
	void 		*id;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}	t_image;

typedef struct s_window {
	void *id;
	t_vector size;
}	t_window;

typedef struct s_game {
	void *mlx_ptr;
	t_window window;
	t_image sprite;
	t_image map;
	t_image wall_r;
	t_image wall_dr;
	t_image wall_iz;
	t_image wall_cen;
	t_vector sprite_position;
	t_vector screen_res;
	t_vector map_position;
}	t_game;


// funciones
t_window ft_new_window(void *mlx, int wd, int high, char *title);
t_image	ft_new_sprite(void *mlx, char *file);
t_image	ft_new_map(void *mlx, char *file);
int ft_input(int key, void *param);
int ft_update(void *prog);
void ft_render(t_game *game);

#endif
