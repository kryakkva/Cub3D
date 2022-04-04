/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:26:59 by apaege            #+#    #+#             */
/*   Updated: 2022/03/23 20:30:50 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_b.h"

static void	ft_write_data(int fd, t_scene *scn)
{
	int	line;

	line = scn->res.h;
	while (--line + 1)
		write(fd, scn->img->data + scn->res.w * line * 4, scn->res.w * 4);
}

static char	*ft_info_header(t_int res)
{
	char	*infoheader;

	infoheader = ft_calloc(sizeof(char), 40);
	ft_memcpy(infoheader, (char []){40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, \
			32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
			0, 0, 0, 0}, 40);
	infoheader[4] = (char)res.w;
	infoheader[5] = res.w >> 8;
	infoheader[6] = res.w >> 16;
	infoheader[7] = res.w >> 24;
	infoheader[8] = (char)res.h;
	infoheader[9] = res.h >> 8;
	infoheader[10] = res.h >> 16;
	infoheader[11] = res.h >> 24;
	return (infoheader);
}

static char	*ft_file_header(int filesize)
{
	char	*fileheader;

	fileheader = ft_calloc(sizeof(char), 14);
	ft_memcpy(fileheader, (char []){'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, \
			54, 0, 0, 0}, 14);
	fileheader[2] = filesize;
	fileheader[3] = filesize >> 8;
	fileheader[4] = filesize >> 16;
	fileheader[5] = filesize >> 24;
	return (fileheader);
}

void	ft_screenshot(char *filename, t_scene *scene)
{
	int		fd;
	int		filesize;
	char	*fileheader;
	char	*infoheader;

	filesize = 14 + 40 + 3 * scene->res.w * scene->res.h;
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0755);
	fileheader = ft_file_header(filesize);
	write(fd, fileheader, 14);
	free(fileheader);
	infoheader = ft_info_header(scene->res);
	write(fd, infoheader, 40);
	free(infoheader);
	ft_write_data(fd, scene);
	close(fd);
}

char	*ft_scrshrt_datetime(char *res)
{
	time_t		t;
	struct tm	tm;
	char		*tmp;

	t = time(NULL);
	tm = *localtime(&t);
	ft_memcpy(res, "Screenshot YYYY-MM-DD hh-mm-ss.bmp", 35);
	ft_memcpy(res + 11, (tmp = ft_itoa_width(tm.tm_year + 1900, 4)), 4);
	free(tmp);
	ft_memcpy(res + 16, (tmp = ft_itoa_width(tm.tm_mon + 1, 2)), 2);
	free(tmp);
	ft_memcpy(res + 19, (tmp = ft_itoa_width(tm.tm_mday, 2)), 2);
	free(tmp);
	ft_memcpy(res + 22, (tmp = ft_itoa_width(tm.tm_hour, 2)), 2);
	free(tmp);
	ft_memcpy(res + 25, (tmp = ft_itoa_width(tm.tm_min, 2)), 2);
	free(tmp);
	ft_memcpy(res + 28, (tmp = ft_itoa_width(tm.tm_sec, 2)), 2);
	free(tmp);
	return (res);
}
