/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 22:34:50 by bargarci          #+#    #+#             */
/*   Updated: 2024/08/18 23:20:47 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_H
# define FRACTOL_H
# include "codes.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "GNL/get_next_line.h"
# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# define WIDTH 800
# define HIGTH 800

//STRUCTS OF MLX
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
}	t_data;

//STRUCTS OF FRACTOL

typedef struct s_scale
{
	double	x_original;
	double	y_original;
	double	x_new;
	double	y_new;
	double	old_min;
	double	old_max;
	double	new_min;
	double	new_max;
}	t_scale;

typedef struct s_formula
{
	double	c_real;
	double	c_img;
	double	z_real;
	double	z_img;
	double	magn;
}	t_formula;

typedef struct s_factors
{
	double	trans_x;
	double	trans_y;
	double	zoom;
	double	iters;
}	t_factors;

typedef struct s_colors
{
	int	palette_1[5];
	int	in_set;
	int	out_set;
	int	bol;
}	t_colors;

typedef struct s_fractol
{
	t_scale		scale;
	t_formula	formula;
	t_factors	factors;
	t_colors	colors;
	t_data		data;
	int			argc;
	char		**argv;
	char		*name;
	double		param1;
	double		param2;
}	t_fractol;

//MLX FUNCTIONS
void	init_mlx(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//--> HOOKS
void	get_hook(t_fractol *fractol);
int		mouse_hook(int keycode, int x, int y, t_fractol *fractol);
int		key_hook(int keycode, t_fractol *fractol);
void	hook_zoom(t_fractol *fractol, int keycode);
void	hook_trans(t_fractol *fractol, int keycode);
void	hook_iters(t_fractol *fractol, int keycode);
void	hook_colors(t_fractol *fractol, int keycode);
void	color_b(t_fractol *fractol);
void	color_c(t_fractol *fractol);
void	color_d(t_fractol *fractol);
int		close_win(t_data *data);

//--> SETS
void	set_struct(t_fractol *fractol);
void	set_scale(t_scale *scale);
void	set_factors(t_factors *factors);
void	set_colors(t_colors *colors);
void	set_mandelbrot(t_fractol *fractol);
void	set_julia(t_fractol *fractol);

//--> SCALE
double	interpolate(double coor, t_scale *scale);
void	calculate_scale(t_scale *scale, t_fractol *fractol);

//-->FORMULA
void	calculate_form(t_formula *formula);
void	calculate_z(t_formula *formula);
void	calculate_total(t_formula *formula);
void	calculate_magn(t_formula *formula);
void	recursive(t_fractol *fractol);
int		interpolate_color(int start_color, int end_color, double ratio);
void	get_color(int iterations, int max_iterations, t_colors *colors);

//--> CHEKCS
int		check_arguments(t_fractol *fractol, char **argv, int argc);
void	check_type(t_fractol *fractol);
int		check_doubles(t_fractol *fractol);
int		aux_double(t_fractol *fractol, int i, int j);
int		check_doubles_max(t_fractol *fractol);

//--> PRINTS
void	print_message(void);
void	print_resume(void);
void	print_examples(void);
void	print_remenber(void);
void	print_controls(void);
void	do_gnl(void);
int		condintions(char *line);
#endif
