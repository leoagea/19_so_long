/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:07:03 by lagea             #+#    #+#             */
/*   Updated: 2024/05/29 14:29:23 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

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

void exit_message(char *str)
{
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}