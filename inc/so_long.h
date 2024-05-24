/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:04:03 by lagea             #+#    #+#             */
/*   Updated: 2024/05/25 00:07:33 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
// # include <mlx.h>
#include "mlx/mlx.h"

#define EMPTY "Map file is empty"
#define NOT_RECT "Map is not rectangular"
#define PIXEL 128
# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53
typedef struct s_map
{
	int		fd;
	int		x;
	int		y;
	char	*path;
	char	**layout;

}			t_map;

typedef struct s_mlx
{
	void *mlx;
	void *win;
	
}			t_mlx;

typedef struct s_data
{
	t_map	map;
	t_mlx	mlx;
	int count;
	
}			t_data;


/*====================PARSER====================*/
/*---------------------Map----------------------*/

void open_map(t_data *data);
void get_malloc_size(t_data *data);
void parse_map(t_data *data);
// char		**read_map(int fd);

/*=====================EXIT=====================*/
/*---------------------exit---------------------*/

void exit_message(char *str);

/*====================RENDER====================*/
/*--------------------RENDER--------------------*/

void render_map(t_data *data);

#endif