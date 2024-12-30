
#include "cub3d.h"

void	press_w(t_info *info)
{
	double	nextMoveX;
	double	nextMoveY;

	nextMoveX = info->pos_x + info->dir_x * moveSpeed;
	nextMoveY = info->pos_y + info->dir_y * moveSpeed;
	if (info->map[(int)(nextMoveY)][(int)(nextMoveX)] == '0')
	{
		info->pos_x += info->dir_x * moveSpeed;
		info->pos_y += info->dir_y * moveSpeed;
	}
}

void	press_s(t_info *info)
{
	double	nextMoveX;
	double	nextMoveY;

	nextMoveX = info->pos_x + info->dir_x * moveSpeed;
	nextMoveY = info->pos_y + info->dir_y * moveSpeed;
	if (info->map[(int)(nextMoveY)][(int)(nextMoveX)] == '0')
	{
		info->pos_x -= info->dir_x * moveSpeed;
		info->pos_y -= info->dir_y * moveSpeed;
	}
}

void	press_d(t_info *info)
{
	double	prv_dirX;
	double	prv_planeX;

	prv_dirX = info->dir_x;
	prv_planeX = info->plane_x;
	info->dir_x = info->dir_x * cos(-rotSpeed) - info->dir_y * sin(-rotSpeed);
	info->dir_y = prv_dirX * sin(-rotSpeed) + info->dir_y * cos(-rotSpeed);
	info->plane_x = info->plane_x * cos(-rotSpeed) - info->plane_y * sin(-rotSpeed);
	info->plane_y = prv_planeX * sin(-rotSpeed) + info->plane_y * cos(-rotSpeed);
}

void	press_a(t_info *info)
{
	double	prv_dirX;
	double	prv_planeX;

	prv_dirX = info->dir_x;
	prv_planeX = info->plane_x;
	info->dir_x = info->dir_x * cos(rotSpeed) - info->dir_y * sin(rotSpeed);
	info->dir_y = prv_dirX * sin(rotSpeed) + info->dir_y * cos(rotSpeed);
	info->plane_x = info->plane_x * cos(rotSpeed) - info->plane_y * sin(rotSpeed);
	info->plane_y = prv_planeX * sin(-rotSpeed) + info->plane_y * cos(-rotSpeed);
}