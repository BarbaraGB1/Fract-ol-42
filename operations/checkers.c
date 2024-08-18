/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:14:49 by bargarci          #+#    #+#             */
/*   Updated: 2024/08/18 23:02:54 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../fractol.h"

int	check_arguments(t_fractol *fractol, char **argv, int argc)
{
	fractol->name = NULL;
	fractol->argv = argv;
	fractol->argc = argc;
	if (!ft_strncmp(argv[1], "Mandelbrot\0", ft_strlen("Mandelbrot") + 1)
		&& argc == 2)
	{
		fractol->name = "mandelbrot";
		return (0);
	}
	if (!ft_strncmp(argv[1], "Julia\0", ft_strlen("Julia") + 1)
		&& (argc == 4))
	{
		if (check_doubles(fractol) && check_doubles_max(fractol))
		{
			fractol->name = "julia";
			return (0);
		}
	}
	print_message();
	exit(1);
}

void	check_type(t_fractol *fractol)
{
	if (!ft_strncmp(fractol->name, "mandelbrot\0", ft_strlen("mandelbrot")))
		set_mandelbrot(fractol);
	if (!ft_strncmp(fractol->name, "julia", ft_strlen("julia")))
		set_julia(fractol);
}

int	check_doubles(t_fractol *fractol)
{
	int	i;
	int	j;
	int	bool;

	i = 1;
	if (fractol->argv[2][0] == '\0' || fractol->argv[3][0] == '\0')
		return (0);
	while (fractol->argv[++i])
	{
		bool = 0;
		j = 0;
		if (fractol->argv[i][j] == '-')
			j++;
		while (fractol->argv[i][j])
		{
			if (ft_isdigit(fractol->argv[i][j]))
				j++;
			else if (fractol->argv[i][j] == '.' && bool == 0)
			{
				bool = 1;
				j++;
			}
			else
				return (0);
		}
	}
	return (1);
}

int	check_doubles_max(t_fractol *fractol)
{
	if (ft_strlen(fractol->argv[2]) > 10 || ft_strlen(fractol->argv[3]) > 10)
		return (0);
	fractol->param1 = ft_atod(fractol->argv[2]);
	fractol->param2 = ft_atod(fractol->argv[3]);
	return (1);
}
