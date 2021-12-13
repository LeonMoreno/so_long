#include "so_long.h"

t_image ft_new_map(void *mlx, char *file)
{
	t_image map;
	
	map.id = mlx_xpm_file_to_image(mlx, file, &map.size.x, &map.size.y);
	map.pixels = mlx_get_data_addr(map.id, &map.bits_per_pixel, &map.size_line, &map.endian);

	return (map);
}
