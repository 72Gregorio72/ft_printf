/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:02:15 by gpicchio          #+#    #+#             */
/*   Updated: 2024/11/25 17:01:22 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, string);
	while (string[i])
	{
		if (string[i] == '%')
		{
			parse_str((char *)string, args, &i, &count);
		}
		else
		{
			ft_putchar_fd(string[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
