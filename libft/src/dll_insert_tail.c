/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_insert_tail.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:34:55 by lagea             #+#    #+#             */
/*   Updated: 2024/05/02 16:59:13 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"
#include "../../inc/push_swap.h"

void dll_insert_tail(ssize_t data, struct dll_edge *edge)
{
	t_node *new;

	new = dll_new_node(data);
	if (edge->tail == NULL)
	{
		edge->head = new;
		edge->tail = new;
	}
	else
	{
		new->prev = edge->tail;
		edge->tail->next = new;
		edge->tail = new;
	}
}
