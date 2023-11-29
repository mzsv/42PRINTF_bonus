/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:52:12 by amenses-          #+#    #+#             */
/*   Updated: 2023/07/03 22:25:36 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_readflags(t_content *a, const char *fmt)
{
	char	*f;
	size_t	i;

	i = 0;
	while (ft_isflag(fmt[i]))
		i++;
	f = ft_substr(fmt, 0, i);
	a->offset = i;
	return (f);
}

void	ft_setflags(t_content *a, const char *fmt)
{
	char		*f;

	f = ft_readflags(a, fmt);
	if (ft_strchr(f, '-'))
		a->minus = 1;
	if (ft_strchr(f, '0') && a->minus == 0)
		a->zero = 1;
	if (ft_strchr(f, '#') && a->spec != 'd' \
			&& a->spec != 'i' && a->spec != 'u')
		a->hashtag = 1;
	if (ft_strchr(f, '+') && a->spec != 'u' \
			&& a->spec != 'x' && a->spec != 'X')
		a->plus = 1;
	if (ft_strchr(f, ' ') && a->plus == 0 \
			&& a->spec != 'u' && a->spec != 'x' && a->spec != 'X')
		a->space = 1;
	free(f);
}

void	ft_setfw(t_content *a, const char *fmt)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = a->offset;
	j = 0;
	while (ft_isdigit(fmt[i]))
	{
		i++;
		j++;
	}
	tmp = ft_substr(fmt, i - j, j);
	a->fw = ft_atoll(tmp);
	a->offset = i;
	free(tmp);
}

void	ft_setprc(t_content *a, const char *fmt)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = a->offset;
	if (fmt[i] == '.')
	{
		i++;
		j = 0;
		while (ft_isdigit(fmt[i]))
		{
			i++;
			j++;
		}
		tmp = ft_substr(fmt, i - j, j);
		a->prc = ft_atoll(tmp);
		free(tmp);
	}
	else
		a->prc = -1;
	if (a->prc > -1)
		a->zero = 0;
	a->offset = i;
}

t_content	*ft_getflags(const char *fmt)
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
