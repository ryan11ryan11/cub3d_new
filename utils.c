/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:53:11 by junhhong          #+#    #+#             */
/*   Updated: 2024/12/30 10:52:24 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_doubleintarr_null(int **arr, int height, int width)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < height)
	{
		while (j < width)
		{
			arr[i][j] = 0;
			j ++;
		}
		j = 0;
		i ++;
	}
}

void	doubleintarr_free(int **double_arr, int num)
{
	int	i;

	i = 0;
	if(double_arr == NULL)
		return ;
	while (i < num)
	{
		free(double_arr[i]);
		i ++;
	}
	free (double_arr);
}

void	doublearr_free(char **double_arr)
{
	int	i;

	i = 0;
	if (double_arr == NULL)
		return ;
	while (double_arr[i])
	{
        free(double_arr[i]);
		i ++;
	}
	free(double_arr);
}

void	free_all(t_info *info)
{
	close(info->fd);
	if (info->win)
		mlx_destroy_window(info->mlx, info->win);
	if (info->whole_file != NULL)
		doublearr_free(info->whole_file);
	if (info->NO != NULL)
		free(info->NO);
	if (info->SO != NULL)
		free(info->SO);
	if (info->WE != NULL)
		free(info->WE);
	if (info->EA != NULL)
		free(info->EA);
	if (info->F != NULL)
		free(info->F);
	if (info->C != NULL)
		free(info->C);
	if (info->path != NULL)
		free(info->path);
	if (info->map != NULL)
		doublearr_free(info->map);
	if (info->texture != NULL)
		doubleintarr_free(info->texture, num_texture);
	if (info->window_screen != NULL)
		doubleintarr_free(info->window_screen, window_height);
	if (info->window_img != NULL && info->window_img->img != NULL)
	{
		mlx_destroy_image(info->mlx, info->window_img->img);
		info->window_img->img = NULL;
	}
	if (info->window_img)
		free(info->window_img);
	if (info->mlx)
		free(info->mlx);
}
