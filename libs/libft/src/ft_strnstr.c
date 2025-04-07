/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 02:10:41 by yfaustin          #+#    #+#             */
/*   Updated: 2024/12/11 02:10:44 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	k;
	char	*b;

	b = (char *)big;
	if (ft_strlen(little) == 0 || big == little)
		return ((char *)big);
	i = 0;
	while (b[i] && i < len)
	{
		k = 0;
		while (little[k] && b[i + k] && b[i + k] == little[k] && i + k < len)
			k++;
		if (k == ft_strlen(little))
			return (&b[i]);
		i++;
	}
	return (0);
}
