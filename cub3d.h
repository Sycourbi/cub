/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:46:51 by sycourbi          #+#    #+#             */
/*   Updated: 2023/11/27 13:58:01 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
//# include "minilibx-linux/mlx.h"

# include <stddef.h>
/*fonction write, close, read*/
# include <unistd.h>
/*fonction open*/
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
/*fonction printf, perror*/
# include <stdio.h>
/*fonction malloc, free, exit*/
# include <stdlib.h>
/*fonction strerror*/
# include <string.h>

# define FAILED 1
# define SUCCESS 0

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;

}	t_player;


typedef struct	s_text
{
	char	*text_north;
	char	*text_south;
	char	*text_west;
	char	*text_east;
	int		*color_C;
	int		*color_F;
}	t_text;

typedef struct	s_map
{
	char	**copy_map;
	char	**copy_file;
	int		map_height;
	int		map_width;
	int		fd;
	
}	t_map;

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_height;
	int		win_width;
	char	*name_file;
	t_map	map;
	t_text	texture;
	t_player	player;
	
}	t_data;

/*main.c*/
int		main(int argc, char **argv);
/*check_arg.c*/
int		check_arg(char *av, t_data *data);
/*creat_copy_file.c*/
int		creat_copy_file(char *file, t_data *data);
/*init.c*/
void	init_data(t_data *data);
/*error.c*/
void	msg_err(char *str);
void	ft_delete(t_data *data);
/*utils.c*/
void	free_tab(char **tab);
/*text_infile*/
int		texture_infile(t_data *data, char **map);
/*color_infile*/
int		ajout_color(char *map, int j, t_data *data);
/*creat_map*/
int		creat_map(char **copy_file, int i, int j, t_data *data);
/*verif_map*/
int	 	ft_verif_map(t_data *data, char **map);
/*text_color_check*/
int		verif_texture_color(t_text *text);
/*pos_player.c*/
int 	check_pos_player(char **map, t_data *data);

#endif
