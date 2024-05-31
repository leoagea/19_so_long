/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 23:32:36 by lagea             #+#    #+#             */
/*   Updated: 2024/05/31 17:24:59 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	render_map(t_data *data)
{
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		exit(EXIT_FAILURE);
	data->mlx.win = mlx_new_window(data->mlx.mlx, (data->map.x) * PIXEL,
			(data->map.y + 2) * PIXEL, "So_long");
	if (!data->mlx.win)
	{
		free(data->mlx.mlx);
		exit(EXIT_FAILURE);
	}
	if (load_xpm(data) == -1)
		when_destroy(data);
	place_map(data);
	mlx_loop_hook(data->mlx.mlx, &anim, data);
	mlx_hook(data->mlx.win, KEYPRESS, 0, &when_keypress, data);
	mlx_hook(data->mlx.win, DESTROYNOTIFY, 0, &when_destroy, data);
	mlx_loop(data->mlx.mlx);
}

void	render_xpm(t_data *data, void *xpm, int x, int y)
{
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, xpm, x, y);
}

void	place_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < (data->map.y))
	{
		x = 0;
		while (x < (data->map.x))
		{
			place_items(data, x, y);
			x++;
		}
		y++;
	}
	place_background_text(data);
}

void	place_items(t_data *data, int x, int y)
{
	if (data->map.layout && data->map.layout[y][x] == '1')
		render_xpm(data, data->xpm.wall, x * PIXEL, (y + 2) * PIXEL);
	else if (data->map.layout && data->map.layout[y][x] == '0')
		render_xpm(data, data->xpm.ground, x * PIXEL, (y + 2) * PIXEL);
	else if (data->map.layout && data->map.layout[y][x] == 'C')
		render_xpm(data, data->xpm.coin, x * PIXEL, (y + 2) * PIXEL);
	else if (data->map.layout && data->map.layout[y][x] == 'P')
	{
		render_xpm(data, data->xpm.ground, x * PIXEL, (y + 2) * PIXEL);
		render_xpm(data, data->xpm.player, x * PIXEL, (y + 2) * PIXEL);
	}
	else if (data->map.layout && data->map.layout[y][x] == 'E')
		render_xpm(data, data->xpm.trapdoor, x * PIXEL, (y + 2) * PIXEL);
	else if (data->map.layout && data->map.layout[y][x] == 'X')
	{
		render_xpm(data, data->xpm.ground, x * PIXEL, (y + 2) * PIXEL);
		render_xpm(data, data->xpm.ennemy, x * PIXEL, (y + 2) * PIXEL);
	}
	else
		exit_message(INV_CHAR);
}

void	place_background_text(t_data *data)
{
	int		x;
	int		y;
	char	*count;

	y = 0;
	while (y < 2)
	{
		x = 0;
		while (x < data->map.x)
		{
			render_xpm(data, data->xpm.ground, x * PIXEL, y * PIXEL);
			x++;
		}
		y++;
	}
	count = ft_itoa(data->count);
	mlx_string_put(data->mlx.mlx, data->mlx.win, 0, 0, 12895487, "Moves :");
	mlx_string_put(data->mlx.mlx, data->mlx.win, 80, 0, 12895487, count);
	free(count);
	ft_printf("Moves : %d\n", data->count);
}
