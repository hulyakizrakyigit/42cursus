/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkizrak- <hkizrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:15:22 by hkizrak-          #+#    #+#             */
/*   Updated: 2023/12/21 16:32:03 by hkizrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_s(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*p;
	int		i;
	int		s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (len > s_len - start)
		len = s_len - start;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoinfree(char *a, char *b)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	if (!a)
	{
		a = malloc(sizeof(char) * 1);
		a[0] = '\0';
	}
	str = malloc((ft_strlen(a) + ft_strlen(b) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (a[i])
	{
		str[i] = a[i];
		i++;
	}
	j = 0;
	while (b[j])
		str[i++] = b[j++];
	str[i] = '\0';
	free(a);
	return (str);
}
