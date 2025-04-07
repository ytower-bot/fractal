/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 02:04:17 by yfaustin          #+#    #+#             */
/*   Updated: 2025/01/15 22:09:27 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static char	*hexnum_type(va_list args, char c)
{
	char	*str;

	if (c == 'x')
		str = ft_lxtoa(va_arg(args, unsigned int));
	else
	{
		str = ft_lxtoa(va_arg(args, unsigned int));
		ft_strupper(str);
	}
	return (str);
}

static int	num_type(va_list args, char c)
{
	int				len;
	char			*str;
	unsigned long	tmp;

	len = 0;
	if (c == 'd' || c == 'i')
		str = ft_itoa(va_arg(args, int));
	else if (c == 'u')
		str = ft_utoa(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		str = hexnum_type(args, c);
	else if (c == 'p')
	{
		tmp = (va_arg(args, unsigned long));
		if ((void *)tmp == NULL)
			return (ft_putstr_fd("(nil)", 1));
		str = ft_lxtoa(tmp);
		len += ft_putstr_fd("0x", 1);
	}
	len += ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

static int	check_type(va_list args, char c)
{
	if (c == 's')
		return (ft_putstr(va_arg(args, char *), 1));
	else if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	return (num_type(args, c));
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	args;

	va_start(args, str);
	len = 0;
	if (str == 0)
		return (-1);
	while (*str)
	{
		if (*str == '%')
			len += check_type(args, *++str);
		else
			len += ft_putchar_fd(*str, 1);
		str++;
	}
	return (len);
}
