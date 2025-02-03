#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define DECIMAL	"0123456789"
# define HEX_UPPER	"0123456789ABCDEF"
# define HEX_LOWER	"0123456789abcdef"

typedef union u_value
{
	int				i;
	long int		li;
	unsigned int	u;
	long unsigned int	lu;
	char			*s;
	void			*p;
}	t_value;

typedef struct s_spec
{
	int	flags;
	int width;
	int modifier;
	char conversion;
} t_spec;

int		ft_printf(const char *format, ...);
int		ft_vprintf(const char *format, va_list ap);
int		ft_vdprintf(int fd, const char *format, va_list ap);
int		ft_dprintf(int fd, const char *format, ...);

#endif
