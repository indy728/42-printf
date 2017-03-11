/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mods.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 19:35:43 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/10 21:18:42 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	parse_mods(t_mess *mess, t_mods *mods, va_list ap)
{
	parse_flags(mess, mods);
	parse_fw(mess, mods);
	parse_precision(mess, mods);
	if (ap)
		;
	return (1);
}
