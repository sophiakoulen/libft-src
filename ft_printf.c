#include "libft.h"

#define ZERO_PAD 1
#define MODIF_LONG 1

static void	ft_printf_get_value(va_list ap, t_spec s, t_value *val);
static int	ft_printf_length_value(t_value val, t_spec s);
static void	ft_printf_print_value(t_value val, t_spec s, int fd);

int parse_flags(const char* format, int *flags)
{
	int i = 0;
	*flags = 0;
	while (ft_strchr("#0- +'", format[i]) != NULL)
	{
		if (format[i] == '0')
			*flags |= ZERO_PAD;
		i++;
	}
	return i;	
}

int parse_width(const char* format, int* width)
{
	int i = 0;
	*width = 0;
	*width = atoi(format);
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	return i;
}

int parse_modifier(const char* format, int* modifier)
{
	int i = 0;
	*modifier = 0;
	if (format[i] == 'l')
	{
		*modifier = MODIF_LONG;
		i++;
	}
	return i;
}

int parse_conversion(const char* format, char* conversion)
{
	int i = 0;
	*conversion = 0;
	if (ft_strchr("cipsxXu", format[i]))
	{
		*conversion = format[i];
		i++;
	}
	return i;
}

//returns number of characters read, or -1
int parse_specifier(const char* format, t_spec *specifier)
{
	int i = 0;
	i += parse_flags(format, &(specifier->flags));
	i += parse_width(format + i, &(specifier->width));
	i += parse_modifier(format + i, &(specifier->modifier));
	i += parse_conversion(format + i, &(specifier->conversion));
	return i;
}

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	int		ret;
	t_value	val;
	t_spec	specifier;

	ret = 0;
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar_fd(*format, fd);
			ret++;
			format++;
		}
		else
		{
			format++;
			
			format += parse_specifier(format, &specifier);

			ft_printf_get_value(ap, specifier, &val);
			ft_printf_print_value(val, specifier, fd);
			ret += ft_printf_length_value(val, specifier);
			format += ret;
		}
	}
	return (ret);
}

int	ft_vprintf(const char *format, va_list ap)
{
	int	ret;

	ret = ft_vdprintf(1, format, ap);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int		ret;
	va_list	ap;

	va_start(ap, format);
	ret = ft_vprintf(format, ap);
	va_end(ap);
	return (ret);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	int		ret;
	va_list	ap;

	va_start(ap, format);
	ret = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (ret);
}

void	ft_printf_get_value(va_list ap, t_spec s, t_value *val)
{
	if ((s.conversion == 'i' || s.conversion == 'd' || s.conversion == 'c') && !s.modifier)
		val->i = va_arg(ap, int);
	else if ((s.conversion == 'i' || s.conversion == 'd') && s.modifier == MODIF_LONG)
		val->li = va_arg(ap, long int);
	else if ((s.conversion == 'u' || s.conversion == 'x' || s.conversion == 'X') && !s.modifier)
		val->u = va_arg(ap, unsigned int);
	else if ((s.conversion == 'u' || s.conversion == 'x' || s.conversion == 'X') && s.modifier == MODIF_LONG)
		val->lu = va_arg(ap, unsigned long int);
	else if (s.conversion == 's')
		val->s = va_arg(ap, char *);
	else if (s.conversion == 'p')
		val->p = va_arg(ap, void *);
}

int	ft_printf_length_value(t_value val, t_spec s)
{
	int	res = 0;

	if (s.conversion == 'i' || s.conversion == 'd')
		res = ft_nbr_len(val.i, 10);
	else if (s.conversion == 'u')
		res = ft_nbr_len_unsigned(val.u, 10);
	else if (s.conversion == 'x' || s.conversion == 'X')
		res = ft_nbr_len_unsigned(val.u, 16);
	else if (s.conversion == 'c' || s.conversion == '%')
		res = 1;
	else if (s.conversion == 's')
	{
		if (val.s)
			res = ft_strlen(val.s);
		else
			res = ft_strlen("(null)");
	}
	else if (s.conversion == 'p')
		res = 2 + ft_nbr_len_unsigned((size_t)val.p, 16);
	return (res);
}

void	ft_printf_print_value(t_value val, t_spec s, int fd)
{
	if (s.conversion == 'i' || s.conversion == 'd')
		ft_putnbr_fd(val.i, fd);
	else if (s.conversion == 'u')
		ft_putnbr_base_unsigned_fd(val.u, DECIMAL, fd);
	else if (s.conversion == 'x')
		ft_putnbr_base_unsigned_fd(val.u, HEX_LOWER, fd);
	else if (s.conversion == 'X')
		ft_putnbr_base_unsigned_fd(val.u, HEX_UPPER, fd);
	else if (s.conversion == 'c')
		ft_putchar_fd((unsigned char)val.i, fd);
	else if (s.conversion == 's')
	{
		if (val.s)
			ft_putstr_fd(val.s, fd);
		else
			ft_putstr_fd("(null)", fd);
	}
	else if (s.conversion == 'p')
	{
		ft_putstr_fd("0x", fd);
		ft_putnbr_base_unsigned_fd((size_t)val.p, HEX_LOWER, fd);
	}
	else if (s.conversion == '%')
		ft_putchar_fd('%', fd);
}
