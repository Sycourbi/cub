/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:01:59 by sycourbi          #+#    #+#             */
/*   Updated: 2023/11/27 15:08:46 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	nbr_line_map(char **map, int i, int j)
{
	int	start;

	start = i;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ' || map[i][j] == '\t' || map[i][j] == '\r')
			j++;
		if (map[i][j] != '1')
			return (0);
		i++;
	}
	return (i - start);
}
int		size_big_line(char **file, int i)
{
	int res;
	res = ft_strlen(file[i]);
	while(file[i])
	{
		if (res < (int)ft_strlen(file[i]))
			res = ft_strlen(file[i]);
		i++;
	}
	return (res);
}
int	ajout_map(char **file, int start, t_data *data)
{
	int j;
	int	i; 
	
	i = 0;
	data->map.map_width = size_big_line(file, start);
	while(i < data->map.map_height)
	{
		j = 0;
		data->map.copy_map[i] = malloc(sizeof(char) * data->map.map_width);
		if (!data->map.copy_file[i])
			return (msg_err("probleme malloc"), -3);
		while (file[start][j] && file[start][j] != '\n')
		{
			data->map.copy_map[i][j] = file[start][j];
			j++;
		}
		while (j < data->map.map_width)
		{
			data->map.copy_map[i][j] = '\0';
			j++;
		}
		i++;
		start++;
	}
	data->map.copy_map[i] = NULL;
	return (2);
	
}

int	creat_map(char **copy_file, int i, int j, t_data *data)
{
	data->map.map_height = nbr_line_map(copy_file, i, j);
	if (data->map.map_height == 0)
		return (-1);
	data->map.copy_map = malloc(sizeof(char *) * (data->map.map_height + 1));
	if (!data->map.copy_map)
		return (msg_err("probleme de map"), -3);
	return (ajout_map(copy_file, i, data));
}
