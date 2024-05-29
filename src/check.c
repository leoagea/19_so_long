/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 22:50:54 by lagea             #+#    #+#             */
/*   Updated: 2024/05/29 14:37:47 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int backtrack_map(t_data *data, int x, int y)
{
    // printf("x : %d, data.map.x : %d\n",x, data->map.x);
    // printf("y : %d, data.map.y : %d\n",y, data->map.y);
    if (x > 0 && x < data->map.x && y < data->map.y && y > 0)
    {
        // printf("test\n"); 
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

int check_border(t_data *data)
{
    int i;

    i = -1;
    while (++i < data->map.x)
        if (data->cpmap.map[0][i] != '1' && data->cpmap.map[0])
            return -1;
    i = -1;
    while (++i < data->map.x)
        if (data->cpmap.map[data->map.y - 1][i] != '1' && data->cpmap.map[data->map.y - 1])
            return -1;
    i = -1;
    while (++i < data->map.y)
        if (data->cpmap.map[i][0] != '1' && data->cpmap.map[i])
            return -1;
    i = -1;
    while (++i < data->map.y)
        if (data->cpmap.map[i][data->map.x - 1] != '1' && data->cpmap.map[i])
            return -1;
    return 1;
}

int checker_map(t_data *data)
{
    if (cpy_map(data) == -1)
        return -1;
    // checker_size(data);
    if (check_border(data) == -1)
    {
        free_map(data,data->map.y);
        exit_message(BORD);
    }
    // printf("Check border : %d\n",check_border(data));
    // printf("collec : %d, exit : %d\n",data->cpmap.count, data->cpmap.exit);
    backtrack_map(data, data->player.x, data->player.y);
    // printf("collec : %d, exit : %d\n",data->cpmap.count, data->cpmap.exit);
    free_map(data, data->map.y);
    if (data->cpmap.count != data->collec.count || data->cpmap.exit != 1)
        return -1;
    return 1;
}

void checker_size(t_data *data)
{
    int i;
    int len;

    i = 0;
    while (i < data->map.y - 1)
    {
        len = ft_strlen(data->map.layout[i]) - 1;
        printf("len from strlen : %d, map.x : %d\n",len , data->map.x);
        if (len != data->map.x)
            exit_message(NOT_RECT);
        i++;
    }
}