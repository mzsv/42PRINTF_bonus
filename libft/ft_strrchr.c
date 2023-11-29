/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 23:25:17 by amenses-          #+#    #+#             */
/*   Updated: 2023/07/03 19:21:26 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	c = c % 256;
	i = 0;
	while (s[i])
		i++;
	if (s[i] == c)
		return ((char *)(s + i));
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i--;
	}
	return (0);
}
/* int main(void)
{
	int c = 'z';
	char s[] = "tripouille";

	printf("%s\n", ft_strrchr(s, c));
	printf("%s(ori)\n", strrchr(s, c));
	return (0);
} */