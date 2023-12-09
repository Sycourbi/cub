/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:49:44 by sycourbi          #+#    #+#             */
/*   Updated: 2023/11/27 15:47:47 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_extension(char *str)
{
	int	i;
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (msg_err("error open fd"), FAILED);
	close (fd);
	i = 0;
	while(str[i])
		i++;
	if (str[i - 1] != 'b' || str[i - 2] != 'u' ||
		str[i - 3] != 'c' || str[i - 4] != '.')
		return (msg_err("extension .cub demande"), FAILED);
	return (SUCCESS);
}

int	check_arg(char *av, t_data *data)
{
	if (check_extension(av))
		return (ft_delete(data), FAILED);
	if (creat_copy_file(av, data))
		return (ft_delete(data), FAILED);
	if (texture_infile(data, data->map.copy_file))
		return (ft_delete(data), FAILED);
	//if (verif_texture_color(&data->text))
	//	return (FAILED);
	if (ft_verif_map(data, data->map.copy_map))
		return (ft_delete(data), FAILED);
	ft_delete(data);
	// 	return (1);
	//verifie color
	return (0);
}