/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:07:03 by lagea             #+#    #+#             */
/*   Updated: 2024/05/31 12:34:20 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int free_map(t_data *data, int y)
{
    int i;

    i = 0;
    while (i < y)
    {
        free(data->cpmap.map[i]);
        i++;
    }
    free(data->cpmap.map);
    return -1;
}

void destroy_image(t_data *data)
{
    if (data->xpm.coin)
        mlx_destroy_image(data->mlx.mlx, data->xpm.coin);
    if (data->xpm.ennemy)
        mlx_destroy_image(data->mlx.mlx, data->xpm.ennemy);
    if (data->xpm.ground)
        mlx_destroy_image(data->mlx.mlx, data->xpm.ground);
    if (data->xpm.ladder)
        mlx_destroy_image(data->mlx.mlx, data->xpm.ladder);
    if (data->xpm.player)
        mlx_destroy_image(data->mlx.mlx, data->xpm.player);
    if (data->xpm.trapdoor)
        mlx_destroy_image(data->mlx.mlx, data->xpm.trapdoor);
    if (data->xpm.wall)
        mlx_destroy_image(data->mlx.mlx, data->xpm.wall);    
}

void exit_message(char *str)
{
    system("leaks so_long");
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}