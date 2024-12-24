/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 10:55:36 by junhhong          #+#    #+#             */
/*   Updated: 2024/12/24 16:40:00 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	texture_init(t_info *info)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	info->texture = (int **)malloc(sizeof(int **) * num_texture);
	if (!info->texture)
		return (1);
	while (i < num_texture)
	{
		info->texture[i] = (int *)malloc(sizeof(int) * t_height * t_width);
		if (!info->texture[i])
			return (1);
		while (j < t_height * t_width)
		{
			info->texture[i][j] = 0;
			j ++;
		}
		i ++;
	}
	return (0);
}

int	fill_texture(t_info *info, char *path, int *target)
{
	t_img	img;
	int		*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0; 
	img.img = mlx_xpm_file_to_image(info->mlx, path, &img.width, &img.height);
	if (img.img == NULL)
		return (1);
	tmp = (int *)mlx_get_data_addr(img.img, &img.bpp, &img.size_line, &img.endian);
	while(i < img.height)
	{
		while (j < img.width)
		{
			target[img.height * i + j] =  tmp[img.height * i + j];
			j ++;
		}
		j = 0;
		i ++;
	}
	mlx_destroy_image(info->mlx, img.img);
	return (0);
}

int	apply_image(t_info *info)
{
	if (fill_texture(info, "textures/eagle.xpm", info->texture[0]) ||
	fill_texture(info, "textures/redbrick.xpm", info->texture[1]) ||
	fill_texture(info, "textures/purplestone.xpm", info->texture[2]) ||
	fill_texture(info, "textures/greystone.xpm", info->texture[3]) ||
	fill_texture(info, "textures/mossy.xpm", info->texture[4]) ||
	fill_texture(info, "textures/wood.xpm", info->texture[5]) ||
	fill_texture(info, "textures/colorstone.xpm", info->texture[6]) ||
	fill_texture(info, "textures/pillar.xpm", info->texture[7]))
	{
		ft_putstr_fd("Error apply image\n", 2);
		return (1);
	}
	return (0);
}

int	set_texture(t_info *info)
{
	if (texture_init(info))
	{
		ft_putstr_fd("Error on texture init\n", 2);
		return (1);
	}
	if (apply_image(info))
		return (1);
	return (0);
}
