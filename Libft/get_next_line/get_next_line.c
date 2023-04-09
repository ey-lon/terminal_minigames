/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 08:58:18 by abettini          #+#    #+#             */
/*   Updated: 2022/11/07 15:43:30 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static char	*ft_join_free(char *buf, char *buf_temp)
{
	char	*buf_update;

	buf_update = ft_strjoin(buf, buf_temp);
	free(buf);
	return (buf_update);
}

static char	*ft_getdata(char *buf, int fd)
{
	int		i;
	char	*buf_temp;

	if (!buf)
		buf = ft_calloc(1, 1);
	buf_temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	i = 1;
	while (i > 0)
	{
		if (ft_strchr(buf, '\n') != 0)
			break ;
		i = read(fd, buf_temp, BUFFER_SIZE);
		if (i < 0)
		{
			free(buf_temp);
			return (NULL);
		}
		buf_temp[i] = '\0';
		buf = ft_join_free(buf, buf_temp);
	}
	free(buf_temp);
	return (buf);
}

static char	*ft_getline(char *buf)
{
	int		i;
	char	*line;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (buf[i] == '\n')
		i++;
	line = ft_calloc((i + 1), sizeof(char));
	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
		line[i] = '\n';
	return (line);
}

static char	*ft_rmline(char *buf_old)
{
	int		i;
	int		j;
	char	*buf_new;

	i = 0;
	while (buf_old[i] != '\n' && buf_old[i] != '\0')
		i++;
	if (buf_old[i] == '\n')
		i++;
	if (!buf_old[i])
	{
		free(buf_old);
		return (NULL);
	}
	buf_new = ft_calloc(ft_strlen(buf_old) - i + 1, sizeof(char));
	j = 0;
	while (buf_old[i + j] != '\0')
	{
		buf_new[j] = buf_old[i + j];
		j++;
	}
	free(buf_old);
	return (buf_new);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf[FOPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buf[fd] = ft_getdata(buf[fd], fd);
	line = ft_getline(buf[fd]);
	buf[fd] = ft_rmline(buf[fd]);
	return (line);
}
