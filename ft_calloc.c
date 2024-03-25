/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 00:45:06 by eseferi           #+#    #+#             */
/*   Updated: 2024/03/24 12:53:08 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*ptr;

	total = count * size;
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);
	else
		ft_memset(ptr, 0, total);
	return (ptr);
}

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     int *arr;
//     size_t count = 5;
//     size_t size = sizeof(int);

//     arr = (int *)ft_calloc(count, size);

//     if (arr != NULL)
//     {
//         for (size_t i = 0; i < count; i++)
//         {
//             printf("%d ", arr[i]);
//         }
//         printf("\n");

//         free(arr);
//     }

//     return 0;
// }