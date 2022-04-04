/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:50:27 by apaege            #+#    #+#             */
/*   Updated: 2022/04/03 19:08:24 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_b.h"

int	ft_key_release(int keycode, t_move *move)
{
	if (keycode == ARROW_UP || keycode == KEY_W)
		move->up = FALSE;
	else if (keycode == ARROW_DOWN || keycode == KEY_S)
		move->down = FALSE;
	else if (keycode == ARROW_LEFT || keycode == KEY_Q)
		move->turn_left = FALSE;
	else if (keycode == ARROW_RIGHT || keycode == KEY_E)
		move->turn_right = FALSE;
	else if (keycode == KEY_A)
		move->left = FALSE;
	else if (keycode == KEY_D)
		move->right = FALSE;
	else if (keycode == ENTER)
		move->enter = FALSE;
	else if (keycode == SPACE)
		move->space = FALSE;
	return (0);
}

int	ft_key_push(int keycode, t_move *move)
{
	if (keycode == ARROW_UP || keycode == KEY_W)
		move->up = TRUE;
	else if (keycode == ARROW_DOWN || keycode == KEY_S)
		move->down = TRUE;
	else if (keycode == ARROW_LEFT || keycode == KEY_Q)
		move->turn_left = TRUE;
	else if (keycode == ARROW_RIGHT || keycode == KEY_E)
		move->turn_right = TRUE;
	else if (keycode == KEY_A)
		move->left = TRUE;
	else if (keycode == KEY_D)
		move->right = TRUE;
	else if (keycode == ENTER)
		move->enter = TRUE;
	else if (keycode == SPACE)
		move->space = TRUE;
	return (0);
}

void	ft_move(t_scene	*scene)
{
	if (scene->move.up)
		ft_move_up(scene);
	if (scene->move.down)
		ft_move_down(scene);
	if (scene->move.left)
		ft_move_left(scene);
	if (scene->move.right)
		ft_move_right(scene);
	if (scene->move.turn_left)
		ft_turn_left(scene);
	if (scene->move.turn_right)
		ft_turn_right(scene);
}

int	ft_key_hook(int keycode, t_scene *scene)
{
	char	filename[MAXFILENAME];

	ft_key_push(keycode, &scene->move);
	if (keycode == ESC)
		ft_close(scene);
	if (keycode == KEY_F5)
		ft_screenshot(ft_scrshrt_datetime(filename), scene);
	ft_move(scene);
	ft_check_door(scene);
	return (0);
}
