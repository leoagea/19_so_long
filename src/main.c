/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:05:48 by lagea             #+#    #+#             */
/*   Updated: 2024/05/25 17:29:15 by lagea            ###   ########.fr       */
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
	data->collec.count = 0;
	data->ennemy.count = 0;
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	t_data data;
	
	if (ac == 2)
		data.map.path = av[1];
	init_data(&data);
	// data.map.path = "maps/map_test.ber";
	open_map(&data);
	render_map(&data);
	
	// system("leaks so_long");
	return 0;
}