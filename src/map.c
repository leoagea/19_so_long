/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:35:54 by lagea             #+#    #+#             */
/*   Updated: 2024/05/29 12:38:30 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void open_map(t_data *data)
{	
	data->map.fd = open(data->map.path, O_RDONLY);
	if (data->map.fd == -1)
	{
		ft_printf("Error\n");
		ft_printf("%s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}
	// read_map(data->map.fd);
	get_malloc_size(data);
	parse_map(data);
	close(data->map.fd);
}

void get_malloc_size(t_data *data)
{
	char *read;
	
	read = get_next_line(data->map.fd);
	if (read == NULL)
		exit_message(EMPTY);
	else if (ft_strlen(read) == 1)
		exit_message(INV);
	// printf("%s",read);
	data->map.x = ft_strlen(read) - 1;
	while(read != NULL)
	{
		data->map.y += 1;
		free(read);
		read = get_next_line(data->map.fd);
		if (read == NULL || read[1] == '\n')
			break ;
		// printf("%s",read);
	}
	free(read);
	close(data->map.fd);
	printf("nbr ligne : %d, long ligne: %d\n",data->map.y, data->map.x);
}
// add funcrtion to check if last line is strlen - 1 de line 

void parse_map(t_data *data)
{
	int i;
	// char *read;
	
	i = 0;
	data->map.layout = (char **) malloc((data->map.y + 1) * sizeof(char *));
	open(data->map.path, O_RDONLY);
	while (i < data->map.y)
	{
		data->map.layout[i] = get_next_line(data->map.fd);
		get_info_map(i, data);
		// printf("%s",data->map.layout[i]);
		i++;
	}
	data->map.layout[i] = NULL;
	printf("Apres parsing : \n");
	i = 0;
	while (data->map.layout[i] != NULL)
	{
		printf("%s",data->map.layout[i]);
		i++;
	}
	printf("\nPlayer, count : %d, x : %d, y : %d\n",data->player.count, data->player.x, data->player.y);
	printf("Exit, count : %d, x : %d, y : %d\n",data->exit.count, data->exit.x, data->exit.y);
	printf("Nbr collec : %d\n",data->collec.count);
	printf("Nbr ennemy : %d\n",data->ennemy.count);
}

void get_info_map(int i, t_data *data)
{
	// if (i != data->map.y)
	// 	if ((int)ft_strlen(data->map.layout[i]) != data->map.x)
	// 		exit_message(NOT_RECT);
	// if (i == data->map.y)
	// 	if ((int)ft_strlen(data->map.layout[i]) != (data->map.x - 1))
	// 		exit_message(NOT_RECT);
	int j;

	j = 0;
	while (data->map.layout[i][j])
	{
		if (data->map.layout[i][j] == 'C')
			data->collec.count++;
		else if (data->map.layout[i][j] == 'P')
		{
			data->player.x = j;
			data->player.y = i;
			data->player.count++;
		}
		else if (data->map.layout[i][j] == 'E')
		{	
			data->exit.x = j;
			data->exit.y = i;
			data->exit.count++;
		}
		else if (data->map.layout[i][j] == 'X')
			data->ennemy.count++;
		j++;
	}	
}
