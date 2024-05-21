/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_delete_tail.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 00:18:01 by lagea             #+#    #+#             */
/*   Updated: 2024/05/21 22:26:31 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void dll_delete_tail(t_stack *stack)
{
	t_node *temp;
	
    temp = stack->tail;
    if (stack->head == stack->tail)
        return ;
    stack->tail = temp->prev;
    stack->tail->next = NULL;
    free(temp);
}