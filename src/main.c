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

int	main(int argc, char **argv)
{
	t_data	data;
	
	if (argc != 2)
		return (printf("problem nbr arg\n"), 1);
	init_data(&data);
	if (check_arg(argv[1], &data))
		return (0);
	
	printf("fin du programme tout est nickel\n");
	return (0);
}