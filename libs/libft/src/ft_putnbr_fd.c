/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 02:05:24 by yfaustin          #+#    #+#             */
/*   Updated: 2024/12/11 02:05:26 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long int	k;

	k = n;
	if (k < 0)
	{
		ft_putchar_fd('-', fd);
		k = -k;
	}
	if (k > 9)
	{
		ft_putnbr_fd((k / 10), fd);
		ft_putchar_fd((k % 10) + '0', fd);
	}
	else
		ft_putchar_fd(k + '0', fd);
}
