/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 22:50:54 by lagea             #+#    #+#             */
/*   Updated: 2024/05/29 00:09:34 by lagea            ###   ########.fr       */
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
    return 1;
}

int backtrack_map(t_data *data, int x, int y)
{
    if (x > 0 && x < data->map.x && y > data->map.y)
    {
        if (data->cpmap.map[y][x] == '1' || data->cpmap.map[y][x] == 'X' || data->cpmap.map[y][x] == 'V')
            return 1;
        if (data->cpmap.map[y][x] == '0' || data->cpmap.map[y][x] == 'P')
            data->cpmap.map[y][x] = 'V';
        if (data->cpmap.map[y][x] == 'C')
        {
            data->cpmap.map[y][x] = 'V';
            data->cpmap.count++;
        }
        if (data->cpmap.map[y][x] == 'E')
        {
            data->cpmap.map[y][x] = 'V';
            data->cpmap.exit++;
        }
        backtrack_map(data, x + 1, y);
        backtrack_map(data, x - 1, y);
        backtrack_map(data, x, y + 1);
        backtrack_map(data, x, y - 1);
    }
    return 1;
}

int cpy_map(t_data *data)
{
    int i;
    int j;

    i = 0;
    data->cpmap.map = (char **)malloc((data->map.y + 1) * sizeof(char *));
    if (!data->cpmap.map)
        return -1;
    while (i < data->map.y && data->map.layout[i])
    {
        j = 0;
        data->cpmap.map[i] = malloc((data->map.x + 1) * sizeof(char));
        if (!data->cpmap.map[i])
            return (free_map(data, i));
        while (j < data->map.x && data->map.layout[i][j])
        {
            data->cpmap.map [i][j] = data->map.layout[i][j];
            j++;
        }
        i++;
    }
    return 1;
}

int checker_map(t_data *data)
{
    if (cpy_map(data) == 0)
        return -1;
    backtrack_map(data, data->player.x, data->player.y);
    free_map(data, data->map.y);
    if (data->cpmap.count != data->collec.count || data->cpmap.exit != 1)
        return -1;
    return 1;
}
