/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:45:25 by gpicchio          #+#    #+#             */
/*   Updated: 2024/11/26 15:26:52 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	add_padding(char *str, int num, int *count)
{
	while (num > 0)
	{
		*count += ft_putchar_fd(' ', 1);
		num--;
	}
	ft_printf(str, 1);
}

void	extract_num(char *str, int *i, t_flags *flags)
{
	int		j;

	j = *i;
	if(ft_isdigit(str[j]))
		flags->num = 0;
	while(ft_isdigit(str[j]))
		flags->num = (flags->num * 10) + (str[j++] - '0');
	if(str[j] == '.')
	{
		flags->point = ft_atoi(&str[j + 1]);
		j += 1;
		while (ft_isdigit(str[j]))
			j += 1;
	}
	*i = j;
}

void	check_flags(char *str, int *i, t_flags *flags)
{
	while(str[*i])
	{
		if (str[*i] == '-')
		{
			flags->minus = 1;
		}
		else if (str[*i] == '0')
			flags->zero = 1;
		else if (str[*i] == '#')
			flags->hashtag = 1;
		else if (str[*i] == ' ')
			flags->space = 1;
		else if (str[*i] == '+')
			flags->plus = 1;
		else if((ft_isdigit(str[*i]) && str[*i] != '0') || (str[*i] == '.'))
			return (extract_num(str, i, flags));
		else
			break ;
		if(str[*i] == '-' || str[*i] == '0' || str[*i] == '.' || str[*i] == '#'
			|| str[*i] == ' ' || str[*i] == '+' || ft_isdigit(str[*i]))
			*i += 1;
		else
			break ;
	}
}

int	parse_str(char *str, va_list args, int *i, t_flags flags)
{
	int		count;

	count = 0;
	*i += 1;
	check_flags(str, i, &flags);
	char c = str[*i];
	if (str[*i] == 'c')
		count += ft_putchar_fd_bonus((char)va_arg(args, int), 1, flags);
	else if (str[*i] == 'd' || str[*i] == 'i')
		ft_putnbr_fd(va_arg(args, int), 1, &count);
	else if (str[*i] == 's')
	count += ft_putstr_fd(va_arg(args, char *), 1);
	else if (str[*i] == 'p')
	{
		ft_printpointer(va_arg(args, unsigned long long),
			"0123456789abcdef", &count);
	}
	else if (str[*i] == 'u')
		ft_putnbr_fd_unsigned((unsigned int)va_arg(args, int), 1, &count);
	else if (str[*i] == 'x')
		ft_putnbr_base_long(va_arg(args, unsigned int),
			"0123456789abcdef", &count);
	else if (str[*i] == 'X')
		ft_putnbr_base_long(va_arg(args, unsigned int),
			"0123456789ABCDEF", &count);
	else if (str[*i] == '%')
		count += ft_putchar_fd('%', 1);
	(void)c;
	return (count);
}
