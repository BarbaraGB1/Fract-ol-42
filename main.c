/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 21:41:12 by bargarci          #+#    #+#             */
/*   Updated: 2024/08/18 23:13:16 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc < 2)
	{
		print_message();
		return (0);
	}
	check_arguments(&fractol, argv, argc);
	init_mlx(&fractol.data);
	set_struct(&fractol);
	get_hook(&fractol);
	calculate_scale(&fractol.scale, &fractol);
	mlx_put_image_to_window(fractol.data.mlx, fractol.data.mlx_win,
		fractol.data.img, 0, 0);
	mlx_loop(fractol.data.mlx);
	return (0);
}
