/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_insert_tail.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:34:55 by lagea             #+#    #+#             */
/*   Updated: 2024/05/21 22:27:51 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void dll_insert_tail(int data, t_stack *stack)
{
	t_node *new;

	new = dll_new_node(data);
	if (stack->tail == NULL)
	{
		stack->head = new;
		stack->tail = new;
	}
	else
	{
		new->prev = stack->tail;
		stack->tail->next = new;
		stack->tail = new;
	}
}
