/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_formula.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:02:39 by bargarci          #+#    #+#             */
/*   Updated: 2024/08/07 19:31:09 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../fractol.h"

void	set_mandelbrot(t_fractol *fractol)
{
	fractol->formula.c_real = fractol->scale.x_new;
	fractol->formula.c_img = fractol->scale.y_new;
	fractol->formula.z_real = fractol->scale.x_new;
	fractol->formula.z_img = fractol->scale.y_new;
}

void	set_julia(t_fractol *fractol)
{
	fractol->formula.c_real = fractol->param1;
	fractol->formula.c_img = fractol->param2;
	fractol->formula.z_real = fractol->scale.x_new;
	fractol->formula.z_img = fractol->scale.y_new;
}
