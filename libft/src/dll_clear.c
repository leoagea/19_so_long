/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:30:55 by lagea             #+#    #+#             */
/*   Updated: 2024/05/21 22:25:33 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void dll_clear(t_stack *stack)
{
	t_node *temp;
	t_node *current;

	current = stack->head;
	while(current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}