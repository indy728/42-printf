/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 21:04:11 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/10 23:37:22 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	parse_precision(t_mess *mess, t_mods *mods)
{
	if (char_at_x(mess) == '.')
	{
		++mess->x;
		mods->prec = ft_atoi(mess->fmt_str + mess->x);
		while (ft_isdigit(char_at_x(mess)))
			++mess->x;	
	}
}
