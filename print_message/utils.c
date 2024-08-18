#include "../fractol.h"

int	condintions(char *line)
{
		if (!ft_strncmp(line, "YES\n", ft_strlen("YES") + 1)
			|| !ft_strncmp(line, "y\n", ft_strlen("y") + 1))
		{
			print_controls();
			free(line);
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
