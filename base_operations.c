/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:52:55 by amenses-          #+#    #+#             */
/*   Updated: 2023/07/03 22:30:03 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	ft_atoll(const char *nptr);
size_t				ft_nbrlen_base(unsigned long long nbr, \
						int sign, int base_len);
void				ft_putnbr_base(unsigned long long nbr, char *base);
void				ft_setspec(t_content *a, const char *fmt);
