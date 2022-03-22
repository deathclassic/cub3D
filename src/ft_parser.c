/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:58:38 by cdelaine          #+#    #+#             */
/*   Updated: 2022/03/22 16:08:34 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

char	**start_parsing(char *fname, t_config *config)
{
	t_listt	*lst;
	char	**map;
	int		fd;

	lst = NULL;
	map = NULL;
	if (ft_strlen2(fname) <= 4)
		error_handler(1);
	if (ft_strncmp2(&(fname[ft_strlen2(fname) - 4]), ".cub", 5))
		error_handler(1);
	init_config(config);
	fd = open(fname, O_RDONLY);
	if (fd < 0)
		error_handler(2);
	if (get_config(fd, config))
		error_handler(3);
	if (get_map_line(&lst, fd) || list_checker(lst))
		error_handler(4);
	map = lst_to_map(lst, config);
	list_clear(&lst);
	return (map);
}

void	free_config(t_config *config)
{
	free(config->north);
	free(config->south);
	free(config->west);
	free(config->east);
}

int	ft_parser(char **argv, t_config *config, t_data *data)
{
	init_draw(data);
	config->map2 = start_parsing(argv[1], config);
	ft_copy(data, config);
	if (ft_check_map_char(data)|| ft_check_map_border(data) || data->p_info->direction == '\0'
		|| data->p_coord->y == -1 || data->p_coord->x == -1)
		error_handler(4);
	return (0);
}
