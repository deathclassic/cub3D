/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:30:04 by                   #+#    #+#             */
/*   Updated: 2022/03/22 16:21:42 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"
#include "../parser.h"

void	free_error(t_config *config, t_data *data)
{
	free_config(config);
	free_all2(config->map2);
	ft_error(data);
}

void	ft_copy(t_data *data, t_config *config)
{
	data->p_draw.path_n = config->north;
	data->p_draw.path_s = config->south;
	data->p_draw.path_w = config->west;
	data->p_draw.path_e = config->east;
	data->p_draw.f_color = config->floor;
	data->p_draw.c_color = config->ceiling;
	data->p_info.arr = config->map2;
	data->p_info.width = config->width;
	data->p_info.height = config->height;
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_config	config;

	if (argc != 2)
		error_handler(0);
	else
	{
		if (ft_parser(argv, &config, &data))
			free_error(&config, &data);
		ft_draw_general(&data);
	}
	free_all(&data);
	return (0);
}
