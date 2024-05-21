/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:39:40 by lagea             #+#    #+#             */
/*   Updated: 2024/05/21 22:30:16 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t	dll_size(t_stack *stack)
{
	size_t dll_len;
	t_node *current;

	dll_len = 0;
	current = stack->head;
	while (current != NULL)
	{
		dll_len++;
		current = current->next;
	}
	return dll_len;
}
