/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:58:43 by bargarci          #+#    #+#             */
/*   Updated: 2024/08/18 23:50:48 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../fractol.h"

int	condintions(char *line)
{
	if (line == NULL)
	{
		free(line);
		return (0);
	}
	if (!ft_strncmp(line, "YES\n", ft_strlen("YES") + 1)
		|| !ft_strncmp(line, "y\n", ft_strlen("y") + 1))
	{
		free(line);
		print_controls();
		return (0);
	}
	else if (!ft_strncmp(line, "NO\n", ft_strlen("NO") + 1)
		|| !ft_strncmp(line, "n\n", ft_strlen("n") + 1))
	{
		free(line);
		return (0);
	}
	else
	{
		free (line);
		ft_printf("-Please write YES or NO-\n");
		return (1);
	}
}

void	do_gnl(void)
{
	char	*line;

	while (1)
	{
		ft_printf("> (y/n):");
		line = get_next_line(0);
		if (!condintions(line))
			break ;
	}
}
