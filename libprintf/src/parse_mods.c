/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mods.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 19:35:43 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/11 01:03:29 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	parse_mods(t_mess *mess, t_mods *mods)
{
	parse_flags(mess, mods);
	parse_fw(mess, mods);
	parse_precision(mess, mods);
//	parse_length(mess, mods);
	parse_specifier(mess, mods);
}
