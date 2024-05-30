/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 23:32:36 by lagea             #+#    #+#             */
/*   Updated: 2024/05/30 18:28:15 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void render_map(t_data *data)
{
	
    data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		exit(EXIT_FAILURE);
	data->mlx.win = mlx_new_window(data->mlx.mlx, (data->map.x) * PIXEL, (data->map.y + 2) * PIXEL, "So_long");
	if (!data->mlx.win)
	{
		free(data->mlx.mlx);
		exit(EXIT_FAILURE);
	}
	mlx_do_sync(data->mlx.mlx);
	mlx_hook(data->mlx.win,KeyPress,KeyPressMask,&when_keypress,data);
	mlx_hook(data->mlx.win, DestroyNotify, 0, &when_destroy, data);
	// if (load_xpm(data) == NULL)
	// 	when_destroy(data);
	load_xpm(data);
	place_map(data);
	mlx_loop(data->mlx.mlx);
}

void load_xpm(t_data *data)
{
	int x;
	int y;
	data->xpm.wall = mlx_xpm_file_to_image(data->mlx.mlx, "assets_24x24/wall.xpm", &x, &y);
	// if (!data->xpm.wall)
	// 	return data->xpm.wall = NULL;
	data->xpm.coin = mlx_xpm_file_to_image(data->mlx.mlx, "assets_24x24/coin.xpm", &x, &y);
	// if (!data->xpm.wall)
	// 	return data->xpm.wall = NULL;
	data->xpm.player = mlx_xpm_file_to_image(data->mlx.mlx, "assets_24x24/player.xpm", &x, &y);
	// if (!data->xpm.wall)
	// 	return data->xpm.wall = NULL;
	data->xpm.ennemy = mlx_xpm_file_to_image(data->mlx.mlx, "assets_24x24/ennemy.xpm", &x, &y);
	// if (!data->xpm.wall)
	// 	return data->xpm.wall = NULL;
	data->xpm.ground = mlx_xpm_file_to_image(data->mlx.mlx, "assets_24x24/ground.xpm", &x, &y);
	// if (!data->xpm.wall)
	// 	return data->xpm.wall = NULL;
	data->xpm.ladder = mlx_xpm_file_to_image(data->mlx.mlx, "assets_24x24/ladder.xpm", &x, &y);
	// if (!data->xpm.wall)
	// 	return data->xpm.wall = NULL;
	data->xpm.trapdoor = mlx_xpm_file_to_image(data->mlx.mlx, "assets_24x24/trapdoor.xpm", &x, &y);
	// if (!data->xpm.wall)
	// 	return data->xpm.wall = NULL;
	// return (void *)x;
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
	// place_background_text(data);
	printf("\nplayer x : %d, y : %d\n", data->player.x, data->player.y);
	printf("collectable : %d , exit : %d , player : %d\n", data->collec.count, data->exit.count, data->player.count);
}

void place_items(t_data *data, int x, int y)
{
	if (data->map.layout && data->map.layout[y ][x ] == '1')
		render_xpm(data, data->xpm.wall, x * PIXEL, (y + 2) * PIXEL);
	else if (data->map.layout && data->map.layout[y ][x ] == '0')
		render_xpm(data, data->xpm.ground, x * PIXEL, (y + 2) * PIXEL);
	else if (data->map.layout && data->map.layout[y ][x ] == 'C')
		render_xpm(data, data->xpm.coin, x* PIXEL, (y + 2) * PIXEL);
	else if (data->map.layout && data->map.layout[y ][x ] == 'E')
		render_xpm(data, data->xpm.trapdoor, x* PIXEL, (y + 2) * PIXEL);
	else if (data->map.layout && data->map.layout[y ][x ] == 'P')
	{
		render_xpm(data, data->xpm.ground, x* PIXEL, (y + 2) * PIXEL);
		render_xpm(data, data->xpm.player, x* PIXEL, (y + 2) * PIXEL);
	}
	else
		exit_message(INV_CHAR);
}
