/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_infile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:46:47 by sycourbi          #+#    #+#             */
/*   Updated: 2023/11/27 15:04:33 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

char	*ajout_new_texture(char *map, int j)
{
	int		start;
	char	*line;
	
	while(map[j] == ' ' || map[j] == '\t' || map[j] == '\r')
		j++;
	start = j;
	while (map[j] && (map[j] == ' ' || map[j] == '\t' || map[j] == '\r'))
		j++;
	line = malloc(sizeof(char) * (j - start) + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (map[start] && (map[start] == ' ' || map[start] == '\t' || map[start] == '\r'))
	{
		line[j] = map[start + j];
		j++;
	}
	line[j] = '\0';
	if (map[j] && map[j] != '\n')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

int	ajout_texture(char *map, int j, t_data *data)
{
	if (map[j] == 'N' && map[j + 1] == 'O' && !data->texture.text_north)
		data->texture.text_north = ajout_new_texture(map, j + 2);
	else if (map[j] == 'S' && map[j + 1] == 'O' && !data->texture.text_south)
		data->texture.text_south = ajout_new_texture(map, j + 2);
	else if (map[j] == 'W' && map[j + 1] == 'E' && !data->texture.text_west)
		data->texture.text_west = ajout_new_texture(map, j + 2);
	else if (map[j] == 'E' && map[j + 1] == 'A' && !data->texture.text_east)
		data->texture.text_east = ajout_new_texture(map, j + 2);
	else
		return (-1);
	return (0);
}

int	check_whitespace(char **file, int i, int j, t_data *data)
{
	while (file[i][j] == ' ' || file[i][j] == '\t' || file[i][j] == '\r')
		j++;
	if (file[i][j] && (file[i][j] >= 'A' && file[i][j] <= 'Z'))
	{
		if (file[i][j + 1] && (file[i][j + 1] >= 'A' && file[i][j + 1] <= 'Z'))
			return (ajout_texture(file[i], j, data));
		else if (file[i][j + 1])
			return (ajout_color(file[i], j, data));
	}
	
	if (file[i][j] == '\0' || file[i][j] == '\n')
		return (1);
	else if (file[i][j] != '\0' && (file[i][j] == '0' || file[i][j] == '1'))
	 	return (creat_map(file, i, j, data));
	return (-1);
	
}

int	texture_infile(t_data *data, char **copy_file)
{
	int	i;
	//int	j;
	int	res;
	
	i = 0;
	while (copy_file[i])
	{
		res = check_whitespace(copy_file, i, 0, data);
		if (res == -1)
			return(msg_err("erreur trouver dans le fichier"), FAILED);
		if (res == 2)
			return (SUCCESS);
		if (res == -3)
			return (FAILED);
		i++;
	}
	return (FAILED);
}