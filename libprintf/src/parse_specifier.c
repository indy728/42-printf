/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 23:38:24 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/22 02:18:19 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		check_spec(char char_x, t_mods *mods)
{
	if (char_x == 'd' || char_x == 'i' || char_x == 'D')
		mods->spec = SIGNED;
	else if (char_x == 'u' || char_x == 'U')
		mods->spec = UNSIGNED;
	else if (char_x == 'o' || char_x == 'O')
		mods->spec = OCTAL;
	else if (char_x == 'x')
		mods->spec = HEX_LOWER;
	else if (char_x == 'X')
		mods->spec = HEX_UPPER;
	else if (char_x == 'c' || char_x == 'C')
		mods->spec = CHAR;
	else if (char_x == 's' || char_x == 'S')
		mods->spec = STRING;
	else if (char_x == 'p')
		mods->spec = POINTER;
	else if (char_x == '%')
		mods->spec = PERCENT;
	else
		mods->spec = INVALID;
	if (char_x == 'D' || char_x == 'O' || char_x == 'U'
			|| char_x == 'C' || char_x == 'S')
		mods->length = L;
}

void	parse_specifier(t_mess *mess, t_mods *mods)
{
	char	char_x;

	if (!(char_x = (char_at_x(mess, 0))))
	{
		ft_putendl_fd("ft_printf: format ends without reaching specifier", 2);
//		free_structs(mess, mods);
	}
	else
	{
		check_spec(char_x, mods);
		++mess->x;
	}
}
