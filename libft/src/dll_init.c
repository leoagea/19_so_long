/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:44:53 by lagea             #+#    #+#             */
/*   Updated: 2024/05/21 22:42:43 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_stack *dll_init(void)
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	stack->head = NULL;
	stack->tail = NULL;

	return (stack);
}