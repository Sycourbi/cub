/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:58:02 by sycourbi          #+#    #+#             */
/*   Updated: 2023/11/27 15:05:08 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_texture(t_data *data)
{
	data->texture.color_C = NULL;
	data->texture.color_F = NULL;
	data->texture.text_north = NULL;
	data->texture.text_south = NULL;
	data->texture.text_east = NULL;
	data->texture.text_west = NULL;
}

void	init_data(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->win_height = 0;
	data->win_width = 0;
	data->name_file = NULL;
	data->map.copy_file = NULL;
	data->map.copy_map = NULL;
	init_texture(data);
}