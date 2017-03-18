/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mods.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 01:03:38 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/15 13:59:57 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_mods(t_mess *mess, t_mods *mods, va_list ap)
{
	char	*str;

	if (mods->spec == STRING)
	{	
		if (!(str = va_arg(ap, char *)))
			str = ft_strdup("(null)");
	}
	else if (mods->spec == SIGNED)
	{	
		if (!(str = ft_lltoa_base(va_arg(ap, int), 10)))
			str = ft_strdup("");
	}
	else if (mods->spec == UNSIGNED)
	{	
		if (!(str = ft_lltoa_base(va_arg(ap, unsigned int), 10)))
			str = ft_strdup("");
	}
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
	{	
		if (!(str = ft_strjoin("0x", ft_lltoa_base(va_arg(ap, long), 16))))
			str = ft_strdup("0x0");
		//realloc somewhere
	}
	else if (mods->spec == CHAR)
	{	
		str = ft_strdup("");
		if (!(*str = (char)va_arg(ap, int)))
			;
	}
	mess->pfint += ft_putlstr(str);
}
