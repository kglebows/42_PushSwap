/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distanceA.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:40:40 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/09 12:55:03 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int dirA(int distance, int len)
{
	if (distance == len)
		distance = 0;
	if (distance > len - distance)
		return (distance - len);
	else
		return (distance);
}

int disA(int id, int low, t_stack *tmp)
{
	int			dis;
	int			len;

	if (!tmp || tmp->id > id)
		return (0);
	dis = 1;
	len = 1;
	while (tmp->nxt && tmp->id != low)
	{
		tmp = tmp->nxt;
		if (tmp)
			len++;
		if (tmp && tmp->id < id)
			dis++;
	}
	if (dis == len)
		return (-1 * len);
	return (dis);
}

int distA(int id, int low, int len, t_pushswap *dt)
{
	t_stack		*tmp;
	int			dis1;
	int			dis2;
	int			biggest;

	biggest = 1;
	tmp = dt->A;
	dis1 = disA(id, low, tmp);
	while (tmp->id != low)
	{
		biggest++;
		tmp = tmp->nxt;
	}
	tmp = tmp->nxt;
	dis2 = disA(id, low, tmp);
	if (dis1 == 0 && dis2 == 0)
		return (dirA(biggest, len));
	if (dis2 > 0)
		return (dirA(biggest + dis2, len));
	if (dis1 < 0)
		return (dirA(dis1 * -1, len));
	return (dirA(dis1, len));
}

int distanceA(int id, t_pushswap *dt)
{
	t_stack		*tmp;
	int			low;
	int			len;

	if (!dt->A)
		return (0);
	if (!dt->A->nxt && id < dt->A->id)
		return (0);
	if (!dt->A->nxt && id > dt->A->id)
		return (1);
	len = 0;
	tmp = dt->A;
	low = dt->A->id;
	while (tmp)
	{
		len++;
		if (tmp->id < low)
			low = tmp->id;
		tmp = tmp->nxt;
	}
	return (distA(id, low, len, dt));
}

