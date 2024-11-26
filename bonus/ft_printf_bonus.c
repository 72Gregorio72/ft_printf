/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:02:15 by gpicchio          #+#    #+#             */
/*   Updated: 2024/11/26 12:24:22 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	set_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->point = -1;
	flags->hashtag = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->num = -1;
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		count;
	t_flags	flags;

	i = 0;
	count = 0;
	set_flags(&flags);
	va_start(args, string);
	while (string[i])
	{
		if (string[i] == '%')
		{
			count += parse_str((char *)string, args, &i, flags);
		}
		else
		{
			ft_putchar_fd(string[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	(void)flags;
	return (count);
}
