/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_delete_head.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 00:18:01 by lagea             #+#    #+#             */
/*   Updated: 2024/05/21 22:25:55 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void dll_delete_head(t_stack *stack)
{
	t_node *temp;
	
    temp = stack->head;
    if (stack->head == stack->tail)
        return ;
    stack->head = temp->next;
    stack->head->prev = NULL;
    free(temp);
}