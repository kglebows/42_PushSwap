/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:18:43 by kglebows          #+#    #+#             */
/*   Updated: 2023/06/26 19:05:11 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackiter(t_stack *start, t_stack *end, void (*f)(void *))
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