/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 13:53:54 by eboris            #+#    #+#             */
/*   Updated: 2020/03/08 17:39:37 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fts_errors.h"

void	fts_check_error(int argc, char **env)
{
	if (argc < 2)
		fts_error_start(1);
	if (*env == NULL || env == NULL)
		fts_error_start(1);
	if (!isatty(0))
		fts_error_start(3);
}

void	fts_error_start(uint8_t error)
{
	if (error == 1)
	{
		ft_putstr_fd("ft_select: No arguments received.\n", 2);
		ft_putstr_fd("Usage: ft_select [arguments]\n", 2);
		exit(1);
	}
	else if (error == 2)
	{
		ft_putstr_fd("ft_select: Error. No enviroment.\n", 2);
		exit(0);
	}
	else if (error == 3)
	{
		ft_putstr_fd("ft_select: Error. Not a terminal.\n", 2);
		exit(0);
	}
}

void	fts_error_init(uint8_t error, t_struct *structs)
{
	if (error == 1)
	{
		ft_putstr_fd("ft_select: Error getenv().", 2);
		ft_putstr_fd(" Failed getting TERM environnement.\n", 2);
	}
	else if (error == 2)
	{
		ft_putstr_fd("ft_select: Error tgetenv().", 2);
		ft_putstr_fd(" Failed getting TERM environnement (", 2);
		ft_putstr_fd(structs->term_name, 2);
		ft_putstr_fd(").\n", 2);
	}
	else if (error == 3)
	{
		ft_putstr_fd("ft_select: Error open().", 2);
		ft_putstr_fd(" Failed getting fd.\n", 2);
	}
	else if (error == 4)
	{
		ft_putstr_fd("ft_select: Error tcsetattr().", 2);
		ft_putstr_fd(" Failed to set termios.\n", 2);
	}
	fts_finish(structs);
}
