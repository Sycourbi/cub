/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:32:54 by sycourbi          #+#    #+#             */
/*   Updated: 2023/11/27 15:05:56 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	msg_err(char *str)
{
	write(2, "cub3d error: ", 13);
	if (str)
		write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}
void	free_texture(t_text *texture)
{
	if (texture->text_north)
		free(texture->text_north);
	if (texture->text_east)
		free(texture->text_east);
	if (texture->text_south)
		free(texture->text_south);
	if (texture->text_west)
		free(texture->text_west);
	if (texture->color_C)
		free(texture->color_C);
	if (texture->color_F)
		free(texture->color_F);		
}
void	free_map(t_map	*map)
{
	if (map->fd)
		close(map->fd);
	if (map->copy_file)
		free_tab(map->copy_file);
	if (map->copy_map)
		free_tab(map->copy_map);
}

void	ft_delete(t_data *data)
{
	printf("debut ft_delete\n");
	if (data->name_file)
	 	free(data->name_file);
	free_map(&data->map);
	free_texture(&data->texture);
}