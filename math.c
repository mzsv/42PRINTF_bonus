/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:51:55 by amenses-          #+#    #+#             */
/*   Updated: 2023/07/03 22:28:25 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_off0(long long n)
{
	if (n < 0)
		return (0);
	return (n);
}

int	ft_sign(long long n)
{
	if (n < 0)
		return (-1);
	return (1);
}

size_t	ft_max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

size_t	ft_min(size_t a, size_t b)
{
	if (a > b)
		return (b);
	else
		return (a);
}
