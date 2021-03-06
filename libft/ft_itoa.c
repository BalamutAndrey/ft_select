/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 09:56:23 by eboris            #+#    #+#             */
/*   Updated: 2019/09/28 13:44:52 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void		ft_itoa_minus(int *n, int *minus, int *temp)
{
	if (*n == -2147483648)
	{
		*n = *n + 1;
		*minus = -1;
		*temp = 1;
		*n = *n * -1;
	}
	else if (*n < 0)
	{
		*minus = -1;
		*n = *n * -1;
		*temp = 0;
	}
	else if (*n >= 0)
	{
		*minus = 1;
		*temp = 0;
	}
}

static int		ft_itoa_len(int n)
{
	int			len;

	len = 0;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

static void		ft_itoa_write(char *finish, int len, int n, int temp)
{
	while (n > 9)
	{
		finish[len--] = (n % 10) + '0' + temp;
		n = n / 10;
		temp = 0;
	}
	finish[len] = n + '0';
}

char			*ft_itoa(int n)
{
	int			minus;
	int			temp;
	int			len;
	char		*finish;

	ft_itoa_minus(&n, &minus, &temp);
	len = ft_itoa_len(n);
	if (minus == -1)
	{
		if (!(finish = malloc((len + 2) * sizeof(char))))
			return (NULL);
		len++;
		finish[0] = '-';
	}
	else
	{
		if (!(finish = malloc((len + 1) * sizeof(char))))
			return (NULL);
	}
	finish[len--] = '\0';
	ft_itoa_write(finish, len, n, temp);
	return (finish);
}
