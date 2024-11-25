/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:53:16 by gpicchio          #+#    #+#             */
/*   Updated: 2024/11/25 16:49:55 by gpicchio         ###   ########.fr       */
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

int		ft_printf(const char *string, ...);
void	parse_str(char *str, va_list args, int *i, int *count);
void	check_flags(char *str, int *i, int *count);
void	manage_minus(char *str, int *i, int *count);

#endif