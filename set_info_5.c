/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:43:30 by junhhong          #+#    #+#             */
/*   Updated: 2024/12/24 14:36:58 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_window_screen(t_info *info)
{
	int	i;

	i = 0;
	info->window_screen = (int **)malloc(sizeof(int *) * window_height);
	if (!info->window_screen)
	{
		ft_putstr_fd("Error window screen init\n", 2);
		return (1);
	}
	while (i < window_height)
	{
		info->window_screen[i] = (int *)malloc(sizeof(int) * window_width);
		if (!info->window_screen[i])
		{
			doubleintarr_free(info->window_screen, i - 1);
			info->window_screen = NULL;
			return (1);
		}
		i ++;
	}
	set_doubleintarr_null(info->window_screen, window_height, window_width);
	return (0);
}
