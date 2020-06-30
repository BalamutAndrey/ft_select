/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 14:10:12 by eboris            #+#    #+#             */
/*   Updated: 2020/03/11 17:50:33 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTS_STRUCTS_H
# define FTS_STRUCTS_H

# include <stdint.h>
# include <termios.h>

typedef struct		s_args
{
	struct s_args	*prev;
	struct s_args	*next;
	char			*name;
	uint8_t			selected;
	uint8_t			curr;
}					t_args;

typedef struct		s_struct
{
	struct termios	t_start;
	struct termios	t_curr;
	char			*term_name;
	int				fd;
	t_args			*first;
	uint16_t		max_len;
	uint16_t		args_nb;
}					t_struct;

#endif
