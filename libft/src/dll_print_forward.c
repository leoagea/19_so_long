/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_print_forward.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:41:18 by lagea             #+#    #+#             */
/*   Updated: 2024/05/24 17:02:35 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	dll_print_forward(t_stack *stack)
{
	int i;
	t_node	*current;

	i = 1;
	current = stack->head;
	while (current != NULL)
	{
		ft_printf("index %d : %d\n",i, current->value);
		current = current->next;
		i++;
	}
}
