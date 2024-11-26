/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:15:37 by gpicchio          #+#    #+#             */
/*   Updated: 2024/11/26 17:22:23 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	minus(char c, int fd, t_flags flags)
{
	int		count;

	count = 1;
	if(flags.point == -1)
	{
		write(fd, &c, 1);
		while(flags.num > 1)
		{
			count++;
			write(fd, " ", 1);
			flags.num--;
		}
	}
	else
	{
		write(fd, &c, 1);
	}
	return (count);
}

int	number(char c, int fd, t_flags flags)
{
	int		count;

	count = 1;
	if(flags.point == -1)
	{
		while(flags.num > 1)
		{
			count++;
			write(fd, " ", 1);
			flags.num--;
		}
		write(fd, &c, 1);
	}
	else
	{
		write(fd, &c, 1);
	}
	return (count);
}

int	ft_putchar_fd_bonus(char c, int fd, t_flags flags)
{
	if (flags.point != -1)
	{
		write(fd, &c, 1);
		return (1);
	}
	else if (flags.minus)
		return (minus(c, fd, flags));
	else if (flags.num != -1)
	{
		return (number(c, fd, flags));
	}
	write(fd, &c, 1);
	return (1);
}
