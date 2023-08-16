/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:51:31 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/16 15:30:57 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(int first, int next)
{
	if (first < 0)
		first = first * -1;
	if (next < 0)
		next = next * -1;
	if (next < first)
		return (1);
	return (0);
}

int	find_longest_increasing_sequence(t_stack *node)
{
	t_stack		*current;
	int			max_mv;
	int			mv;

	if (node->nxt == NULL)
		return (node->mv);
	current = node->nxt;
	max_mv = node->mv;
	while (current != NULL)
	{
		if (current->id > node->id)
		{
			mv = find_longest_increasing_sequence(current);
			if (mv + 1 > max_mv)
				max_mv = mv + 1;
		}
		current = current->nxt;
	}
	return (max_mv);
}

void	ft_presorted(t_pushswap *dt)
{
	t_stack		*current;
	t_stack		*tmp;

	current = dt->a;
	while (current != NULL)
	{
		tmp = current->nxt;
		while (tmp != NULL)
		{
			tmp->mv = 1;
			tmp = tmp->nxt;
		}
		current->mv = find_longest_increasing_sequence(current);
		if (current->mv > dt->ph1)
			dt->ph1 = current->mv;
		current = current->nxt;
	}
}
