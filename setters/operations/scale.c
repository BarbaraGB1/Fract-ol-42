/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 12:38:20 by bargarci          #+#    #+#             */
/*   Updated: 2024/08/07 15:32:56 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../fractol.h"

double	interpolate(double coor, t_scale *scale)
{
	double	new_scale;

	new_scale = ((scale->new_max - scale->new_min) * (coor - scale->old_min))
		/ (scale->old_max - scale->old_min) + scale->new_min;
	return (new_scale);
}

void	calculate_scale(t_scale *scale, t_fractol *fractol)
{
	scale->y_original = 0;
	while (scale->y_original < HIGTH)
	{
		while (scale->x_original < WIDTH)
		{
			scale->x_new = (interpolate(scale->x_original, scale)
					* fractol->factors.zoom) + fractol->factors.trans_x;
			scale->y_new = (interpolate(scale->y_original, scale)
					* fractol->factors.zoom) + fractol->factors.trans_y;
			recursive(fractol);
			scale->x_original++;
		}
		scale->x_original = 0;
		scale->y_original++;
	}
}
