/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 13:48:41 by eboris            #+#    #+#             */
/*   Updated: 2020/02/17 18:19:41 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRS_H
# define FT_STRS_H

# include <stdlib.h>
# include <stdint.h>
# include <wchar.h>

void	ft_strdel(char **s);
int		ft_pf_strlen(char *s);
int		ft_wstrlen(wchar_t *s);
int8_t	ft_charlen(wchar_t c);
void	ft_wstrdel(wchar_t **s);

#endif
