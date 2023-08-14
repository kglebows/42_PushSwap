/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:18:43 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/14 13:43:55 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacklast(t_stack *stack)
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

void	ft_free(char **arr)
{
	int		i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	mvb_(t_pushswap *dt, t_stack *tmp, int cnt, int rot)
{
	if (cnt < dt->alen / 2)
	{
		tmp->rt = rot * -1;
		rot++;
	}
	if (cnt == dt->alen / 2 && dt->alen % 2 == 1)
		rot++;
	if (cnt == dt->alen / 2)
		cnt++;
	if (cnt > dt->alen / 2)
	{
		tmp->rt = rot;
		rot--;
	}
	return (rot);
}

void	mvb(t_pushswap *dt)
{
	t_stack			*tmp;
	int				rot;
	int				cnt;

	rot = 0;
	cnt = 0;
	tmp = dt->a;
	while (tmp)
	{
		tmp->mv = distance_b(tmp->id, dt);
		rot = mvb_(dt, tmp, cnt, rot);
		if (cnt == dt->alen / 2)
			cnt++;
		cnt++;
		tmp = tmp->nxt;
	}
}

void	sortb(t_pushswap *dt)
{
	int		turn;

	turn = distance_b(0, dt);
	while (turn != 0)
	{
		if (turn > 0)
		{
			ft_stack_rb(dt);
			turn--;
		}
		if (turn < 0)
		{
			ft_stack_rrb(dt);
			turn++;
		}
	}
	while (dt->b)
		ft_stack_pa(dt);
}
