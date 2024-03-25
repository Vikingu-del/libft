/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:49:09 by eseferi           #+#    #+#             */
/*   Updated: 2024/03/11 15:49:59 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	haylen;

	haylen = ft_strlen(haystack);
	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)(&haystack[0]));
	if (haylen < len)
		len = haylen;
	while (i < len && haystack[i] != '\0')
	{
		while (haystack[i + j] == needle[j] && (i + j) < len)
			j++;
		i++;
		if (needle[j] == '\0')
			return ((char *)(&haystack[i - 1]));
		else
			j = 0;
	}
	return (NULL);
}
