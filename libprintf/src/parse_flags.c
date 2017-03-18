/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 20:22:20 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/17 21:59:12 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		check_flag(char char_x, t_flags *flag)
{
	if (char_x == '#')
		return (flag->hash = 1);
	else if (char_x == '0')
		return (flag->zero = 1);
	else if (char_x == '-')
		return (flag->minus = 1);
	else if (char_x == ' ')
		return (flag->space = 1);
	else if (char_x == '+')
		return (flag->plus = 1);
	else
		return (0);
}

void	parse_flags(t_mess *mess, t_mods *mods)
{
	char	char_x;

	while ((char_x = char_at_x(mess, 0) && check_flag(char_x, mods->flags)))
		++mess->x;
}
