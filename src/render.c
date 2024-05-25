/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 23:32:36 by lagea             #+#    #+#             */
/*   Updated: 2024/05/26 00:26:31 by lagea            ###   ########.fr       */
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
	data->xpm.player = mlx_xpm_file_to_image(data->mlx.mlx, "assets/character.xpm", &x, &y);
	data->xpm.coin = mlx_xpm_file_to_image(data->mlx.mlx, "assets/coin.xpm", &x, &y);
	data->xpm.ennemy = mlx_xpm_file_to_image(data->mlx.mlx, "assets/ennemy.xpm", &x, &y);
	data->xpm.ground = mlx_xpm_file_to_image(data->mlx.mlx, "assets/ground.xpm", &x, &y);
	data->xpm.ladder = mlx_xpm_file_to_image(data->mlx.mlx, "assets/ladder.xpm", &x, &y);
	data->xpm.wall = mlx_xpm_file_to_image(data->mlx.mlx, "assets/wall_down_1.xpm", &x, &y);
	// render_xpm(data, data->xpm.player, 0, 0);
	// render_xpm(data, data->xpm.coin, 16, 16);
	// render_xpm(data, data->xpm.ennemy, 32, 32);
	// render_xpm(data, data->xpm.ground, 48, 48);
	// render_xpm(data, data->xpm.ladder, 64, 64);
	// render_xpm(data, data->xpm.wall, 32, 0);	
}

void render_xpm(t_data *data, void *xpm, int x, int y)
{
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, xpm, x, y);
}

void place_map(t_data *data)
{
	int x;
	int y;
	int count;

	count = 0;
	y = 0;
	printf("x : %d, y : %d",data->map.x, data->map.y);
	while (y < (data->map.y * PIXEL))
	{
		printf("test\n");
		x = 0;
		while (x < (data->map.x * PIXEL))
		{
			printf("test 0, %d\n",count++);
			place_items(data, x, y);
			x+=PIXEL;
		}
		y+= PIXEL;
	}
}

void place_items(t_data *data, int x, int y)
{
	if (data->map.layout && data->map.layout[x / PIXEL][y / PIXEL] == '1')
	{
		printf("test 1\n");
		render_xpm(data, data->xpm.wall, x, y);
	}
	else if (data->map.layout && data->map.layout[x / PIXEL][y / PIXEL] == '0')
	{
		printf("test 2\n");
		render_xpm(data, data->xpm.ground, x, y);
	}
	else if (data->map.layout && data->map.layout[x / PIXEL][y / PIXEL] == 'C')
		render_xpm(data, data->xpm.coin, x, y);
	else if (data->map.layout && data->map.layout[x / PIXEL][y / PIXEL] == 'P')
		render_xpm(data, data->xpm.player, x, y);
	else if (data->map.layout && data->map.layout[x / PIXEL][y / PIXEL] == 'E')
		render_xpm(data, data->xpm.ladder, x, y);
	else if (data->map.layout && data->map.layout[x / PIXEL][y / PIXEL] == 'X')
		render_xpm(data, data->xpm.ennemy, x, y);
}
