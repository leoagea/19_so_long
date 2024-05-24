/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_print_backward.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:38:24 by lagea             #+#    #+#             */
/*   Updated: 2024/05/24 17:02:27 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	dll_print_backward(t_stack *stack)
{
	int i;
	t_node	*current;

	i = 0;
	current = stack->tail;
	while (current != NULL)
	{
		ft_printf("index %d : %d\n", i, current->value);
		current = current->prev;
		i++;
	}
}
