/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 15:12:17 by dbutterw          #+#    #+#             */
/*   Updated: 2020/02/21 17:40:45 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <monetary.h>
# define N_FLAGS 5
# define FLAGS "-+ #0"
# define N_TYPES 10

typedef struct	s_params
{
	short		flags[N_FLAGS];
	int			width;
	int			rigor;
	char		size;
	char		type;
}				t_params;

typedef struct	s_handlers
{
	char		type;
	int			(*handler)(t_params*, va_list);
}				t_handlers;

int				ft_printf(const char *format, ...);
void			ft_get_params(const char **format, t_params *params, va_list args);

ssize_t			ft_util_size(va_list args, char size);
size_t			ft_util_usize(va_list args, char size);

void			ft_util_rigor(char **res, t_params *params, int pad);
void			ft_util_width(char **res, int width, short align);
void			ft_util_sign(char **res, const short *flags);
void			ft_util_hexpref(char **res, char type);
int				ft_util_print(char **res);

int				ft_handle_int(t_params *params, va_list args);
int				ft_handle_oct(t_params *params, va_list args);
int				ft_handle_uns(t_params *params, va_list args);
int				ft_handle_hex(t_params *params, va_list args);
int				ft_handle_chr(t_params *params, va_list args);
int				ft_handle_str(t_params *params, va_list args);
int				ft_handle_ptr(t_params *params, va_list args);
int				ft_handle_flt(t_params *params, va_list args);
int				ft_handle_nul(t_params *params);

#endif
