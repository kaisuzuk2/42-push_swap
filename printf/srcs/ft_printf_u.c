/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:10:01 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/05/09 16:58:10 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_u(unsigned int un)
{
	char	buf[11];
	int		i;

	i = 10;
	buf[i] = '\0';
	while (1)
	{
		buf[--i] = "0123456789"[un % 10];
		un /= 10;
		if (!un)
			break ;
	}
	return (ft_putstr(&buf[i]));
}
