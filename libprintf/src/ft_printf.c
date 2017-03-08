/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:31:54 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/08 14:41:01 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
//#include <stdio.h>

int	flag(char c)
{
	if (c == '%')
		return (1);
	return (0);
}

int	check_flag(char const *fmt_str)
{
	int		count;
	int		i;
	char	*flag;

	count = 0;
	i = 0;
	flag = FLAGS;
	while(flag[i])
	{
		if (*fmt_str == flag[i])
		{
			++count;
			i = 0;
			++fmt_str;
		}
		else
			++i;
	}
	return (count);
}

int	check_fw(char const *fmt_str)
{
	int	n;

	n = ft_atoi(fmt_str);
	if (n > 0)
		return (ft_count_base(n, 10));
	return (0);
}

int	check_prec(char const *fmt_str)
{
	int	n;

	if (*fmt_str != '.')
		return (0);
	++fmt_str;
	n = ft_atoi(fmt_str);
	if (n > 0)
		return (ft_count_base(n, 10) + 1);
	return (1);
}

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

int	check_spec(char const *fmt_str)
{
	int		count;
	int		i;
	char	*spec;

	count = 0;
	i = 0;
	spec = SPECS;
	while(spec[i])
	{
		if (*fmt_str == spec[i])
			return (1);
		else
			++i;
	}
	return (0);
}

void err_spec()
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

char	find_x(t_mess *mess)
{
	return (*(mess->fmt_str + mess->x));
}

int	ft_printf(const char *fmt_str, ...)
{
	va_list	ap;
	t_mess	mess;
	char	place;

	ft_bzero(&mess, sizeof(t_mess));
	mess.fmt_str = fmt_str;
	va_start(ap, fmt_str);
	while ((place = find_x(&mess)))
	{
		if (place != '%')
		{
			(&mess)->pfint += ft_putlchar(place);
			++(&mess)->x;
		}
		else
		{
/*			ft_bzero(&mods, sizeof(mods));
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
				ftpf += ft_putlstr(va_arg(ap, char *));}*/
		
		}
	}
	va_end(ap);
	return (mess.pfint);
}
