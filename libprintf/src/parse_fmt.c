/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 18:04:28 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/17 21:51:14 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	convert_mess(t_mess *mess, va_list ap)
{
	t_mods	*mods;

	if (char_at_x(mess, 0) == '%')
	{
		mess->pfint += ft_putlchar('%');
		++mess->x;
	}
	else
	{
		if (!(mods = (t_mods *)malloc(sizeof(t_mods))))
			ft_exit_malloc_error("ft_printf", sizeof(t_mods));
		ft_bzero(mods, sizeof(t_mods));
		parse_mods(mess, mods);
		print_mods(mess, mods, ap);
		ft_memdel((void **)&mods);
	}	
}

void	parse_fmt(t_mess *mess, va_list ap)
{
	char	char_x;

	while ((char_x = char_at_x(mess, 0)))
	{
		if (char_x != '%')
		{
			mess->pfint += ft_putlchar(char_x);
			++mess->x;
		}
		else
		{
			++mess->x;
			convert_mess(mess, ap);
		}
	}
}
