/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 12:39:16 by bargarci          #+#    #+#             */
/*   Updated: 2024/08/18 23:02:24 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../fractol.h"

void	calculate_magn(t_formula *formula)
{
	double	a;
	double	b;

	a = formula->z_img * formula->z_img;
	b = formula->z_real * formula->z_real;
	formula->magn = a + b;
}

void	calculate_total(t_formula *formula)
{
	formula->z_real = formula->z_real + formula->c_real;
	formula->z_img = formula->z_img + formula->c_img;
}

void	calculate_z(t_formula *formula)
{
	double	a;
	double	b;
	double	ab;

	a = formula->z_real * formula->z_real;
	b = formula->z_img * formula->z_img;
	ab = formula->z_real * formula->z_img;
	formula->z_img = ab + ab;
	formula->z_real = a - b;
}

void	calculate_form(t_formula *formula)
{
	calculate_z(formula);
	calculate_total(formula);
	calculate_magn(formula);
}

void	recursive(t_fractol *fractol)
{
	double	i;

	i = 1;
	check_type(fractol);
	while (i < fractol->factors.iters)
	{
		calculate_form(&fractol->formula);
		if (fractol->formula.magn > 2)
		{
			get_color(i, fractol->factors.iters, &fractol->colors);
			my_mlx_pixel_put(&fractol->data, fractol->scale.x_original,
				fractol->scale.y_original, fractol->colors.out_set);
			return ;
		}
		i++;
	}
	if (fractol->colors.bol == 1)
		fractol->colors.in_set = 0xFF00000 * fractol->formula.magn;
	my_mlx_pixel_put(&fractol->data, fractol->scale.x_original,
		fractol->scale.y_original, fractol->colors.in_set);
}
