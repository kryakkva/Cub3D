/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:50:27 by apaege            #+#    #+#             */
/*   Updated: 2022/03/20 19:08:42 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	ft_key_push(keycode, &scene->move);
	if (keycode == ESC)
		ft_close(scene);
	ft_move(scene);
	return (0);
}

int	ft_refresh(t_scene *scene)
{
	ft_draw_image(scene);
	mlx_clear_window(scene->mlx, scene->win);
	mlx_put_image_to_window(scene->mlx, scene->win, scene->img->img_ptr, 0, 0);
	return (0);
}
