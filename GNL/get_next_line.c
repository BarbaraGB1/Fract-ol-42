/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:14:30 by bargarci          #+#    #+#             */
/*   Updated: 2023/05/08 15:02:22 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_new_line(char *s)
{
	char	*new;
	int		i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\n')
		new = malloc(sizeof(char) * (i + 2));
	else
		new = malloc(sizeof(char) * (i + 1));
	if (!new)
		return (0);
	i = -1;
	while (s[++i] != '\n' && s[i] != '\0')
		new[i] = s[i];
	if (s[i] == '\n')
		new[i++] = '\n';
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin_getnl(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!s1 && s2)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[j] != '\0')
	{
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*rest;	
	char		*buffer;
	int			nbyts;
	char		*new_line;

	nbyts = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	while (!ft_count_getnl(rest) && nbyts != 0)
	{
		nbyts = read(fd, buffer, BUFFER_SIZE);
		if (nbyts == -1)
			return (free(buffer), free(rest), rest = NULL, NULL);
		buffer[nbyts] = '\0';
		rest = ft_strjoin_getnl(rest, buffer);
	}
	free (buffer);
	if (rest && rest[0] == '\0')
		return (free(rest), rest = NULL, NULL);
	return (new_line = ft_new_line(rest), rest = garbage(rest), new_line);
}

/*void	leaks(void)
{
	system("leaks a.out");
}

int	main(void)
{
	int		fd;
	char	*line;
	
	//atexit(leaks);
	fd = open("null", O_RDONLY);
	if (fd < 0)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
		
	}
	close(fd);
}*/
