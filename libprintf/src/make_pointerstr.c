/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pointerstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:23:21 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/20 21:36:51 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*make_pointerstr(t_mods *mods, va_list ap)
{
	long	pointer;
	char	*str;

	pointer = (long)va_arg(ap, void *);
	if (!pointer)
		return (ft_strdup("0x0"));
	str = ft_lltoa_base(pointer, 16);
	str = ft_strmove(ft_strjoin("0x", str), &str);
	(void)mods;
//	(void)ap; I don't know what these are supposed to do.
	return (str);
}
