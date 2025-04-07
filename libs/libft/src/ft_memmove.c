/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 02:02:45 by yfaustin          #+#    #+#             */
/*   Updated: 2024/12/11 02:02:48 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest_p;
	char	*src_p;

	dest_p = (char *)dest;
	src_p = (char *)src;
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	while (n--)
		dest_p[n] = src_p[n];
	return (dest);
}
