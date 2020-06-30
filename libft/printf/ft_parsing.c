/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 16:58:26 by eboris            #+#    #+#             */
/*   Updated: 2020/02/17 18:27:07 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parsing.h"

int8_t	ft_parsing(t_mainlist *param, va_list ap)
{
	int64_t	i;
	char	*temp;

	while ((i = ft_strpercent(param->line)) != -1)
	{
		if ((temp = ft_strmbncpy(param->line, i)) == NULL)
			return (0);
		param->line_length = param->line_length +
			ft_pf_putstr(temp, param->fd);
		ft_strdel(&temp);
		if ((param->line = ft_strmancpy(param->line, i)) == NULL)
			return (0);
		if (ft_flags(param, ap) == 0)
			return (0);
		ft_printf_mainlist(param);
	}
	param->line_length = param->line_length +
		ft_pf_putstr(param->line, param->fd);
	return (1);
}
