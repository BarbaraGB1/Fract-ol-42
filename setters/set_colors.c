/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 12:50:30 by bargarci          #+#    #+#             */
/*   Updated: 2024/08/18 21:49:43 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../fractol.h"

void	set_colors(t_colors *colors)
{

	colors->palette_1[0] = 0x6a0d83;
	colors->palette_1[1] = 0x660066;
	colors->palette_1[2] = 0xbe29ec;
	//colors->palette_1[3] = 0xd896ff;
	colors->palette_1[3] = 0xFFFFFF;
	colors->in_set = 0x000000;
	colors->bol = 0;
}
