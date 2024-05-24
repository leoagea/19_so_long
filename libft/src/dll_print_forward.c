/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_print_forward.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:41:18 by lagea             #+#    #+#             */
/*   Updated: 2024/05/20 18:34:17 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"
#include "../../inc/push_swap.h"

void	dll_print_forward(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current != NULL)
	{
		printf("index %d : %zd\n", current->index, current->value);
		current = current->next;
	}
}
