/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:31:54 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/17 18:06:22 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
//#include <stdio.h>

int	check_mod(char const *fmt_str)
{
	char	*mod;
	int		i;

	mod = MODS;
	i = 0;
	while (mod[i])
	{
		if (!ft_strncmp(fmt_str, mod + i, 2))
			return (2);
		else if (!ft_strncmp(fmt_str, mod + i, 1))
			return (1);
		++i;
	}
	return (0);	
}

int	ft_printf(int fd, const char *fmt_str, ...)
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
/*	while ((place = char_at_x(mess)))
	{
		if (place != '%')
		{
			mess->pfint += ft_putlchar(place);
			++mess->x;
		}
		else
		{
			ft_bzero(&mods, sizeof(mods));
			++fmt_str;
			fmt_str += check_flag(fmt_str);
			fmt_str += check_fw(fmt_str);
			fmt_str += check_prec(fmt_str);
			fmt_str += check_mod(fmt_str);
			if (!check_spec(fmt_str))
				err_spec();
			else{
			if (*fmt_str == 'd' || *fmt_str == 'i')
				ftpf += ft_putlstr(ft_lltoa_base((int)va_arg(ap, int), 10));
			else if (*fmt_str == 'D')
				ftpf += ft_putlstr(ft_lltoa_base((long)va_arg(ap, long), 10));
			else if (*fmt_str == 'u' || *fmt_str == 'U')
				ftpf += ft_putlstr(ft_lltoa_base((uintmax_t)va_arg(ap, uintmax_t), 10));
			else if (*fmt_str == 'x')
				ftpf += ft_putlstr(ft_lltoa_base(va_arg(ap, long), 16));
			else if (*fmt_str == 'p')
			{
				ftpf += ft_putlstr("0x");
				ftpf += ft_putlstr(ft_lltoa_base((long)va_arg(ap, void *), 16));
			}
			else if (*fmt_str == 'o' || *fmt_str == 'O')
				ftpf += ft_putlstr(ft_lltoa_base(va_arg(ap, long), 8));
			else if (*fmt_str == 'c')
				ftpf += ft_putlchar(va_arg(ap, int));
			else if (*fmt_str == '%')
				ftpf += ft_putlchar('%');
			else if (*fmt_str == 's')
				ftpf += ft_putlstr(va_arg(ap, char *));}
		
		}
	}*/
	va_end(ap);
	return (mess->pfint);
}
