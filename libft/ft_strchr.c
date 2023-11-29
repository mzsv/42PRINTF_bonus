/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:59:35 by amenses-          #+#    #+#             */
/*   Updated: 2023/07/03 19:17:38 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	c = c % 256;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == c)
		return ((char *)(s + i));
	return (0);
}
/* int main(void)
{
	int c = 't' + 256;
	char s[] = "tripouille";

	printf("%s\n", ft_strchr(s, c));//, *ft_strchr(s, c) == '\0');
	printf("%s%d(ori)\n", strchr(s, c), *strchr(s, c) == '\0');
	return (0);
} */