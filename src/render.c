/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 23:32:36 by lagea             #+#    #+#             */
/*   Updated: 2024/05/31 15:17:37 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void render_map(t_data *data)
{
	
    data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		exit(EXIT_FAILURE);
	data->mlx.win = mlx_new_window(data->mlx.mlx, (data->map.x) * PIXEL, (data->map.y) * PIXEL, "So_long");
	if (!data->mlx.win)
	{
		free(data->mlx.mlx);
		exit(EXIT_FAILURE);
	}
	mlx_do_sync(data->mlx.mlx);
	mlx_hook(data->mlx.win,KeyPress,KeyPressMask,&when_keypress,data);
	mlx_hook(data->mlx.win, DestroyNotify, 0, &when_destroy, data);
	if (load_xpm(data) == -1)
		when_destroy(data);
	place_map(data);
	mlx_loop(data->mlx.mlx);
}

int load_xpm(t_data *data)
{
	int x;
	int y;
	data->xpm.wall = mlx_xpm_file_to_image(data->mlx.mlx, "assets_24x24/wall.xpm", &x, &y);
	if (!data->xpm.wall)
		return -1;
	data->xpm.coin = mlx_xpm_file_to_image(data->mlx.mlx, "assets_24x24/coin.xpm", &x, &y);
	if (!data->xpm.wall)
		return -1;
	data->xpm.player = mlx_xpm_file_to_image(data->mlx.mlx, "assets_24x24/player.xpm", &x, &y);
	if (!data->xpm.wall)
		return -1;
	data->xpm.ennemy = mlx_xpm_file_to_image(data->mlx.mlx, "assets_24x24/ennemy.xpm", &x, &y);
	if (!data->xpm.wall)
		return -1;
	data->xpm.ground = mlx_xpm_file_to_image(data->mlx.mlx, "assets_24x24/ground.xpm", &x, &y);
	if (!data->xpm.wall)
		return -1;
	data->xpm.ladder = mlx_xpm_file_to_image(data->mlx.mlx, "assets_24x24/ladder.xpm", &x, &y);
	if (!data->xpm.wall)
		return -1;
	data->xpm.trapdoor = mlx_xpm_file_to_image(data->mlx.mlx, "assets_24x24/trapdoor.xpm", &x, &y);
	if (!data->xpm.wall)
		return -1;
	return 1;
}

void render_xpm(t_data *data, void *xpm, int x, int y)
{
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, xpm, x, y);
}

void place_map(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (y < (data->map.y ))
	{
		x = 0;
		while (x < (data->map.x ))
		{
			place_items(data, x, y);
		x++;
		}
		y++;
	}
}

void place_items(t_data *data, int x, int y)
{
	if (data->map.layout && data->map.layout[y ][x ] == '1')
		render_xpm(data, data->xpm.wall, x * PIXEL, y * PIXEL);
	else if (data->map.layout && data->map.layout[y ][x ] == '0')
		render_xpm(data, data->xpm.ground, x * PIXEL, y * PIXEL);
	else if (data->map.layout && data->map.layout[y ][x ] == 'C')
		render_xpm(data, data->xpm.coin, x* PIXEL, y * PIXEL);
	else if (data->map.layout && data->map.layout[y ][x ] == 'E')
		render_xpm(data, data->xpm.trapdoor, x* PIXEL, y * PIXEL);
	else if (data->map.layout && data->map.layout[y ][x ] == 'P')
	{
		render_xpm(data, data->xpm.ground, x* PIXEL, y * PIXEL);
		render_xpm(data, data->xpm.player, x* PIXEL, y * PIXEL);
	}
	else
		exit_message(INV_CHAR);
}
