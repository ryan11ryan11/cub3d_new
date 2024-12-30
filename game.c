
#include "cub3d.h"

void	verLine(t_info *info, int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(info->mlx, info->win, x, y, color);
		y++;
	}
}

int		game_1(t_info *info)
{
	double	raydirX;
	double	raydirY;
	double	cameraX;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		x;
	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;

	x = 0;
	while (x < window_width)
	{
		hit = 0;
		cameraX = 2 * x / (double)window_width - 1;
		raydirX = info->dir_x + info->plane_x * cameraX;
		raydirY = info->dir_y + info->plane_y * cameraX;
		mapX = (int)info->pos_x;
		mapY = (int)info->pos_y;
		deltaDistX = fabs(1 / raydirX);
		deltaDistY = fabs(1 / raydirY);
		if (raydirX > 0)
		{ 
			stepX = 1;
			sideDistX = (mapX - info->pos_x + 1) * deltaDistX;
		}
		else
		{
			stepX = -1;
			sideDistX = (info->pos_x - mapX) * deltaDistX;
		}
		if (raydirY > 0)
		{
			stepY = 1;
			sideDistY = (mapY - info->pos_y + 1) * deltaDistY;
		}
		else
		{
			stepY = -1;
			sideDistY = (info->pos_y - mapY) * deltaDistY;
		}
		while (hit == 0)
		{
			if (sideDistX > sideDistY)
			{
				sideDistY = sideDistY + deltaDistY;
				mapY = mapY + stepY;
				side = 1;
			}
			else
			{
				sideDistX = sideDistX + deltaDistX;
				mapX = mapX + stepX;
				side = 0;
			}
			if (info->map[mapY][mapX] > '0')
				hit = 1;
		}
		if (side == 0)
			perpWallDist = (mapX - info->pos_x + (1 - stepX) / 2) / raydirX;
		else
			perpWallDist = (mapY - info->pos_y + (1 - stepY) / 2) / raydirY;
		int lineHeight = (int)(window_height/perpWallDist);
		int drawStart = -lineHeight / 2 + window_height / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + window_height / 2;
		if(drawEnd >= window_height)
			drawEnd = window_height - 1;

		int	color;
		if (info->map[mapY][mapX] == '1')
			color = 0xFF0000;
		else if (info->map[mapY][mapX] == '2')
			color = 0x00FF00;
		else if (info->map[mapY][mapX] == '3')
			color = 0x0000FF;
		else if (info->map[mapY][mapX] == '4')
			color = 0xFFFFFF;
		else
			color = 0xFFFF00;
		if (side == 1)
			color = color / 2;
		verLine(info, x, drawStart, drawEnd, color);
		x ++;
	}
	return (0);
}

int	game(t_info *info)
{
	game_1(info);
	mlx_put_image_to_window(info->mlx, info->win, &info->img, 0, 0);
	return (0);
}