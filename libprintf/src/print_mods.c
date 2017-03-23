/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mods.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 01:03:38 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/22 18:04:56 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	print_strings(t_mess *mess, t_mods *mods, va_list ap)
{
	char	*str;

	if (mods->spec == STRING)
		str = make_stringstr(mods, ap);
	else if (mods->spec == SIGNED || mods->spec == UNSIGNED)
		str = make_decimalstr(mods, ap);
	else if (mods->spec == OCTAL)
		str = make_octalstr(mods, ap);
	else if (mods->spec == HEX_LOWER || mods->spec == HEX_UPPER)
		str = make_hexstr(mods, ap);
	else if (mods->spec == POINTER)
		str = make_pointerstr(mods, ap);
	add_padding(mods, &str);
	mess->pfint += ft_putlstr(str);
	ft_freezero(str, ft_strlen(str));
}

static void	print_char(t_mess *mess, t_mods *mods, char c)
{
	char	*str;

	str = ft_strnew(1);
	*str = c;
	if (c == '\0' && mods->fwidth)
		--mods->fwidth;
	add_padding(mods, &str);
	if (!c)
	{
		if (mods->flags.minus)
			mess->pfint += ft_putlchar(c) + ft_putlstr(str);
		else
			mess->pfint += ft_putlstr(str) + ft_putlchar(c);
	}
	else
		mess->pfint += ft_putlstr(str);
	ft_freezero(str, ft_strlen(str));
}

void		print_mods(t_mess *mess, t_mods *mods, va_list ap)
{
	if (mods->spec == CHAR)
	{
		/*if (mods->length > H)
			print_wide_char(mess, mods, ap);
		else*/
			print_char(mess, mods, (char)va_arg(ap, int));
	}
	else if (mods->spec == PERCENT)
		print_char(mess, mods, '%');
	else
		print_strings(mess, mods, ap);
}
