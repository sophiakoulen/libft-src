#include "libft.h"

static void	ft_printf_get_value(va_list ap, char specifier, t_value *val);
static int	ft_printf_length_value(t_value val, char specifier);
static void	ft_printf_print_value(t_value val, char specifier, int fd);

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	int		ret;
	t_value	val;

	ret = 0;
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar_fd(*format, fd);
			ret++;
		}
		else
		{
			format++;
			ft_printf_get_value(ap, *format, &val);
			ft_printf_print_value(val, *format, fd);
			ret += ft_printf_length_value(val, *format);
		}
		format++;
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

void	ft_printf_get_value(va_list ap, char specifier, t_value *val)
{
	if (specifier == 'i' || specifier == 'd' || specifier == 'c')
		val->i = va_arg(ap, int);
	else if (specifier == 'u' || specifier == 'x' || specifier == 'X')
		val->u = va_arg(ap, unsigned);
	else if (specifier == 's')
		val->s = va_arg(ap, char *);
	else if (specifier == 'p')
		val->p = va_arg(ap, void *);
}

int	ft_printf_length_value(t_value val, char specifier)
{
	int	res;

	if (specifier == 'i' || specifier == 'd')
		res = ft_nbr_len(val.i, 10);
	else if (specifier == 'u')
		res = ft_nbr_len_unsigned(val.u, 10);
	else if (specifier == 'x' || specifier == 'X')
		res = ft_nbr_len_unsigned(val.u, 16);
	else if (specifier == 'c' || specifier == '%')
		res = 1;
	else if (specifier == 's')
	{
		if (val.s)
			res = ft_strlen(val.s);
		else
			res = ft_strlen("(null)");
	}
	else if (specifier == 'p')
		res = 2 + ft_nbr_len_unsigned((size_t)val.p, 16);
	else
		res = 0;
	return (res);
}

void	ft_printf_print_value(t_value val, char specifier, int fd)
{
	if (specifier == 'i' || specifier == 'd')
		ft_putnbr_fd(val.i, fd);
	else if (specifier == 'u')
		ft_putnbr_base_unsigned_fd(val.u, DECIMAL, fd);
	else if (specifier == 'x')
		ft_putnbr_base_unsigned_fd(val.u, HEX_LOWER, fd);
	else if (specifier == 'X')
		ft_putnbr_base_unsigned_fd(val.u, HEX_UPPER, fd);
	else if (specifier == 'c')
		ft_putchar_fd((unsigned char)val.i, fd);
	else if (specifier == 's')
	{
		if (val.s)
			ft_putstr_fd(val.s, fd);
		else
			ft_putstr_fd("(null)", fd);
	}
	else if (specifier == 'p')
	{
		ft_putstr_fd("0x", fd);
		ft_putnbr_base_unsigned_fd((size_t)val.p, HEX_LOWER, fd);
	}
	else if (specifier == '%')
		ft_putchar_fd('%', fd);
}
