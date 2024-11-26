/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:53:16 by gpicchio          #+#    #+#             */
/*   Updated: 2024/11/26 15:27:39 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdint.h>
# include <wchar.h>
# include <locale.h>
# include <string.h>
# include "libft.h"

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		point;
	int		hashtag;
	int		space;
	int		plus;
	int		num;
}	t_flags;

int		ft_printf(const char *string, ...);
int		parse_str(char *str, va_list args, int *i,t_flags flags);
void	check_flags(char *str, int *i, t_flags *flags);
void	set_flags(t_flags *flags);
int		ft_putchar_fd_bonus(char c, int fd, t_flags flags);
void	extract_num(char *str, int *i, t_flags *flags);
void	add_padding(char *str, int num, int *count);

#endif