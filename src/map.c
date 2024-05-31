/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:35:54 by lagea             #+#    #+#             */
/*   Updated: 2024/05/31 18:25:26 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	open_map(t_data *data)
{
	data->map.fd = open(data->map.path, O_RDONLY);
	if (data->map.fd == -1)
	{
		system("leaks so_long");
		ft_printf("Error\n");
		ft_printf("%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	get_malloc_size(data);
	parse_map(data);
	close(data->map.fd);
}

void	get_malloc_size(t_data *data)
{
	char	*read;

	read = get_next_line(data->map.fd);
	if (read == NULL)
		exit_message(EMPTY);
	else if (ft_strlen(read) == 1)
		exit_message(INV);
	data->map.x = ft_strlen(read) - 1;
	while (read != NULL)
	{
		data->map.y += 1;
		free(read);
		read = get_next_line(data->map.fd);
		if (read == NULL || read[1] == '\n')
			break ;
	}
	free(read);
	close(data->map.fd);
}

void	parse_map(t_data *data)
{
	int	i;

	i = 0;
	data->map.layout = (char **)malloc((data->map.y + 1) * sizeof(char *));
	open(data->map.path, O_RDONLY);
	while (i < data->map.y)
	{
		data->map.layout[i] = get_next_line(data->map.fd);
		get_info_map(i, data);
		i++;
	}
	data->map.layout[i] = NULL;
}

void	get_info_map(int i, t_data *data)
{
	int	j;

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
		else if (data->map.layout[i][j] != '0' && data->map.layout[i][j] != '1'
			&& data->map.layout[i][j] != '\n')
			exit_message(INV_CHAR);
		j++;
	}
}
