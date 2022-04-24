#include "game_of_life.h"

t_vars	get_scrn_size(t_vars vars)
{
	vars.scrn.height = 0;
	vars.scrn.width = ft_strlen(vars.map[0]) * 8;
	while (vars.map[vars.scrn.height++]);
	vars.scrn.height = vars.scrn.height * 8;
	return (vars);
}

int	nbr_rows(char **map)
{
	int	i;

	i = 0;
	while (map[i++]);
	return (i);
}

void	paint_white_img(t_data img)
{
	int	i;
	int	j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
			my_mlx_pixel_put(&img, i, j++, 0x00FFFFFF);
		i++;
	}
}

void	paint_map(t_vars vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars.map[i])
	{
		j = 0;
		while (vars.map[i][j])
		{
			if (vars.map[i][j] == '1')
				mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img_w.img, j * 8, i * 8);
			else if (vars.map[i][j] == '0')
				mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img_b.img, j * 8, i * 8);
			j++;
		}
		i++;
	}
}