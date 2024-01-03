/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkizrak- <hkizrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:27:45 by hkizrak-          #+#    #+#             */
/*   Updated: 2023/10/31 19:14:17 by hkizrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_strlen(const char *str);
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoinfree(char *s1, char *s2);
char	*ft_get_line(char *s);
char	*ft_after(char *str);
int		ft_check(const char *s);
char	*ft_read(char *str, int fd);
#endif
