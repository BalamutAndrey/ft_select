/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdups.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 12:49:14 by eboris            #+#    #+#             */
/*   Updated: 2020/02/17 18:21:42 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRDUPS_H
# define FT_STRDUPS_H

# include <stdlib.h>
# include <string.h>
# include <wchar.h>
# include "ft_strcpys.h"
# include "ft_strs.h"

char	*ft_pf_strdup(char *s);
char	*ft_strsdup(char *b, char *a);
wchar_t	*ft_wstrdup(wchar_t *s);

#endif
