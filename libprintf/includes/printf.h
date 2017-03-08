/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:36:53 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/08 14:40:55 by kmurray          ###   ########.fr       */
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

typedef	struct		s_mods
{
	t_flags			*flags;
	unsigned int	fwidth;
	unsigned int	prec;
	char			spec;
}					t_mods;

int	ft_printf(const char *fmt_str, ...);

#endif
