/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stringstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:10:33 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/22 21:23:34 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

char	*make_stringstr(t_mods *mods, va_list ap)
{
	char	*str;

	if (mods->length == L){
		printf("%ls", va_arg(ap, wchar_t *));
		str = ft_strdup("doodoo");}
	else
		str = va_arg(ap, char *);
	if (!str)
		return (ft_strdup("(null)"));
	str = ft_strdup(str);
	if (mods->dot && ft_strlen(str) > mods->prec)
		ft_bzero((void *)(str + mods->prec), ft_strlen(str) - mods->prec);
	return (str);
}
