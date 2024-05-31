/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 23:32:36 by lagea             #+#    #+#             */
/*   Updated: 2024/05/31 17:20:45 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	render_map(t_data *data)
{
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		exit(EXIT_FAILURE);
	data->mlx.win = mlx_new_window(data->mlx.mlx, (data->map.x) * PIXEL,
			(data->map.y) * PIXEL, "So_long");
	if (!data->mlx.win)
	{
		free(data->mlx.mlx);
		exit(EXIT_FAILURE);
	}
	mlx_do_sync(data->mlx.mlx);
	mlx_hook(data->mlx.win, KEYPRESS, 0, &when_keypress, data);
	mlx_hook(data->mlx.win, DESTROYNOTIFY, 0, &when_destroy, data);
	if (load_xpm(data) == -1)
		when_destroy(data);
	place_map(data);
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
}

void	place_items(t_data *data, int x, int y)
{
	if (data->map.layout && data->map.layout[y][x] == '1')
		render_xpm(data, data->xpm.wall, x * PIXEL, y * PIXEL);
	else if (data->map.layout && data->map.layout[y][x] == '0')
		render_xpm(data, data->xpm.ground, x * PIXEL, y * PIXEL);
	else if (data->map.layout && data->map.layout[y][x] == 'C')
		render_xpm(data, data->xpm.coin, x * PIXEL, y * PIXEL);
	else if (data->map.layout && data->map.layout[y][x] == 'E')
		render_xpm(data, data->xpm.trapdoor, x * PIXEL, y * PIXEL);
	else if (data->map.layout && data->map.layout[y][x] == 'P')
	{
		render_xpm(data, data->xpm.ground, x * PIXEL, y * PIXEL);
		render_xpm(data, data->xpm.player, x * PIXEL, y * PIXEL);
	}
	else
		exit_message(INV_CHAR);
}
