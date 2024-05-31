/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:05:48 by lagea             #+#    #+#             */
/*   Updated: 2024/05/31 15:21:25 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void init_data(t_data *data)
{
	data->map.fd = 0;
	data->map.x = 0;
	data->map.y = 0;
	data->count = 0;
	data->player.x = 0;
	data->player.y = 0;
	data->player.count = 0;
	data->exit.x = 0;
	data->exit.y = 0;
	data->exit.count = 0;
	data->collec.game = 0;
	data->collec.count = 0;
	data->ennemy.count = 0;
	data->cpmap.count = 0;
	data->cpmap.exit = 0;
}

int	main(int ac, char **av)
{
	t_data data;
	
	if (ac == 2)
		data.map.path = av[1];
	else
		exit_message(INV_ARG);
	init_data(&data);
	open_map(&data);
	if (checker_map(&data) == -1)
		exit_message(INV);
	render_map(&data);
	return 0;
}