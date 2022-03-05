/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:44:57 by yait-iaz          #+#    #+#             */
/*   Updated: 2022/03/05 20:38:11 by yait-iaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

char	*get_new_line(char *buffer)
{
	size_t		i;
	char		*str;

	i = 0;
	if (buffer[i] == 0)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	str = ft_strdupi(buffer, i);
	return (str);
}

char	*get_rest(char *buffer)
{
	int		rest_len;
	char	*rest;
	char	*start;

	start = ft_strchr(buffer, '\n');
	rest_len = ft_strlen(start + 1);
	rest = ft_strdupi(start + 1, rest_len);
	return (rest);
}

char	*get_buffer(char *buffer, int fd, char *rest, int nbyte)
{
	char	*temp;

	if (nbyte > 0)
	{
		while (ft_strchr(buffer, '\n') == 0)
		{
			temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
			if (!temp)
				return (0);
			nbyte = read(fd, temp, BUFFER_SIZE);
			if (nbyte <= 0)
			{
				free(temp);
				break ;
			}
			temp[nbyte] = '\0';
			buffer = ft_strjoin(buffer, temp);
			free(temp);
		}
	}
	if (rest != NULL)
		buffer = get_new_buffer(rest, buffer);
	return (buffer);
}

char	*get_new_buffer(char *rest, char *buffer)
{
	char	*new_buffer;

	new_buffer = ft_strjoin(rest, buffer);
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*rest;
	int			nbyte;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	nbyte = read(fd, buffer, BUFFER_SIZE);
	if (nbyte < 0 || (!rest && nbyte == 0))
	{
		free(buffer);
		return (NULL);
	}
	buffer[nbyte] = '\0';
	buffer = get_buffer(buffer, fd, rest, nbyte);
	rest = NULL;
	str = get_new_line(buffer);
	if (ft_strlen(buffer) > ft_strlen(str))
		rest = get_rest(buffer);
	free(buffer);
	return (str);
}