/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 22:42:46 by apaege            #+#    #+#             */
/*   Updated: 2022/04/03 18:53:05 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_b.h"

static void	ft_check_pos(char **map, t_int el, int *ok)
{
	if (map[el.h][el.w] == '9')
		*ok = ft_verif_map(map, el);
	else if (map[el.h][el.w] == ' ' || map[el.h][el.w] == '\0')
		*ok = 0;
}

int	ft_verif_map(char **map, t_int el)
{
	int	ok1;
	int	ok2;
	int	ok3;
	int	ok4;

	ok1 = 1;
	ok2 = 1;
	ok3 = 1;
	ok4 = 1;
	map[el.h][el.w] = '0';
	el.h = el.h - 1;
	ft_check_pos(map, el, &ok1);
	el.h = el.h + 1;
	el.w = el.w - 1;
	ft_check_pos(map, el, &ok2);
	el.h = el.h + 1;
	el.w = el.w + 1;
	ft_check_pos(map, el, &ok3);
	el.h = el.h - 1;
	el.w = el.w + 1;
	ft_check_pos(map, el, &ok4);
	return (ok1 && ok2 && ok3 && ok4);
}

static void	ft_check_border(char **map, t_int size)
{
	t_int	el;
	int		tmp_w;

	el.h = 0;
	tmp_w = 0;
	while (el.h < size.h)
	{
		tmp_w = ft_strlen(map[el.h]);
		el.w = 0;
		while (map[el.h][el.w])
		{
			if (!el.h || !el.w || el.h == size.h - 1 || el.w == tmp_w - 1)
				if (ft_in_charset(map[el.h][el.w], "23469NSWE"))
					ft_print_error("Map not closed", PARSE_ERROR);
			el.w++;
		}
		el.h++;
	}
}

static void	ft_parse_door(char **map, t_int el)
{
	int	num;

	num = 0;
	if (map[el.h - 1][el.w] == ' ' || map[el.h - 1][el.w] == '\0'
		|| map[el.h][el.w - 1] == ' ' || map[el.h][el.w - 1] == '\0'
		|| map[el.h + 1][el.w] == ' ' || map[el.h + 1][el.w] == '\0'
		|| map[el.h][el.w + 1] == ' ' || map[el.h][el.w + 1] == '\0')
		ft_print_error("Map not closed", PARSE_ERROR);
	if (map[el.h - 1][el.w] == '0')
		num++;
	if (map[el.h][el.w - 1] == '0')
		num++;
	if (map[el.h + 1][el.w] == '0')
		num++;
	if (map[el.h][el.w + 1] == '0')
		num++;
	if (num > 2)
		ft_print_error("Door inside the map", PARSE_ERROR);
}

void	ft_check_map(char **map, t_int size)
{
	t_int	el;
	int		tmp_w;

	ft_check_border(map, size);
	el.h = 1;
	tmp_w = 0;
	while (el.h < size.h - 1)
	{
		tmp_w = ft_strlen(map[el.h]);
		el.w = 1;
		while (el.w < tmp_w - 1)
		{
			if (map[el.h][el.w] == '6')
				ft_parse_door(map, el);
			if (map[el.h][el.w] == '9')
				if (!ft_verif_map(map, el))
					ft_print_error("Map not closed", PARSE_ERROR);
			el.w++;
		}
		el.h++;
	}
}
