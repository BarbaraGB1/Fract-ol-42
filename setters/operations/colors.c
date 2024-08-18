/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:31:32 by bargarci          #+#    #+#             */
/*   Updated: 2024/08/18 14:09:52 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../fractol.h"

int	interpolate_color(int start_color, int end_color, double ratio)
{
	int	red;
	int	green;
	int	blue;

	red = ((start_color >> 16) & 0xFF) + ratio * (((end_color >> 16) & 0xFF)
			- ((start_color >> 16) & 0xFF));
	green = ((start_color >> 8) & 0xFF) + ratio * (((end_color >> 8) & 0xFF)
			- ((start_color >> 8) & 0xFF));
	blue = (start_color & 0xFF) + ratio * ((end_color & 0xFF)
			- (start_color & 0xFF));
	return ((red << 16) | (green << 8) | blue);
}

void	get_color(int iterations, int max_iterations, t_colors *colors)
{
	int		palette_index;
	double	ratio;

	palette_index = (iterations * 4.0) / max_iterations;
	ratio = (double)(iterations % (max_iterations / 4))
		/ (max_iterations / 4.0);
	colors->out_set = interpolate_color(colors->palette_1[palette_index],
			colors->palette_1[palette_index + 1], ratio);
}
