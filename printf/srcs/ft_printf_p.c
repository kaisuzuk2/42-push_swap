/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:46:24 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/05/09 16:56:44 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printaddr(uintptr_t np)
{
	int	count;

	count = 0;
	if (np >= 16)
		count = ft_printaddr(np / 16);
	count += ft_putchar("0123456789abcdef"[np % 16]);
	return (count);
}

int	ft_printf_p(void *p)
{
	int	res;

	if (p == NULL)
		return (write(1, "(nil)", 5));
	res = 0;
	res += ft_putstr("0x");
	return (res + ft_printaddr((uintptr_t)p));
}
