/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:15:01 by junhhong          #+#    #+#             */
/*   Updated: 2024/12/30 11:32:24 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include "./minilibx-linux/mlx.h"
#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"

#define KEY_ESC		65307
#define	KEY_PRESS	2
#define	KEY_W		119
#define	KEY_S		115
#define	KEY_A		97
#define	KEY_D		100
#define	KEY_LEFT	65361
#define KEY_RIGHT	65363
#define	X_CLICK		17
#define	t_height	64
#define	t_width		64
#define	num_texture	8
#define window_height		600
#define window_width		600
#define moveSpeed	0.03
#define rotSpeed	0.1

typedef struct s_img
{
	void	*img;
	int	*data;
	int	width;
	int	height;
	int	size_line;
	int	bpp;
	int	endian;
}	t_img;


typedef struct s_info
{
	int		fd;
	int		num_lines;
	int		num_map_lines;
	int		number_news;
	int		**texture;
	int		**window_screen;
	t_img	*window_img;
	float		pos_x;
	float		pos_y;
	float		dir_x;
	float		dir_y;
	double		plane_x;
	double		plane_y;
	char	direction[2];
	char	*path;
	char	**whole_file;
	char	**map;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*F;
	char	*C;
	void	*mlx;
	void	*win;
} t_info;

void	doublearr_free(char **double_arr);
void	free_all(t_info *info);

/*set_info1*/
int		set_info(t_info *info, char *path);
int		set_path(t_info *info, char *path);
int		set_fd(t_info *info);
int		set_num_lines(t_info *info);
int		set_whole_file(t_info *info);

/*set_info2*/
char	*remove_linechange(char *line);
char	*return_value(t_info *info, char *target);
int		set_value(t_info *info);
void	set_all_NULL(t_info *info);
int		set_mlx(t_info *info);

/*set_info3*/
int		set_pos(t_info *info);
void	set_dir_xy(t_info *info, int dir_x, int dir_y);
int		set_dir(t_info *info);
void	set_plane_xy(t_info *info, double x, double y);
int		set_plane(t_info *info);

/*set_info4*/
int		set_texture(t_info *info);
int		texture_init(t_info *info);
/*set_info5*/
int		set_window_screen(t_info *info);
int		window_img_make(t_info *info);

/*set_map*/
int		set_map(t_info *info);
int		map_line_count(char **tmp_file);
int		is_component(char *line);

/*cubfile_check*/
int components_counter(t_info *info, char *target);
int duplicate_check(t_info *info);
int cubfile_check(t_info *info);

/*validity_check_1*/
int	extension_check(const char *path);
int	is_news(char *line);
int	news_check(t_info *info);
int	validity_check(t_info *info);

/*validity_check_block*/
int is_blocked(t_info *info);
int	top_bottom_check(t_info *info);
int	all_1_space(char *line);

/* utils */
void	set_doubleintarr_null(int **arr, int height, int width);
void	doubleintarr_free(int **double_arr, int num);
void	doublearr_free(char **double_arr);
void	free_all(t_info *info);

/* move */
void	press_w(t_info *info);
void	press_s(t_info *info);
void	press_a(t_info *info);
void	press_d(t_info *info);

/* game */
int		game(t_info *info);


/* to be deleted befor submit */
void print_status(t_info *info);