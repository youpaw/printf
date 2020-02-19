#include "ft_printf.h"
#include "PrintDouble.h"

ssize_t		ft_handle_flt(t_params *params, va_list args)
{
	char *res;
	long double val;

	val = 0;
    if (params->type == 'f' && params->size == 0)
        val = va_arg(args, double);
    if (params->type == 'f' && params->size == 'L')
        val = va_arg(args, long double);

    res = printDouble(val,params->width < 0 ? 0 : params->width,
	        params->rigor < 0 ? 6 : params->rigor, params->flags[0]);
	return (ft_util_print(&res));
}
