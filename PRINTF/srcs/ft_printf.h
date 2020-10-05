#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include "../libft/libft.h"

# define ALL_SYM		"cCsSpPdDiIoOuUxXfFrhlLjz0123456789 .-+#%rb"
# define TYPE_SYM		"cCsSpPdDiIoOuUxXfF%rb"
# define FLAGS			" .-+#0hlLjz6"
# define SHORT			1
# define SHORTSHORT		2
# define LONG			3
# define LONGLONG		4
# define LONGDOUBLE		7
# define SIZET			8
# define _UINT_MAX		9

typedef struct	s_struct
{
	char		*fmt;
	int			n_printed;
	int			n_printed_here;
	int			i;
	int			negative;
	int			minus;
	int			plus;
	int			space;
	int			zero;
	int			zero_arg;
	int			hash;
	int			hash_case;
	int			hash_case_zero;
	int			small_hex;
	int			dot;
	int			width;
	int			prec;
	int			prec_was;
	int			prec_zero;
	int			indent;
	int			len;
	int			after_perc;
	char		*f_before;
	char		*f_after;
	int			len_before;
	int			len_after;
}				t_struct;

int				ft_printf(const char *fmt, ...);
int				format_parser(va_list args, const char *fmt, \
				t_struct *params);
int				usual_parser(va_list args, t_struct *params, const char *fmt);
int				after_perc_parser(t_struct *params, const char *fmt);
int				convertor_1(va_list args, char spec, t_struct *params);
int				convertor_2(va_list args, char spec, t_struct *params);
int				modifiers(va_list args, const char *fmt, t_struct *params);
void			struct_bzeroer(t_struct *prms, int full);

void			length_determer(const char *fmt, t_struct *prms);
void			flag_hooker(const char *fmt, t_struct	*prms);
void			width_determer(const char *fmt, t_struct	*prms);
void			prec_determer(const char *fmt, t_struct	*prms);

void			its_int(va_list args, t_struct *prms);
void			int_from_fmt(t_struct *prms, intmax_t num, int i);
void			int_printer(t_struct *prms, char *s, int indent);
int				int_printer_2(t_struct *prms, char *s);
char			*int_with_prec(t_struct *prms, char *s, int i);
void			int_checker(t_struct *prms);
char			*int_ovrflw_check(intmax_t num, char *s);

void			its_char(va_list args, t_struct *prms);
void			char_printer(t_struct *params, char c, int indent);

void			its_str(va_list args, t_struct *params);
void			str_printer(t_struct *params, char *s);
void			str_printer_2(t_struct *params);

void			its_ptr(va_list args, t_struct *prms);
void			ptr_printer(t_struct *params, char *s);
void			ptr_printer_2(t_struct *params, char*s);
void			ptr_printer_3(t_struct *params, char*s);
void			ptr_printer_4(t_struct *params, char*s);
void			ptr_checker(t_struct *params);

void			its_uint(va_list args, t_struct *params, char spec);
void			uint_from_fmt(t_struct *params, uintmax_t num, int i);
char			*uint_with_prec(t_struct *params, char *s, int i);
void			uint_printer(t_struct *params, char *s, int indent);
int				uint_printer_2(t_struct *params, char *s);

void			its_oct(va_list args, t_struct *params);
void			oct_from_fmt(t_struct *params, uintmax_t num, int i);
char			*oct_with_prec(t_struct *params, char *s, int i);
char			*oct_hash(t_struct *params, char *s);
void			oct_hash_checker(t_struct *prms, int num);
void			oct_printer(t_struct *params, char *s, int indent);
int				oct_printer_2(t_struct *params, char *s);

void			its_hex(va_list args, t_struct *params, char spec);
void			hex_from_fmt(t_struct *prms, uintmax_t num, int i);
void			hex_from_fmt_2(t_struct *prms, char *s, int indent);
char			*hex_hash(t_struct *params, char *s);
char			*hex_with_prec(t_struct *prms, char *s, int i);
void			hex_hash_check(t_struct *prms, int num);
void			hex_printer(t_struct *params, char *s, int indent);
int				hex_printer_2(t_struct *prms, char *s);

void			its_float(va_list args, t_struct *params);
void			float_determer(long double num, t_struct *prms);
char			*int_determer(long double num, int end);
void			decimal_determer(long double num, t_struct *prms);
int				is_inf_nan(t_struct *prms, long double num);
int				is_odd(char c);
void			round_upper(long double num, t_struct *prms, int i);
void			f_incrementer(t_struct *prms);
void			float_printer(t_struct *prms);
void			float_printer_2(t_struct *params);

void			writezeros(int n);
void			writeblanks(int n);

int				num_len(intmax_t num, int base);
int				uint_num_len(uintmax_t num, int base);
int				float_num_len(long double num);
long double		ft_atof(char *str);
char			*itoa_base(t_struct *prms, intmax_t num, int base);
char			*itoa_base_uint(uintmax_t num, int base);
char			*itoa_base_to_up(uintmax_t num, int base);

long double		to_power(long long n, int i);
void			percenter(t_struct *params);

void			nonprint_creator(va_list args, t_struct *prms);
int				len_recalcer(char *s, int i);
void			str_refresher(char *s, char *s_nonpr, int i, int j);

void			its_binary(va_list args, t_struct *params);
void			binary_from_fmt(t_struct *params, uintmax_t num, int i);

#endif
