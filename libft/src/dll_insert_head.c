/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_insert_head.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:18:21 by lagea             #+#    #+#             */
/*   Updated: 2024/05/02 17:00:59 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"
#include "../../inc/push_swap.h"

void dll_insert_head(ssize_t data, struct dll_edge *edge)
{
	t_node *new;
	
	new = dll_new_node(data);
	if (edge->head == NULL)
	{
		edge->head = new;
		edge->tail = new;
	}
	else
	{
		new->next = edge->head;
		edge->head->prev = new;
		edge->head = new;	
	}
}
