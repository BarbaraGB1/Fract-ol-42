/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_factors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:04:09 by bargarci          #+#    #+#             */
/*   Updated: 2024/08/05 18:45:44 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../fractol.h"

void	set_factors(t_factors *factors)
{
	factors->zoom = 0.7;
	factors->trans_x = 0.0;
	factors->trans_y = 0.0;
	factors->iters = 12;
}
