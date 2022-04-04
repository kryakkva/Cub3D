/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:16:52 by apaege            #+#    #+#             */
/*   Updated: 2022/04/03 20:00:14 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_b.h"

int	ft_mouse_press(int keycode, int x, int y, void *param)
{
	t_scene	*scene;

	(void)x;
	(void)y;
	scene = (t_scene *)param;
	if (keycode == MOUSE_SCROLL_UP)
		ft_move_up(scene);
	else if (keycode == MOUSE_SCROLL_DOWN)
		ft_move_down(scene);
	else if (keycode == MOUSE_LEFT_BUTTON)
		scene->mouse->lkm_is_pressed = 1;
	else if (keycode == MOUSE_RIGHT_BUTTON)
		scene->mouse->rkm_is_pressed = 1;
	return (0);
}

int	ft_mouse_release(int keycode, int x, int y, void *param)
{
	t_scene	*scene;

	(void)x;
	(void)y;
	(void)keycode;
	scene = (t_scene *)param;
	scene->mouse->lkm_is_pressed = 0;
	scene->mouse->rkm_is_pressed = 0;
	return (0);
}

int	ft_mouse_hook(int x, int y, void *param)
{
	t_scene	*scene;

	scene = (t_scene *)param;
	scene->mouse->previous_x = scene->mouse->x;
	scene->mouse->previous_y = scene->mouse->y;
	scene->mouse->x = x;
	scene->mouse->y = y;
	if (scene->mouse->rkm_is_pressed == 1 || scene->mouse->lkm_is_pressed == 1)
	{
		if (x > scene->mouse->previous_x)
			ft_turn_right(scene);
		else if (x < scene->mouse->previous_x)
			ft_turn_left(scene);
	}
	return (0);
}
