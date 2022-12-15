/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uakkan <uakkan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:19:33 by uakkan            #+#    #+#             */
/*   Updated: 2022/12/05 15:36:44 by uakkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_read_line(int fd, char *readline)
{
	char	*data;
	int		i;

	data = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!data)
		return (NULL);
	i = 1;
	while (!ft_strchr(readline, '\n') && i != 0)
	{
		i = read(fd, data, BUFFER_SIZE);
		if (i == -1)
		{
			free(data);
			return (NULL);
		}
		data[i] = '\0';
		readline = ft_strjoin(readline, data);
	}
	free(data);
	return (readline);
}

char	*ft_get_before_newline(char *readline)
{
	int		i;
	char	*data;

	i = 0;
	if (!readline[i])
		return (NULL);
	while (readline[i] && readline[i] != '\n')
		i++;
	data = (char *)malloc(sizeof(char) * (i + 2));
	if (!data)
		return (NULL);
	i = 0;
	while (readline[i] && readline[i] != '\n')
	{
		data[i] = readline[i];
		i++;
	}
	if (readline[i] == '\n')
	{
		data[i] = readline[i];
		i++;
	}
	data[i] = '\0';
	return (data);
}

char	*ft_get_after_newline(char *readline)
{
	int		i;
	int		j;
	char	*data;

	i = 0;
	while (readline[i] && readline[i] != '\n')
		i++;
	if (!readline[i])
	{
		free(readline);
		return (NULL);
	}
	data = (char *)malloc(sizeof(char) * (ft_strlen(readline) - i + 1));
	if (!data)
		return (NULL);
	i++;
	j = 0;
	while (readline[i])
		data[j++] = readline[i++];
	data[j] = '\0';
	free(readline);
	return (data);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*readline[5000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	readline[fd] = ft_get_read_line(fd, readline[fd]);
	if (!readline[fd])
		return (0);
	line = ft_get_before_newline(readline[fd]);
	readline[fd] = ft_get_after_newline(readline[fd]);
	return (line);
}
