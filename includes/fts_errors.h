/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_errors.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 13:55:15 by eboris            #+#    #+#             */
/*   Updated: 2020/03/11 17:38:02 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTS_ERRORS_H
# define FTS_ERRORS_H

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "fts_structs.h"
# include "fts_finish.h"

void	fts_check_error(int argc, char **env);
void	fts_error_start(uint8_t error);
void	fts_error_init(uint8_t error, t_struct *structs);

#endif
