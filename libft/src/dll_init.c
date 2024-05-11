/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:44:53 by lagea             #+#    #+#             */
/*   Updated: 2024/05/02 18:14:04 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

struct dll_edge *dll_init(void)
{
	struct dll_edge *edge;

	edge = malloc(sizeof(struct dll_edge));
	edge->head = NULL;
	edge->tail = NULL;

	return (edge);
}