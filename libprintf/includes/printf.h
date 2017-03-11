/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:36:53 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/11 01:17:30 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define FLAGS "#0- +"
# define SPECS "sSpdDioOuUxXcC"
# define MODS "hhlljz"

typedef	char		t_bool;

typedef	struct		s_mess
{
	char const		*fmt_str;
	unsigned int	x;
	unsigned int	pfint;
}					t_mess;

typedef struct		s_flags
{
	t_bool			hash;
	t_bool			zero;
	t_bool			minus;
	t_bool			space;
	t_bool			plus;
}					t_flags;

typedef enum		e_spec
{
	ZILCH, SIGNED, UNSIGNED, OCTAL, HEX_LOWER, HEX_UPPER, CHAR, STRING,
	POINTER
}					t_spec;

typedef	struct		s_mods
{
	t_flags			*flags;
	unsigned int	fwidth;
	unsigned int	prec;
	t_spec			spec;
}					t_mods;

int	ft_printf(const char *fmt_str, ...);
char				char_at_x(t_mess *mess);
void				parse_fmt(t_mess *mess, va_list ap);
void				parse_mods(t_mess *mess, t_mods *mods);
void				parse_flags(t_mess *mess, t_mods *mods);
void				parse_fw(t_mess *mess, t_mods *mods);
void				parse_precision(t_mess *mess, t_mods *mods);
void				parse_specifier(t_mess *mess, t_mods *mods);
void				print_mods(t_mess *mess, t_mods *mods, va_list ap);

#endif
