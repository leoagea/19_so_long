/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:35:54 by lagea             #+#    #+#             */
/*   Updated: 2024/05/24 19:05:21 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

char **open_map(char *path)
{
	int op;
	char *read;
	char **map;
	
	op = open(path, O_RDONLY);
	if (op == -1)
	{
		ft_printf("Error\n");
		ft_printf("%s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}
}

