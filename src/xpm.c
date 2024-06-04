/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:12:16 by lagea             #+#    #+#             */
/*   Updated: 2024/06/04 17:24:04 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	load_xpm(t_data *data)
{
	int	x;
	int	y;

	data->xpm.wall = mlx_xpm_file_to_image(data->mlx.mlx,
			"assets/wall.xpm", &x, &y);
	if (!data->xpm.wall)
		return (-1);
	data->xpm.coin = mlx_xpm_file_to_image(data->mlx.mlx,
			"assets/coin.xpm", &x, &y);
	if (!data->xpm.wall)
		return (-1);
	data->xpm.player = mlx_xpm_file_to_image(data->mlx.mlx,
			"assets/player.xpm", &x, &y);
	if (!data->xpm.wall)
		return (-1);
	data->xpm.ennemy = mlx_xpm_file_to_image(data->mlx.mlx,
			"assets/ennemy.xpm", &x, &y);
	if (!data->xpm.wall)
		return (-1);
	if (load_xpm_2(data, x, y) == -1)
		return (-1);
	return (1);
}

int	load_xpm_2(t_data *data, int x, int y)
{
	data->xpm.ground = mlx_xpm_file_to_image(data->mlx.mlx,
			"assets/ground.xpm", &x, &y);
	if (!data->xpm.wall)
		return (-1);
	data->xpm.ladder = mlx_xpm_file_to_image(data->mlx.mlx,
			"assets/ladder.xpm", &x, &y);
	if (!data->xpm.wall)
		return (-1);
	data->xpm.trapdoor = mlx_xpm_file_to_image(data->mlx.mlx,
			"assets/trapdoor.xpm", &x, &y);
	if (!data->xpm.wall)
		return (-1);
	return (1);
}
