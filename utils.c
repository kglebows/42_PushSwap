/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:18:43 by kglebows          #+#    #+#             */
/*   Updated: 2023/06/27 14:51:52 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_stackiter(t_stack *start, t_stack *end, void (*f)(void *))
{
	t_stack		*tmp;

	tmp = start;
	while (tmp->nxt != end)
	{
		f(tmp);
		tmp = tmp->nxt;
	}
	f(tmp);
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