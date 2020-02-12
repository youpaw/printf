#include "ft_printf.h"
#include "PrintDouble.h"

ssize_t		ft_handle_flt(t_params *params, va_list args)
{
	char *res;

	res = printDouble(va_arg(args, double), params->width, params->rigor);
	return (ft_util_print(&res));
}