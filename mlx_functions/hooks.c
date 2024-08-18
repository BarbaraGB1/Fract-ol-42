/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:08:31 by bargarci          #+#    #+#             */
/*   Updated: 2024/08/18 21:54:32 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../fractol.h"

void	hook_zoom(t_fractol *fractol, int keycode)
{
	if (keycode == ZOOM_IN)
		fractol->factors.zoom /= 1.1;
	if (keycode == ZOOM_OUT)
		fractol->factors.zoom *= 1.1;
}

void	hook_trans(t_fractol *fractol, int keycode)
{
	if (keycode == MOVE_UP)
		fractol->factors.trans_y -= (0.1 * fractol->factors.zoom);
	if (keycode == MOVE_DOWN)
		fractol->factors.trans_y += (0.1 * fractol->factors.zoom);
	if (keycode == MOVE_L)
		fractol->factors.trans_x -= (0.1 * fractol->factors.zoom);
	if (keycode == MOVE_R)
		fractol->factors.trans_x += (0.1 * fractol->factors.zoom);
}

void	hook_iters(t_fractol *fractol, int keycode)
{
	if (keycode == PLUS_ITER)
		fractol->factors.iters += 1;
	if (keycode == LESS_ITER)
	{
		if (fractol->factors.iters > 4)
			fractol->factors.iters -= 1;
	}
}

void	hook_colors(t_fractol *fractol, int keycode)
{
	if (keycode == COLOR_A)
		set_colors(&fractol->colors);
	if (keycode == COLOR_B)
		color_b(fractol);
	if (keycode == COLOR_C)
		color_c(fractol);
	if (keycode == COLOR_D)
		color_d(fractol);
}
