/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:27:21 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/16 13:29:00 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_add(t_stack *a, int nb)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->mv = 1;
	new->rt = 0;
	new->nxt = NULL;
	new->id = 0;
	a->nxt = new;
	return (new);
}

t_stack	*ft_stack_ini(int nb, t_pushswap *dt)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->mv = 1;
	new->nxt = NULL;
	new->rt = 0;
	new->id = 0;
	dt->a = new;
	return (new);
}

t_stack	*ft_stack_last(t_stack *stack)
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

void	ft_stack_cleanup(t_pushswap *dt)
{
	t_stack		*tmp;
	t_stack		*nxt;

	tmp = dt->a;
	while (tmp)
	{
		nxt = tmp->nxt;
		free(tmp);
		tmp = nxt;
	}
	tmp = dt->b;
	while (tmp)
	{
		nxt = tmp->nxt;
		free(tmp);
		tmp = nxt;
	}
	free(dt);
	dt = NULL;
}
