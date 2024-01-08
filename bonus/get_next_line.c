/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:13:43 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/05 02:27:13 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_line(char **s)
{
	char	*str;
	char	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*(*s + i) && *(*s + i) != '\n')
		i++;
	if (*(*s + i) == '\n')
		i++;
	str = (char *)malloc(i + 1);
	if (!str)
		return (free(*s), *s = NULL, NULL);
	while (j < i)
	{
		*(str + j) = *(*s + j);
		j++;
	}
	return (*(str + j) = '\0', tmp = ft_strdup_get(*s + i),
		free(*s), *s = tmp, str);
}

static int	ft_read(char **saves, int fd)
{
	char	*buffer;
	int		length;

	buffer = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (free(*saves), *saves = NULL, -1);
	length = read(fd, buffer, BUFFER_SIZE);
	if (length <= 0)
		return (free(buffer), length);
	*(buffer + length) = '\0';
	*saves = ft_strjoin_get(*saves, buffer);
	free(buffer);
	if (!saves || !*saves)
		return (-1);
	return (length);
}

char	*get_next_line(int fd)
{
	static char	*saves = NULL;
	int			length;

	if (fd < 0 || fd > 10240 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (free(saves), saves = NULL, NULL);
	length = 1;
	while (ft_strchr_get(saves, '\n') == -1 && length > 0)
		length = ft_read(&saves, fd);
	if (length <= 0 && (!saves || !*saves))
		return (free(saves), saves = NULL, NULL);
	return (ft_get_line(&saves));
}
