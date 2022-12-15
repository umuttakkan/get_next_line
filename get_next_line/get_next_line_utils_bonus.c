/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uakkan <uakkan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:12:11 by uakkan            #+#    #+#             */
/*   Updated: 2022/12/05 15:38:00 by uakkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (!c)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *readline, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!readline)
	{
		readline = (char *)malloc(sizeof(char) * 1);
		readline[0] = '\0';
	}
	if (!readline || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(readline) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (readline)
		while (readline[++i] != '\0')
			str[i] = readline[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[i] = '\0';
	free(readline);
	return (str);
}
