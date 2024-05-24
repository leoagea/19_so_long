/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:04:03 by lagea             #+#    #+#             */
/*   Updated: 2024/05/24 20:13:19 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <mlx.h>

#define EMPTY "Map file is empty"
#define NOT_RECT "Map is not rectangular"

typedef struct s_map
{
	int		fd;
	int		x;
	int		y;
	char	*path;
	char	**layout;

}			t_map;

typedef struct s_data
{
	t_map	map;

}			t_data;

/*====================PARSER====================*/
/*---------------------Map----------------------*/

void open_map(t_data *data);
void get_malloc_size(t_data *data);
// char		**read_map(int fd);

/*=====================EXIT=====================*/
/*---------------------exit---------------------*/

void exit_message(char *str);

#endif