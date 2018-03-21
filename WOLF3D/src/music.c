/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdahmouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 04:57:39 by sdahmouc          #+#    #+#             */
/*   Updated: 2017/09/14 04:57:55 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void		stop_music(int keycode)
{
	if (keycode == 45)
		system("killall afplay > /dev/null 2>&1");
}

int			music_play(int keycode)
{
	stop_music(keycode);
	return (0);
}
