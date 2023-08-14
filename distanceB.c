/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distanceB.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:40:40 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/14 13:39:05 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dir(int distance, int len)
{
	if (distance == len)
		distance = 0;
	if (distance > len - distance)
		return (distance - len);
	else
		return (distance);
}

int	dis(int id, int low, t_stack *tmp)
{
	int			dis;
	int			len;

	if (!tmp || tmp->id < id)
		return (0);
	dis = 1;
	len = 1;
	while (tmp->nxt && tmp->id != low)
	{
		tmp = tmp->nxt;
		if (tmp)
			len++;
		if (tmp && tmp->id > id)
			dis++;
	}
	if (dis == len)
		return (-1 * len);
	return (dis);
}

int	dist(int id, int low, int len, t_pushswap *dt)
{
	t_stack		*tmp;
	int			dis1;
	int			dis2;
	int			biggest;

	biggest = 1;
	tmp = dt->b;
	dis1 = dis(id, low, tmp);
	while (tmp->id != low)
	{
		biggest++;
		tmp = tmp->nxt;
	}
	tmp = tmp->nxt;
	dis2 = dis(id, low, tmp);
	if (dis1 == 0 && dis2 == 0)
		return (dir(biggest, len));
	if (dis2 > 0)
		return (dir(biggest + dis2, len));
	if (dis1 < 0)
		return (dir(dis1 * -1, len));
	return (dir(dis1, len));
}

int	distance_b(int id, t_pushswap *dt)
{
	t_stack		*tmp;
	int			low;
	int			len;

	if (!dt->b)
		return (0);
	if (!dt->b->nxt && id > dt->b->id)
		return (0);
	if (!dt->b->nxt && id < dt->b->id)
		return (1);
	len = 0;
	tmp = dt->b;
	low = dt->b->id;
	while (tmp)
	{
		len++;
		if (tmp->id < low)
			low = tmp->id;
		tmp = tmp->nxt;
	}
	return (dist(id, low, len, dt));
}
