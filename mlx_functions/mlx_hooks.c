/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:32:00 by bargarci          #+#    #+#             */
/*   Updated: 2024/08/18 14:15:16 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../fractol.h"

int	key_hook(int keycode, t_fractol *fractol)
{
	if (keycode == ESCAPE)
		close_win(&fractol->data);
	else if (keycode == RESTART)
		set_struct(fractol);
	else if (keycode == ZOOM_IN || keycode == ZOOM_OUT)
		hook_zoom(fractol, keycode);
	else if (keycode == MOVE_UP || keycode == MOVE_DOWN || keycode == MOVE_L
		|| keycode == MOVE_R)
		hook_trans(fractol, keycode);
	else if (keycode == PLUS_ITER || keycode == LESS_ITER)
		hook_iters(fractol, keycode);
	else if (keycode == COLOR_A || keycode == COLOR_B || keycode == COLOR_C
			|| keycode == COLOR_D)
		hook_colors(fractol, keycode);
	else
		return (0);
	calculate_scale(&fractol->scale, fractol);
	mlx_put_image_to_window(fractol->data.mlx, fractol->data.mlx_win,
		fractol->data.img, 0, 0);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_fractol *fractol)
{
	if (x == -900 && y == -900)
		return (0);
	if (keycode == MOUSE_IN)
		fractol->factors.zoom *= 1.1;
	else if (keycode == MOUSE_OUT)
		fractol->factors.zoom /= 1.1;
	else
		return (0);
	
	calculate_scale(&fractol->scale, fractol);
	mlx_put_image_to_window(fractol->data.mlx, fractol->data.mlx_win,
		fractol->data.img, 0, 0);
	return (0);
}

int	close_win(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(EXIT_SUCCESS);
}

void	get_hook(t_fractol *fractol)
{
	mlx_mouse_hook(fractol->data.mlx_win, mouse_hook, fractol);
	mlx_key_hook(fractol->data.mlx_win, key_hook, fractol);
	mlx_hook(fractol->data.mlx_win, 17, 0, close_win, &fractol->data);
}
