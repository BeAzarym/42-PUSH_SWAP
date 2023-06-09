/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:04:06 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/11 20:34:12 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	len;

	va_start(ap, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			len += ft_convert(*(format + 1), ap);
			format++;
		}
		else
			len += ft_print_char(*format);
		format++;
	}
	va_end(ap);
	return (len);
}
