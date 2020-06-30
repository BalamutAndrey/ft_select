/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 15:15:16 by eboris            #+#    #+#             */
/*   Updated: 2020/03/13 15:05:10 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fts_args.h"

void	fts_args_write(t_struct *structs, int argc, char **argv)
{
	uint16_t	i;
	t_args		*first;
	t_args		*prev;
	t_args		*new;

	i = 1;
	first = malloc(sizeof(t_args));
	first->name = ft_strdup(argv[1]);
	first->next = first;
	first->selected = 0;
	first->curr = 1;
	prev = first;
	while (++i < argc)
	{
		new = malloc(sizeof(t_args));
		new->name = ft_strdup(argv[i]);
		new->prev = prev;
		new->next = first;
		new->selected = 0;
		new->curr = 0;
		prev->next = new;
		prev = new;
	}
	first->prev = prev;
	structs->first = first;
}

void	fts_args_del(t_struct *structs, char *name)
{
	uint16_t	i;
	t_args		*args;
	t_args		*temp;

	i = 0;
	args = structs->first;
	while (++i < structs->args_nb)
		if (ft_strcmp(args->name, name) == 0)
		{
			if (args->prev != NULL)
			{
				temp = args->prev;
				temp->next = args->next;
			}
			else
				structs->first = args->next;
			ft_strdel(&args->name);
			free(args);
			structs->args_nb = structs->args_nb - 1;
			i = structs->args_nb;
		}
		else
			args = args->next;
	fts_args_max_len(structs);
}

void	fts_args_free(t_struct *structs)
{
	t_args	*curr;
	t_args	*temp;

	curr = structs->first;
	while (curr != NULL)
	{
		temp = curr->next;
		ft_strdel(&curr->name);
		free(curr);
		curr = temp;
	}
	structs->first = NULL;
	structs->max_len = 0;
	structs->args_nb = 0;
}

void	fts_args_max_len(t_struct *structs)
{
	uint16_t	i;
	uint16_t	n;
	uint16_t	z;
	t_args		*args;

	n = 0;
	z = 0;
	args = structs->first;
	while (++z < structs->args_nb)
	{
		i = ft_strlen(args->name);
		if (i > n)
			n = i;
		args = args->next;
	}
	structs->max_len = n;
}
