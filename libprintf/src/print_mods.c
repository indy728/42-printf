/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mods.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 01:03:38 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/20 21:41:28 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_mods(t_mess *mess, t_mods *mods, va_list ap)
{
	char	*str;

	if (mods->spec == STRING)
		str = make_stringstr(mods, ap);
	else if (mods->spec == SIGNED || mods->spec == UNSIGNED)
		str = make_decimalstr(mods, ap);
	else if (mods->spec == OCTAL)
	{
		if (!(str = ft_lltoa_base(va_arg(ap, unsigned int), 8)))
			str = ft_strdup("");
	}
	else if (mods->spec == HEX_LOWER)
	{
		if (!(str = ft_lltoa_base(va_arg(ap, unsigned int), 16)))
			str = ft_strdup("");
	}
	else if (mods->spec == POINTER)
		str = make_pointerstr(mods, ap);
	else if (mods->spec == CHAR)
	{
		str = ft_strdup("");
		if (!(*str = (char)va_arg(ap, int)))
			;
	}
	mess->pfint += ft_putlstr(str);
}
