/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 15:32:42 by eboris            #+#    #+#             */
/*   Updated: 2020/03/13 15:42:35 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fts_keys.h"

void	fts_keys(t_struct *structs)
{
	uint64_t	buff;

	while ((read(structs->fd, &buff, 16)) != 0)
	{
		if (buff == 0x1B)
			fts_key_escape(structs);
		else if (buff == 0x20)
			fts_key_space(structs);
		else if (buff == 0xA)
			fts_key_enter();
		else if (buff == 0x7F)
			fts_key_delete();
		else if (buff == 0x7E335B1B)
			fts_key_delete();
		else if (buff == 0x415B1B)
			fts_key_up();
		else if (buff == 0x425B1B)
			fts_key_down();
		else if (buff == 0x435B1B)
			fts_key_right(structs);
		else if (buff == 0x445B1B)
			fts_key_left(structs);
		buff = 0;
	}
}
