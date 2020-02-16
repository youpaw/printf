#include "ft_printf.h"
#include "PrintDouble.h"

ssize_t		ft_handle_flt(t_params *params, va_list args)
{
	char *res;

	res = printDouble(va_arg(args, long double), \
	params->width < 0 ? 0 : params->width, \
	params->rigor < 0 ? 6 : params->rigor);
	return (ft_util_print(&res));
}
