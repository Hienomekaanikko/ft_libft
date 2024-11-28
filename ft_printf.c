/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:43:36 by msuokas           #+#    #+#             */
/*   Updated: 2024/11/28 15:34:23 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list *args, const char format)
{
	int	total_length;

	total_length = 0;
	if (format == 'd' || format == 'i')
		total_length += ft_write_int(va_arg(*args, int));
	else if (format == '%')
	{
		total_length += 1;
		write(1, "%", 1);
	}
	else if (format == 'u')
		total_length += ft_write_unsigned_int(va_arg(*args, unsigned int));
	else if (format == 's')
		total_length += ft_write_string(va_arg(*args, char *));
	else if (format == 'c')
		total_length += ft_write_char(va_arg(*args, int));
	else if (format == 'x' || format == 'X')
		total_length += ft_hex(va_arg(*args, unsigned int), format);
	else if (format == 'p')
		total_length += ft_write_ptr(va_arg(*args, unsigned long long));
	else
		write(1, "%", 1);
	return (total_length);
}
int	skip_spaces(const char *str, int i)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		fail_check;
	int		total_length;
	va_list	args;

	i = 0;
	fail_check = 0;
	total_length = 0;
	va_start(args, str);
	while (str[i] != '\0' && fail_check > -1)
	{
		fail_check = 0;
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			fail_check += ft_format(&args, str[++i]);
			total_length += fail_check;
		}
		else
			total_length += write (1, &str[i], 1);
		i++;
	}
	va_end(args);
	if (fail_check == -1)
		return (-1);
	return (total_length);
}
