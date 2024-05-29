/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:04:03 by lagea             #+#    #+#             */
/*   Updated: 2024/05/29 12:38:34 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
// # include <mlx.h>
# include "mlx/mlx.h"

# define EMPTY "Map file is empty"
# define NOT_RECT "Map is not rectangular"
# define NOT_BER "Map file is not a .ber file"
# define INV "Map is invalid"
# define PIXEL 24
# define A 0
# define S 1
# define D 2
# define W 13
# define AR_R 124
# define AR_L 123
# define AR_U 126
# define AR_D 125
# define ESC 53
# define KeyPress 02
# define DestroyNotify 17
# define KeyPressMask (1L << 0)

typedef struct s_player
{
	int			x;
	int			y;
	int			count;
}				t_player;

typedef struct s_exit
{
	int			x;
	int			y;
	int			count;
}				t_exit;

typedef struct s_collec
{
	int			game;
	int			count;
}				t_collec;

typedef struct s_ennemy
{
	int			x;
	int			y;
	int			count;
}				t_ennemy;

typedef struct s_map
{
	int			fd;
	int			x;
	int			y;
	char		*path;
	char		**layout;

}				t_map;

typedef struct s_cpmap
{
	int exit;
	int count;
	char **map;
}				t_cpmap;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;

}				t_mlx;

typedef struct s_xpm
{
	void *coin;
	void *wall;
	void *ennemy;
	void *ground;
	void *ground_2;
	void *ground_3;
	void *player;
	void *ladder;
	void *trapdoor;
	
}				t_xpm;

typedef struct s_data
{
	t_map		map;
	t_mlx		mlx;
	t_xpm		xpm;
	t_exit		exit;
	t_cpmap		cpmap;
	t_player	player;
	t_ennemy	ennemy;
	t_collec	collec;
	int			count;

}				t_data;

/*====================PARSER====================*/
/*---------------------Map----------------------*/

void			open_map(t_data *data);
void			get_malloc_size(t_data *data);
void			parse_map(t_data *data);
void			get_info_map(int i, t_data *data);

/*=====================EXIT=====================*/
/*---------------------exit---------------------*/

void			exit_message(char *str);

/*====================RENDER====================*/
/*--------------------RENDER--------------------*/

void			render_map(t_data *data);
void load_xpm(t_data *data);
void render_xpm(t_data *data, void *xpm, int x, int y);
void place_map(t_data *data);
void place_items(t_data *data, int x, int y);
void place_background_text(t_data *data);

/*====================Events====================*/
/*--------------------Events--------------------*/

int when_destroy(t_data *data);
int when_keypress(int keysym, t_data *data);
int move(t_data *data, int x, int y);

/*=====================Check====================*/
/*---------------------Check--------------------*/

int free_map(t_data *data, int y);
int backtrack_map(t_data *data, int x, int y);
int cpy_map(t_data *data);
int checker_map(t_data *data);

#endif