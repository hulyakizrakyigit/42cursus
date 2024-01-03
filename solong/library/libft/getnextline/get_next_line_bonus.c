/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkizrak- <hkizrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:27:38 by hkizrak-          #+#    #+#             */
/*   Updated: 2023/10/31 19:13:10 by hkizrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(char *str, int fd)
{
	char	*temp;
	int		readed;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	readed = 1;
	while (!ft_check(str) && readed != 0)
	{
		readed = read(fd, temp, BUFFER_SIZE);
		if (readed == -1)
		{
			if (str)
				free(str);
			free(temp);
			return (NULL);
		}
		temp[readed] = '\0';
		str = ft_strjoinfree(str, temp);
	}
	free(temp);
	return (str);
}

char	*ft_get_line(char *s)
{
	int		i;
	char	*line;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_after(char *s)
{
	char	*after;
	int		len;
	int		i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	len = (ft_strlen(s) - i);
	if (len == 0)
	{
		free(s);
		return (NULL);
	}
	after = ft_substr(s, i, len);
	free (s);
	return (after);
}

char	*get_next_line(int fd)
{
	static char	*str[10240];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = ft_read(str[fd], fd);
	if (!str[fd] || !*str[fd])
	{
		if (str[fd])
			free(str[fd]);
		str[fd] = NULL;
		return (NULL);
	}
	line = ft_get_line(str[fd]);
	str[fd] = ft_after(str[fd]);
	return (line);
}
