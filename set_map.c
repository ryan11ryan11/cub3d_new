/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:35:50 by junhhong          #+#    #+#             */
/*   Updated: 2024/11/27 16:26:59 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int map_line_count(char **tmp_file)
{
	char	**tmp;
	int		num_lines;

	num_lines = 0;
	tmp = tmp_file;
	while (*tmp)
	{
		num_lines ++;
		tmp ++;
	}
	return (num_lines);
}

int	is_component(char *line)
{
	if (strncmp(line, "NO", 2) == 0)
		return (0);
	if (strncmp(line, "SO", 2) == 0)
		return (0);
	if (strncmp(line, "WE", 2) == 0)
		return (0);
	if (strncmp(line, "EA", 2) == 0)
		return (0);
	if (strncmp(line, "F", 1) == 0)
		return (0);
	if (strncmp(line, "C", 1) == 0)
		return (0);
	return (1);
}

int	set_map(t_info *info)
{
	char	**tmp_file;
	int		num_lines;
	int		i;

	i = 0;
	tmp_file = info->whole_file + info->num_lines - 1;
	while (is_component(*tmp_file))
		tmp_file --;
	tmp_file ++;
	num_lines = map_line_count(tmp_file);
	info->num_map_lines = num_lines;
	if (num_lines <= 0)
	{
		ft_putstr_fd("Map does not exist in cubfile\n", 2);
		return (1);
	}
	info->map = (char **)malloc(sizeof(char *) * (num_lines + 1));
	while(*tmp_file != NULL)
	{
		info->map[i] = ft_strdup(*tmp_file);
		tmp_file ++;
		i ++;
	}
	info->map[num_lines] = NULL;
	return (0);
}
