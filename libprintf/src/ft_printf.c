/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:31:54 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/21 20:37:42 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *fmt_str, ...)
{
	va_list	ap;
	t_mess	*mess;

	if (!fmt_str)
	{
		ft_putendl_fd("ft_printf: must input valid format string", 2);
		exit(1);
	}
	if (!(mess = (t_mess *)malloc(sizeof(t_mess))))
		ft_exit_malloc_error("ft_printf", sizeof(t_mess));
	ft_bzero(mess, sizeof(t_mess));
	mess->fmt_str = fmt_str;
	va_start(ap, fmt_str);
	parse_fmt(mess, ap);
	va_end(ap);
	return (mess->pfint);
}
