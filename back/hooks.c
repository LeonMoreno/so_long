#include "so_long.h"

int ft_input(int key, void *param)
{
	t_game *prog = (t_game *)param;

	//mlx_clear_window(prog->mlx_ptr, prog->window.id);
	
	if (key == 124)
		//prog->sprite_position.x += prog->sprite.size.x;
		prog->sprite_position.x += 30;
	else if (key == 123)
		prog->sprite_position.x -= prog->sprite.size.x;	
	else if (key == 125)
		prog->sprite_position.y += prog->sprite.size.y;	
	else if (key == 126)
		prog->sprite_position.y -= prog->sprite.size.y;	
	else if (key == 53)
		exit(0);	
	
	// Funcion que actualiza la poscicion del sprite
	// la posicion inicial fue 0,0 arriba a la iz.
	//mlx_put_image_to_window(prog->mlx_ptr, prog->window.id, prog->sprite.id, prog->sprite_position.x, prog->sprite_position.y);	
	
	printf("Key press %d\n", key);
	printf("sprite.position.x = %d\n", prog->sprite_position.x);
	printf("sprite.position.y = %d\n", prog->sprite_position.y);
	printf("------------\n");

	ft_render(param);
	
	return (0);
}

int ft_update(void *param)
{
	t_game *program = (t_game *)param;
	static int frame;

	frame++;
	if(frame == ANIMATION_FRAMES)
        program->sprite_position.y += 1;
    // every x*2 frames go back that pixel to loop the animation
    else if (frame >= ANIMATION_FRAMES * 2)
    {
        program->sprite_position.y -= 1;
        frame = 0;
    }
    
    mlx_put_image_to_window(program->mlx_ptr, program->window.id,
        program->sprite.id, program->sprite_position.x, program->sprite_position.y);

    return (0);
}
