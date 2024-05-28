/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:46:38 by lagea             #+#    #+#             */
/*   Updated: 2024/05/28 14:31:28 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int when_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx.mlx, data->mlx.win);
	free(data->mlx.mlx);
	exit(0);
	return (0);
}

int when_keypress(int keysym, t_data *data)
{
	data->count++;
	render_xpm(data, data->xpm.ground, data->player.x * PIXEL, data->player.y * PIXEL);
	if (keysym == ESC)
		when_destroy(data);
	else if (keysym == W || keysym == AR_U)
	{
		if (move(data, (data->player.x), (data->player.y - 1)) == 0)
			render_xpm(data, data->xpm.player, (data->player.x) * PIXEL, data->player.y * PIXEL);
	}
	else if (keysym == D || keysym == AR_R)
	{
		if (move(data, (data->player.x + 1), (data->player.y)) == 0)
			render_xpm(data, data->xpm.player, (data->player.x) * PIXEL, data->player.y * PIXEL);
	}
	else if (keysym == A || keysym == AR_L)
	{
		if (move(data, (data->player.x - 1), (data->player.y)) == 0)
			render_xpm(data, data->xpm.player, (data->player.x) * PIXEL, data->player.y * PIXEL);
	}
	else if (keysym == S || keysym == AR_D)
	{
		if (move(data, (data->player.x), (data->player.y + 1)) == 0)
			render_xpm(data, data->xpm.player, (data->player.x) * PIXEL, data->player.y * PIXEL);
	}
	printf("Moves : %d	Key pressed : %d\n", data->count, keysym);
	return (1);
}

int move(t_data *data, int x, int y)
{
	if (data->map.layout[y][x] == '1')
		return 0;
	if (data->map.layout[y][x] == 'E')
		when_destroy(data);
	if (data->map.layout[y][x] == 'X')
		when_destroy(data);
	if (data->map.layout[y][x] == 'C')
	{
		data->collec.game++;
		data->map.layout[y][x] = '0';
	}
	render_xpm(data, data->xpm.ground, x * PIXEL, y * PIXEL);
	render_xpm(data, data->xpm.player, x * PIXEL, y * PIXEL);
	if (data->collec.game == data->collec.count)
	{
		render_xpm(data, data->xpm.ground, data->exit.x * PIXEL, data->exit.y * PIXEL);
		render_xpm(data, data->xpm.ladder, data->exit.x * PIXEL, data->exit.y * PIXEL);
	}
	data->player.x = x;
	data->player.y = y;
	if (data->collec.game == data->collec.count && data->player.x == data->exit.x && data->player.y == data->exit.y)
		when_destroy(data);
	return 1;
}
