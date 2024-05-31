/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:04:03 by lagea             #+#    #+#             */
/*   Updated: 2024/05/31 20:21:03 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "../mlx/mlx.h"

# define EMPTY "Map file is empty"
# define NOT_RECT "Map is not rectangular"
# define NOT_BER "Map file is not a .ber file"
# define INV "Map is invalid"
# define BORD "Border are invalid"
# define INV_SIZE "Map is too big"
# define INV_CHAR "Char in map not valid"
# define INV_ARG "Number of arguments is not valid"
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
# define KEYPRESS 02
# define DESTROYNOTIFY 17

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
	int			anim;
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
	int			exit;
	int			count;
	char		**map;
}				t_cpmap;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;

}				t_mlx;

typedef struct s_xpm
{
	void		*coin;
	void		*wall;
	void		*ennemy;
	void		*ground;
	void		*ground_2;
	void		*ground_3;
	void		*player;
	void		*ladder;
	void		*trapdoor;
	void		*coin_2;
	void		*coin_3;
	void		*coin_4;

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

/*======================SRC=====================*/
/*----------------------Map---------------------*/

void			open_map(t_data *data);
void			get_malloc_size(t_data *data);
void			parse_map(t_data *data);
void			get_info_map(int i, t_data *data);

/*---------------------exit---------------------*/

int				free_map(t_data *data, int y);
void			exit_message(char *str);
void			destroy_image(t_data *data);

/*--------------------RENDER--------------------*/

void			render_map(t_data *data);
void			render_xpm(t_data *data, void *xpm, int x, int y);
void			place_map(t_data *data);
void			place_items(t_data *data, int x, int y);
void			place_background_text(t_data *data);

/*--------------------Events--------------------*/

int				when_destroy(t_data *data);
int				when_keypress(int keysym, t_data *data);
int				move(t_data *data, int x, int y);

/*---------------------Check--------------------*/

int				backtrack_map(t_data *data, int x, int y);
int				cpy_map(t_data *data);
int				check_border(t_data *data);
int				checker_map(t_data *data);
void			checker_size(t_data *data);

/*----------------------XPM---------------------*/

int				load_xpm(t_data *data);
int				load_xpm_2(t_data *data, int x, int y);

/*=====================BONUS====================*/
/*---------------------Anim---------------------*/

void			anim_coin(t_data *data, int x, int y);
void			anim_loop(t_data *data);
int				anim(t_data *data);

#endif