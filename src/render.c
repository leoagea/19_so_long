/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 23:32:36 by lagea             #+#    #+#             */
/*   Updated: 2024/05/28 14:24:59 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

	mlx_hook(data->mlx.win,KeyPress,KeyPressMask,&when_keypress,data);
	mlx_hook(data->mlx.win, DestroyNotify, 0, &when_destroy, data);
	load_xpm(data);
	place_map(data);
	mlx_loop(data->mlx.mlx);
}

void load_xpm(t_data *data)
{
	int x;
	int y;
	data->xpm.wall = mlx_xpm_file_to_image(data->mlx.mlx, "assets_24x24/wall.xpm", &x, &y);
	data->xpm.coin = mlx_xpm_file_to_image(data->mlx.mlx, "assets_24x24/coin.xpm", &x, &y);
	data->xpm.player = mlx_xpm_file_to_image(data->mlx.mlx, "assets_24x24/player.xpm", &x, &y);
	data->xpm.ennemy = mlx_xpm_file_to_image(data->mlx.mlx, "assets_24x24/ennemy.xpm", &x, &y);
	data->xpm.ground = mlx_xpm_file_to_image(data->mlx.mlx, "assets_24x24/ground.xpm", &x, &y);
	data->xpm.ladder = mlx_xpm_file_to_image(data->mlx.mlx, "assets_24x24/ladder.xpm", &x, &y);
	data->xpm.trapdoor = mlx_xpm_file_to_image(data->mlx.mlx, "assets_24x24/trapdoor.xpm", &x, &y);
	// data->xpm.ground_2 = mlx_xpm_file_to_image(data->mlx.mlx, "assets_32_32/wall.xpm", &x, &y);
	// data->xpm.ground_3 = mlx_xpm_file_to_image(data->mlx.mlx, "assets/ground.xpm", &x, &y);
	// render_xpm(data, data->xpm.player, 0, 0);
	// render_xpm(data, data->xpm.ground_2, 0, 32); 
	// render_xpm(data, data->xpm.ground_3, 0, 64);
	// render_xpm(data, data->xpm.ladder, 64, 0);
	// render_xpm(data, data->xpm.ground, 64, 64);
	// // render_xpm(data, data->xpm.ground_2, 96, 64);
	// render_xpm(data, data->xpm.ground_3, 100, 64);
	// render_xpm(data, data->xpm.wall, 130, 64);
}

void render_xpm(t_data *data, void *xpm, int x, int y)
{
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, xpm, x, y);
}

void place_map(t_data *data)
{
	int x;
	int y;
	// int count;

	// count = 0;
	y = 0;
	printf("\nx : %d, y : %d",data->map.x, data->map.y);
	while (y < (data->map.y ))
	{
		// printf("test\n");
		x = 0;
		while (x < (data->map.x ))
		{
			// printf("test 0, %d\n",count++);
			// printf("x : %d, y : %d, char : %c\n", x, y,data->map.layout[y][x]);
			place_items(data, x, y);
		x++;
		}
		y++;
	}
	printf("\nplayer x : %d, y : %d\n", data->player.x, data->player.y);
	printf("collectable : %d , exit : %d , player : %d\n", data->collec.count, data->exit.count, data->player.count);
}

void place_items(t_data *data, int x, int y)
{
	if (data->map.layout && data->map.layout[y ][x ] == '1')
	{
		render_xpm(data, data->xpm.wall, x * PIXEL, y * PIXEL);
	}
	else if (data->map.layout && data->map.layout[y ][x ] == '0')
	{
		render_xpm(data, data->xpm.ground, x* PIXEL, y* PIXEL);
	}
	else if (data->map.layout && data->map.layout[y ][x ] == 'C')
	{
		// render_xpm(data, data->xpm.ground, x* PIXEL, y* PIXEL);
		render_xpm(data, data->xpm.coin, x* PIXEL, y* PIXEL);
	}
	else if (data->map.layout && data->map.layout[y ][x ] == 'P')
	{
		render_xpm(data, data->xpm.ground, x* PIXEL, y* PIXEL);
		render_xpm(data, data->xpm.player, x* PIXEL, y* PIXEL);
	}
	else if (data->map.layout && data->map.layout[y ][x ] == 'E')
	{
		render_xpm(data, data->xpm.trapdoor, x* PIXEL, y* PIXEL);
	}
	else if (data->map.layout && data->map.layout[y ][x ] == 'X')
	{
		render_xpm(data, data->xpm.ground, x* PIXEL, y* PIXEL);
		render_xpm(data, data->xpm.ennemy, x* PIXEL, y* PIXEL);
	}
	else
		return ;
}
