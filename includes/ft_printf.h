/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 15:12:17 by dbutterw          #+#    #+#             */
/*   Updated: 2019/10/03 21:29:10 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include "../libft/libft.h"
# define N_FLAGS 5
# define FLAGS "-+ #0"

typedef struct	s_params
{
	short		flags[N_FLAGS];
	int 		width;
	int			rigor;
	char 		size;
	char 		type;

}				t_params;

int				ft_printf(char *format, ...);

t_params		*ft_get_params(char **format, va_list args);

ssize_t			ft_util_handle(char **format, va_list args);

ssize_t			ft_util_size(va_list args, char size);

uintmax_t		ft_util_usize(va_list args, char size);

void			ft_util_rigor(char **res, t_params *params, int pad);

void			ft_util_width(char **res, int width, short align);

void 			ft_util_sign(char **res, const short *flags);

void			ft_util_hexpref(char **res, char type);

ssize_t			ft_util_print(char **res);

#endif
