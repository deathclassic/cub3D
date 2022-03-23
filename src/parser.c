/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharmel <tcharmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:21:16 by                   #+#    #+#             */
/*   Updated: 2022/03/23 11:41:54 by tcharmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_draw(t_data *data)
{
	data->p_info.width = 0;
	data->p_info.height = 0;
	data->p_info.screen_height = 720;
	data->p_info.screen_width = 1280;
	data->p_info.direction = '\0';
	data->p_coord.x = -1;
	data->p_coord.y = -1;
	data->p_coord.vec_x = 0;
	data->p_coord.vec_y = 0;
	data->p_coord.angle = 0.66;
	data->p_coord.ray_vec_x = 0;
	data->p_coord.ray_vec_y = 0;
	data->p_coord.move_speed = 0.2;
	data->p_coord.rot_speed = M_PI / 32;
	data->p_draw.f_red = -1;
	data->p_draw.f_green = -1;
	data->p_draw.f_blue = -1;
	data->p_draw.c_red = -1;
	data->p_draw.c_blue = -1;
	data->p_draw.c_green = -1;
	data->p_draw.path_e = NULL;
	data->p_draw.path_w = NULL;
	data->p_draw.path_n = NULL;
	data->p_draw.path_s = NULL;
	data->p_info.flag = 0;
}
