#include "ft_printf.h"

int		convertor_1(va_list args, char spec, t_struct *params)
{
	if (spec == 'c' || spec == 'C')
		its_char(args, params);
	else if (spec == 's' || spec == 'S')
		its_str(args, params);
	else if (spec == 'p' || spec == 'P')
		its_ptr(args, params);
	else if (spec == 'd' || spec == 'i' || spec == 'D' || spec == 'I')
		its_int(args, params);
	else if (spec == 'u' || spec == 'U')
		its_uint(args, params, spec);
	else if (spec == 'x' || spec == 'X')
		its_hex(args, params, spec);
	else if (spec == 'f' || spec == 'F')
		its_float(args, params);
	else if (spec == 'o' || spec == 'O')
		its_oct(args, params);
	return (convertor_2(args, spec, params));
}

int		convertor_2(va_list args, char spec, t_struct *params)
{
	if (spec == '%')
		percenter(params);
	else if (spec == 'r')
		nonprint_creator(args, params);
	else if (spec == 'b')
		its_binary(args, params);
	else
		struct_bzeroer(params, 0);
	return (params->i);
}
