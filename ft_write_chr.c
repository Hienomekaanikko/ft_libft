/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_chr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:43:56 by msuokas           #+#    #+#             */
/*   Updated: 2024/11/28 15:02:11 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_string(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0' && i > -1)
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}
int	ft_write_char(int c)
{
	return(write(1, &c, 1));
}
