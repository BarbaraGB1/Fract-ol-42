/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:55:50 by bargarci          #+#    #+#             */
/*   Updated: 2024/08/18 21:48:39 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../fractol.h"

void	color_b(t_fractol *fractol)
{
	fractol->colors.palette_1[0] = 0x0c457d;
	fractol->colors.palette_1[1] = 0x6bd2db;
	fractol->colors.palette_1[2] = 0x0ea7b5;
	fractol->colors.palette_1[3] = 0xffbe4f;
	fractol->colors.palette_1[4] = 0xffecb8;
	fractol->colors.in_set = 0x0000000;
	fractol->colors.bol = 0;
}

void	color_c(t_fractol *fractol)
{
	
	fractol->colors.palette_1[0] = 0x6a0d83;
	fractol->colors.palette_1[1] = 0x660066;
	fractol->colors.palette_1[2] = 0x00FFFF;
	//fractol->cocolo.->palette_1[3] = 0xd896ff;
	fractol->colors.palette_1[3] = 0xFFFFFF;
	fractol->colors.in_set = 0x0000000;
	fractol->colors.bol = 0;
}

void	color_d(t_fractol *fractol)
{
	set_colors(&fractol->colors);	
	fractol->colors.palette_1[0] = 0x000000;
	fractol->colors.palette_1[1] = 0x000000;
	fractol->colors.palette_1[2] = 0x000000;
	// // //fractol->cocolo.->palette_1[30 = 0xd896ff;
	fractol->colors.palette_1[3] = 0xFF0000;
	fractol->colors.bol = 1;
}
