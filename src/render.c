/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 23:32:36 by lagea             #+#    #+#             */
/*   Updated: 2024/05/25 18:03:13 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void render_map(t_data *data)
{
	
    data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		exit(EXIT_FAILURE);
	data->mlx.win = mlx_new_window(data->mlx.mlx, 1280, 720, "So_long");
	if (!data->mlx.win)
	{
		free(data->mlx.mlx);
		exit(EXIT_FAILURE);
	}

	mlx_hook(data->mlx.win,KeyPress,KeyPressMask,&when_keypress,data);
	mlx_hook(data->mlx.win, DestroyNotify, 0, &when_destroy, data);
	load_xpm(data);
	render_xpm(data);
	mlx_loop(data->mlx.mlx);
}

void load_xpm(t_data *data)
{
	int x = 64;
	int y = 64;
	data->xpm.test = mlx_xpm_file_to_image(data->mlx.mlx, "assets/Dungeon_Tileset.xpm", &x, &y);
}

void render_xpm(t_data *data)
{
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->xpm.test, 0, 0);	
}

