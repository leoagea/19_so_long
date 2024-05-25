/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:46:38 by lagea             #+#    #+#             */
/*   Updated: 2024/05/25 17:47:13 by lagea            ###   ########.fr       */
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
	if (keysym == ESC)
		when_destroy(data);
	printf("Moves : %d\n", data->count);
	return (1);
}

