/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 18:04:28 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/22 21:16:37 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void override_flags(t_mods *mods)
{
	if (mods->flags.plus)
		mods->flags.space = 0;
	if (mods->flags.minus || mods->dot)
		mods->flags.zero = 0;
	if (mods->spec >= POINTER)
		mods->length = 0;
}

static void	convert_mess(t_mess *mess, va_list ap)
{
	t_mods	*mods;

	if (!(mods = (t_mods *)malloc(sizeof(t_mods))))
		ft_exit_malloc_error("ft_printf", sizeof(t_mods));
	ft_bzero(mods, sizeof(t_mods));
	parse_mods(mess, mods);
	validate_mods(mods);
	if (!mods->error)
	{
		override_flags(mods);
		print_mods(mess, mods, ap);
	}
	ft_freezero(mods, sizeof(t_mods));
}

void		parse_fmt(t_mess *mess, va_list ap)
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
