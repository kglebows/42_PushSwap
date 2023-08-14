/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:18:43 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/14 14:36:00 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pushswap	*ft_error(void)
{
	write(1, "Error\n", 6);
	return (NULL);
}

int	ft_isnum(char *str)
{
	while (*str != '\0')
	{
		if (!(ft_isdigit((int) *str) || *str == '-' || *str == '+'))
			return (0);
		str++;
	}
	return (1);
}

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

t_pushswap	*ft_ini(int argn, char *argc[])
{
	t_pushswap	*dt;

	if (argn < 2)
		return (NULL);
	dt = ft_ini_dt();
	if (!dt || ft_ini_a(argn, argc, dt) == 0)
		return (ft_error());
	if (ft_ini_inputcheck(dt) == 0)
		return (ft_error());
	ft_ini_dtdata(dt);
	ft_ini_id(dt);
	if (dt->len < 26)
		ft_ini_mv(dt);
	return (dt);
}

void	ft_cleanup(t_pushswap *dt)
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
