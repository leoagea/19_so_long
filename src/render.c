/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 23:32:36 by lagea             #+#    #+#             */
/*   Updated: 2024/05/25 00:07:50 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

static int	key_hook(int keycode, t_data *vars)
{
	if (keycode)
		printf("Hello from key_hook!\n");
	vars->count++;
	return (0);
}

void render_map(t_data *data)
{
	
    data->mlx.mlx = mlx_init();
	data->mlx.win = mlx_new_window(data->mlx.mlx, 1280, 720, "So_long");

	mlx_key_hook(data->mlx.win,key_hook, data);
	
	mlx_loop(data->mlx.mlx);
}