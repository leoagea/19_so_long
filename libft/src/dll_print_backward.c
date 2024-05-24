/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_print_backward.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:38:24 by lagea             #+#    #+#             */
/*   Updated: 2024/05/20 18:34:04 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"
#include "../../inc/push_swap.h"

void	dll_print_backward(t_stack *stack)
{
	t_node	*current;

	current = stack->tail;
	while (current != NULL)
	{
		printf("index %d : %zd\n", current->index, current->value);
		current = current->prev;
	}
}
