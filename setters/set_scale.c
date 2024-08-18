/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:03:13 by bargarci          #+#    #+#             */
/*   Updated: 2024/08/18 12:53:11 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../fractol.h"

void	set_struct(t_fractol *fractol)
{
	set_scale(&fractol->scale);
	set_factors(&fractol->factors);
	set_colors(&fractol->colors);
}

void	set_scale(t_scale *scale)
{
	scale->x_new = 0.0;
	scale->y_new = 0.0;
	scale->x_original = 0.0;
	scale->y_original = 0.0;
	scale->new_min = -4;
	scale->new_max = 4;
	scale->old_min = 0.0;
	scale->old_max = 799;
}
