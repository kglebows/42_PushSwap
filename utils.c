/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:18:43 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/11 12:09:07 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_stackiter(t_stack *stack, void (*f)(void *))
{
	while (stack)
	{
		f(stack);
		stack = stack->nxt;
	}
}

t_stack *ft_stacklast(t_stack *stack)
{
	t_stack		*last;

	last = stack;
	if (last)
	{
		while (last->nxt != NULL)
			last = last->nxt;
	}
	return (last);
}

void ft_Error(void)
{
	write(1, "Error\n", 6);
}
