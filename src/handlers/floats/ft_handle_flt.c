#include "ft_printf.h"
#include "PrintDouble.h"

ssize_t		ft_handle_flt(t_params *params, va_list args)
{
	char *res;

	res = \
	printDouble(ft_util_size(args, params->size), params->width, params->rigor);
	return (ft_util_print(&res));
}