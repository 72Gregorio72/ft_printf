/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_minus_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpicchio <gpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:28:25 by gpicchio          #+#    #+#             */
/*   Updated: 2024/11/25 17:02:08 by gpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	manage_minus(char *str, int *i, int *count)
{
	int		num;
	(*count)++;

	if (str[*i] >= '0' && str[*i] <= '9')
	{
		num = ft_atoi(&str[*i]);
	}
	if (str[*i] == '-')
	{
		*i += 1;
		//manage_minus(str, i, count);
	}
}