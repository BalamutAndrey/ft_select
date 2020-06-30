/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 14:26:10 by eboris            #+#    #+#             */
/*   Updated: 2020/02/17 18:22:29 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUTSTR_H
# define FT_PUTSTR_H

# include <unistd.h>
# include <stdint.h>
# include <wchar.h>
# include <locale.h>

uint64_t	ft_pf_putstr(char const *s, int fd);
uint64_t	ft_putwstr(wchar_t *str, int32_t fd);
void		ft_pf_putchar(char c, int fd);
uint64_t	ft_putwchar(wchar_t a, int fd);
uint64_t	ft_putwchar2(wchar_t a, int fd, unsigned char c);

#endif
