/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:30:30 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/21 20:42:30 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static t_length		data_length(char c0, char c1)
{
	if (c0 == 'h')
		return (c1 == 'h' ? HH : H);
	else if (c0 == 'l')
		return (c1 == 'l' ? LL : L);
	else if (c0 == 'j')
		return (J);
	else if (c0 == 'z')
		return (Z);
	return (DEFAULT);
}

void				parse_length(t_mess *mess, t_mods *mods)
{
	char	c0;
	char	c1;

	c0 = char_at_x(mess, 0);
	if (c0 && (c1 = char_at_x(mess, 1)))
	{
		mods->length = data_length(c0, c1);
		if (mods->length != DEFAULT)
			++mess->x;
		if (mods->length == HH || mods->length == LL)
			++mess->x;
	}
}
