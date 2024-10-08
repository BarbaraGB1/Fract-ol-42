/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:15:23 by bargarci          #+#    #+#             */
/*   Updated: 2023/05/12 13:40:55 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_count_getnl(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*garbage(char *rest)
{
	int		i;
	char	*aux;
	int		len;

	i = 0;
	if (!rest)
		return (NULL);
	while (rest[i] != '\n' && rest[i] != '\0')
		i++;
	len = ft_strlen(rest);
	aux = ft_substr_getnl(rest, (i + 1), (len - i));
	free(rest);
	return (aux);
}

char	*ft_substr_getnl(char const *s, size_t start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	lens;

	i = (size_t)start;
	j = 0;
	if (!s)
		return (0);
	lens = ft_strlen(s);
	if ((len > lens) || ((start + len) > lens))
		len = ft_strlen(s) - start;
	if (start >= lens)
		return (NULL);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (j < len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
