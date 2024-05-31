/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:02:30 by lagea             #+#    #+#             */
/*   Updated: 2024/05/31 19:58:17 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	anim_coin(t_data *data, int x, int y)
{
	if (data->collec.anim < 12)
		render_xpm(data, data->xpm.coin, x * PIXEL, (y + 2) * PIXEL);
	else if (data->collec.anim > 12 && data->collec.anim < 25)
		render_xpm(data, data->xpm.coin_2, x * PIXEL, (y + 2) * PIXEL);
	else if (data->collec.anim > 25 && data->collec.anim < 37)
		render_xpm(data, data->xpm.coin_3, x * PIXEL, (y + 2) * PIXEL);
	else if (data->collec.anim > 37)
		render_xpm(data, data->xpm.coin_4, x * PIXEL, (y + 2) * PIXEL);
}

void	anim_loop(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.y - 1)
	{
		j = 0;
		while (j < data->map.x - 1 && data->map.layout[i][j])
		{
			if (data->map.layout[i][j] == 'C')
				anim_coin(data, j, i);
			j++;
		}
		i++;
	}
}

int	anim(t_data *data)
{
	anim_loop(data);
	if (data->collec.anim == 50)
		data->collec.anim = 0;
	data->collec.anim++;
	return (1);
}
