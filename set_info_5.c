/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:43:30 by junhhong          #+#    #+#             */
/*   Updated: 2024/12/24 17:01:23 by junhhong         ###   ########.fr       */
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

int	window_img_make(t_info *info)
{
	info->window_img = (t_img *)malloc(sizeof(t_img));
	info->window_img->img = NULL;
	if (!info->window_img)
		return (1);
	info->window_img->img = mlx_new_image(info->mlx, window_width, window_height);
	if (!info->window_img->img)
	{
		free(info->window_img);
		info->window_img = NULL;
		ft_putstr_fd("Error window img init\n", 2);
		return (1);
	}
	info->window_img->data = (int *)mlx_get_data_addr(info->window_img->img, &info->window_img->bpp, &info->window_img->size_line, &info->window_img->endian);
	if (!info->window_img->data)
	{
		free(info->window_img);
		info->window_img = NULL;
		ft_putstr_fd("Error window img data init\n", 2);
		return (1);
	}
	return (0);
}
