#include "so_long.h"

t_image ft_new_sprite (void *mlx, char *file)
{
	t_image image;
	
	image.id = mlx_xpm_file_to_image(mlx, file, &image.size.x, &image.size.y);
	image.pixels = mlx_get_data_addr(image.id, &image.bits_per_pixel, &image.size_line, &image.endian);

	return (image);
}
