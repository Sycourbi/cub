/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:46:59 by sycourbi          #+#    #+#             */
/*   Updated: 2023/11/27 15:07:03 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ajout_dir(char **map, t_data *data)
{
	int i;
	int j;

	i = 0;
	data->player.dir = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			while(map[i][j] == ' ' || map[i][j] == '\t')
				j++;
			if (ft_strchr("01NSEW", map[i][j]) == NULL)
				return (msg_err("mauvais caratere dans la map"), FAILED);
			if (ft_strchr("NSEW", map[i][j]) && data->player.dir == 0)
				data->player.dir = map[i][j];
			else if (ft_strchr("NSEW", map[i][j]) && data->player.dir != 0)
				return (msg_err("Erreur direction player"), FAILED);
			j++;
		}
		i++;
	}
	printf("dir est %c\n", data->player.dir);
	return (SUCCESS);
}

void	ajout_pos_player(char **map, t_data *data)
{
	int i;
	int j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (ft_strchr("NSEW", map[i][j]))
			{
				data->player.pos_x = (double)j;
				data->player.pos_y = (double)i;
				map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

int check_pos_player(char **map, t_data *data)
{
	if(ajout_dir(map, data))
		return (FAILED);
	printf("DEBUT POS_PLAYER\n");
	if (data->player.dir == 0)
		return(msg_err("Erreur direction player"), FAILED);
	ajout_pos_player(map, data);
	return (SUCCESS);
}