/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:36:53 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/07 02:21:32 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define FLAGS "#0- +"
# define SPECS "sSpdDioOuUxXcC"
# define MODS "hhlljz"

typedef	struct		s_mods
{
	struct s_flags	*flags;
	int				fwidth;
	int				prec;
	char			spec;
}					t_mods;

typedef struct		s_flags
{
	int				hash;
	int				zero;
	int				minus;
	int				space;
	int				plus;
}					t_flags;

int	ft_printf(const char *fmt_str, ...);

#endif
