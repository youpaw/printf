/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_handlers.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 19:24:18 by dbutterw          #+#    #+#             */
/*   Updated: 2019/10/03 21:29:10 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HANDLERS_H
# define FT_HANDLERS_H
# include "ft_printf.h"
# define N_TYPES 9

typedef struct					s_handlers
{
	char						type;
	ssize_t						(*handler)(t_params*, va_list);
}								t_handlers;

ssize_t							ft_handle_int(t_params *params, va_list args);

ssize_t							ft_handle_oct(t_params *params, va_list args);

ssize_t							ft_handle_uns(t_params *params, va_list args);

ssize_t							ft_handle_hex(t_params *params, va_list args);

ssize_t							ft_handle_chr(t_params *params, va_list args);

ssize_t							ft_handle_str(t_params *params, va_list args);

ssize_t							ft_handle_ptr(t_params *params, va_list args);

ssize_t							ft_handle_nul(t_params *params);

static const t_handlers			handlers[N_TYPES] =
{
		{'d', &ft_handle_int},
		{'i', &ft_handle_int},
		{'o', &ft_handle_oct},
		{'u', &ft_handle_uns},
		{'x', &ft_handle_hex},
		{'X', &ft_handle_hex},
		{'c', &ft_handle_chr},
		{'s', &ft_handle_str},
		{'p', &ft_handle_ptr}
};

#endif
