/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:55:08 by apaege            #+#    #+#             */
/*   Updated: 2022/03/20 17:55:41 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h" 

static int	check_out(int ptr, int read_byte, char	**tail)
{
	if (ptr)
		return (1);
	else
	{
		free(*tail);
		*tail = 0;
		return (read_byte);
	}
}

static int	check_ptr(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

static int	check_tail(char *tail, char **line, int ptr)
{
	if (tail)
	{
		ptr = check_ptr(tail, '\n');
		*line = "";
		if (ptr)
		{
			tail[ptr - 1] = '\0';
			*line = ft_strjoin(*line, tail);
			ft_strlcpy(tail, &tail[ptr], ft_strlen(&tail[ptr]) + 1);
		}
		else
			*line = ft_strjoin(*line, tail);
	}
	else
		*line = ft_calloc(sizeof(char), 1);
	if (!(*line))
		return (-1);
	return (ptr);
}

static int	get_line(char **tail, char	**line, char	*buf)
{
	char	*tmp;
	char	*empty_line;
	int		ptr;

	ptr = check_ptr(buf, '\n');
	if (ptr)
	{
		buf[ptr - 1] = '\0';
		empty_line = "";
		tmp = *tail;
		*tail = ft_strjoin(empty_line, &buf[ptr]);
		free(tmp);
		if (!*tail)
			return (-1);
	}
	tmp = *line;
	*line = ft_strjoin(*line, buf);
	if (!(*line))
		return (-1);
	free(tmp);
	free(buf);
	buf = 0;
	return (ptr);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	int			ptr;
	static char	*tail;
	int			read_byte;

	if ((BUFFER_SIZE < 1) || (fd < 0) || (fd > 999) || !line)
		return (-1);
	ptr = 0;
	ptr = check_tail(tail, line, ptr);
	read_byte = 1;
	while (!ptr && (read_byte > 0))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			exit (-1);
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte == -1)
			return (-1);
		buf[read_byte] = '\0';
		ptr = get_line(&tail, line, buf);
	}
	return (check_out(ptr, read_byte, &tail));
}
