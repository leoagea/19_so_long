/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:35:54 by lagea             #+#    #+#             */
/*   Updated: 2024/05/24 20:24:42 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void open_map(t_data *data)
{
	char **map;
	
	data->map.fd = open(data->map.path, O_RDONLY);
	if (data->map.fd == -1)
	{
		ft_printf("Error\n");
		ft_printf("%s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}
	// read_map(data->map.fd);
	get_malloc_size(data);
	close(data->map.fd);
	data->map.layout = malloc(sizeof(char *) * (data->map.y + 1));
	open(data->map.path, O_RDONLY);
	parse_map(data);
	close(data->map.fd);
}

void get_malloc_size(t_data *data)
{
	int len;
	char *read;
	
	read = get_next_line(data->map.fd);
	if (read == NULL)
		exit_message(EMPTY);
	data->map.x = ft_strlen(read) - 1;
	while(read != NULL)
	{
		data->map.y += 1;
		free(read);
		read = get_next_line(data->map.fd);
		len = ft_strlen(read) - 1;
		if (read == NULL)
			break ;
		if (data->map.x != len )
		{
			free(read);
			exit_message(NOT_RECT);
		}
	}
	free(read);
	printf("nbr ligne : %d, long ligne: %d\n",data->map.y, data->map.x);
}

void parse_map(t_data *data)
{
	
}
// char **read_map(int fd)
// {
// 	char *read;
// 	char **map;
	
// 	read = get_next_line(fd);
// 	if (read == NULL)
// 		exit(EXIT_FAILURE);
// 	while (read != NULL)
// 	{
// 		printf("%s\n",read);
// 		// map[i] = read;
// 		free(read);
// 		read = get_next_line(fd);
// 	// 	i++;
// 	}
// 	// map[i] = NULL;
// 	// free(read);
// 	return (map);
// }