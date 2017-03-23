/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:38:11 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/22 17:40:52 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	free_structs(t_mess *mess, t_mods *mods)
{
	if (mods)
		ft_freezero(mods, sizeof(t_mods));
	if (mess)
	{
		if (mess->fmt_str)
			ft_freezero((void *)mess->fmt_str, ft_strlen(mess->fmt_str));
		ft_freezero(mess, sizeof(t_mess));
	}
}
