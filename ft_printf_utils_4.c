/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:52:24 by amenses-          #+#    #+#             */
/*   Updated: 2023/07/03 22:25:33 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_content	*ft_getflags(const char *fmt) // D
{
	t_content	*a;

	a = ft_calloc(1, sizeof(t_content));
	if (!a)
		return (NULL);
	ft_setflags(a, fmt);
	ft_setfw(a, fmt);
	ft_setprc(a, fmt);
	ft_setspec(a, fmt);
	return (a);
}

void	ft_putc(t_content *a, char c)
{
	size_t	i;

	if (a->minus)
		ft_putchar_fd(c, 1);
	i = 0;
	while (a->fw && i < a->fw - 1)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
	if (!a->minus)
		ft_putchar_fd(c, 1);
	a->len = ft_max(1, a->fw);
}

void	ft_puts(t_content *a, char *s)
{
	size_t	i;
	size_t	len;
	int		isnull;

	isnull = 0;
	if (!s)
		s = ft_getnull(a, &isnull);
	len = ft_strlen(s);
	if (a->prc > -1)
		len = ft_min(a->prc, ft_strlen(s));
	if (a->minus)
		ft_putnstr_fd(s, len, 1);
	i = 0;
	while ((a->fw > len) && i < a->fw - len)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
	a->len = ft_max(a->fw, len);
	if (!a->minus)
		ft_putnstr_fd(s, len, 1);
	if (isnull)
		free(s);
}

void	ft_padding(t_content *a)
{
	size_t	i;

	i = 0;
	if (ft_isnumspec(a->spec))
	{
		while (!a->minus && (a->fw > ft_max(a->len + a->plus, \
				ft_off0(a->prc) + a->space + a->plus + (2 * a->hashtag))) \
				&& i < a->fw - ft_max(a->len + a->plus, ft_off0(a->prc) \
				+ a->space + a->plus + (2 * a->hashtag)))
		{
			if (a->zero)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
			i++;
		}
	}
	a->len += i;
}

void	ft_printnbr(t_content *a, unsigned long long n, char *base)
{
	size_t	i;

	i = 0;
	if (a->minus)
	{
		if (!(a->prc == 0 && n == 0))
			ft_putnbr_base(n, base);
		while ((a->fw > a->len) && i < a->fw - a->len)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
		a->len += i;
	}
	if (!a->minus && !(a->prc == 0 && n == 0))
		ft_putnbr_base(n, base);
}
