/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:30:33 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/16 15:35:13 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

int	best(int rb, int ra)
{
	if (abs(ra) > abs(rb))
		return (abs(ra + rb) + abs(ra));
	else
		return (abs(ra + rb) + abs(rb));
}

void	find_the_next_best_move(t_pushswap *dt)
{
	t_stack			*tmp;

	tmp = dt->a;
	dt->ph1 = tmp->mv;
	dt->top = tmp->rt;
	while (tmp)
	{
		if (best(tmp->mv, tmp->rt) < best(dt->ph1, dt->top))
		{
			dt->ph1 = tmp->mv;
			dt->top = tmp->rt;
		}
		tmp = tmp->nxt;
	}
}

void	single_rotations(t_pushswap *dt)
{
	if (dt->ph1 > 0)
	{
		ft_stack_rb(0, dt);
		if (!dt->b->nxt)
			ft_stack_pb(0, dt);
		dt->ph1--;
	}
	else if (dt->ph1 < 0)
	{
		ft_stack_rrb(0, dt);
		dt->ph1++;
	}
	else if (dt->top > 0)
	{
		ft_stack_rra(0, dt);
		dt->top--;
	}
	else if (dt->top < 0)
	{
		ft_stack_ra(0, dt);
		dt->top++;
	}
}

void	ft_sort(t_pushswap *dt)
{
	find_the_next_best_move(dt);
	while (dt->ph1 != 0 || dt->top != 0)
	{
		if (dt->ph1 > 0 && dt->top < 0)
		{
			ft_stack_rr(0, dt);
			dt->ph1--;
			dt->top++;
		}
		else if (dt->ph1 < 0 && dt->top > 0)
		{
			ft_stack_rrr(0, dt);
			dt->ph1++;
			dt->top--;
		}
		else
			single_rotations(dt);
	}
	ft_stack_pb(0, dt);
}
