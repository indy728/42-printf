/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_mods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 00:38:34 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/21 20:36:54 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	pointer_percent_length_error(t_mess *mess, t_mods *mods)
{
	if (mods->spec >= POINTER && mods->length != DEFAULT)
	{
		ft_putchar_fd(char_at_x(mess, -1), 2);
		return (1);
	}
	return (0);
}

static int	precision_error(t_mess *mess, t_mods *mods)
{
	if (mods->dot && ((mods->spec == CHAR && mods->length > H)
				|| mods->spec == POINTER))
	{
		ft_putchar_fd(char_at_x(mess, -1), 2);
		return (1);
	}
	return (0);
}

int			validate_mods(t_mess *mess, t_mods *mods)
{
	if (pointer_percent_length_error(mess, mods)
			|| precision_error(mess, mods)
			|| !validate_flags(mess, mods))
		return (0);
	return (1);
}
