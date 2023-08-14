/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:56:16 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/14 18:07:12 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_pushswap *dt)
{
	t_stack	*tmp;

	if (dt->b || dt->a->id != 1)
		return (0);
	else
	{
		tmp = dt->a;
		while (tmp->nxt)
		{
			if (tmp->nxt->id != tmp->id + 1)
				return (0);
			tmp = tmp->nxt;
		}
		return (1);
	}
}

int	stack_commands(char *c, t_pushswap *dt)
{
	if (c[0] == 'p' && c[1] == 'a' && c[2] == '\n')
		ft_stack_pa(dt);
	else if (c[0] == 'p' && c[1] == 'b' && c[2] == '\n')
		ft_stack_pb(dt);
	else if (c[0] == 's' && c[1] == 'a' && c[2] == '\n')
		ft_stack_sa(dt);
	else if (c[0] == 's' && c[1] == 'b' && c[2] == '\n')
		ft_stack_sb(dt);
	else if (c[0] == 's' && c[1] == 's' && c[2] == '\n')
		ft_stack_ss(dt);
	else if (c[0] == 'r' && c[1] == 'a' && c[2] == '\n')
		ft_stack_ra(dt);
	else if (c[0] == 'r' && c[1] == 'b' && c[2] == '\n')
		ft_stack_rb(dt);
	else if (c[0] == 'r' && c[1] == 'r' && c[2] == '\n')
		ft_stack_rr(dt);
	else if (c[0] == 'r' && c[1] == 'r' && c[2] == 'a' && c[3] == '\n')
		ft_stack_rra(dt);
	else if (c[0] == 'r' && c[1] == 'r' && c[2] == 'b' && c[3] == '\n')
		ft_stack_rrb(dt);
	else if (c[0] == 'r' && c[1] == 'r' && c[2] == 'r' && c[3] == '\n')
		ft_stack_rrr(dt);
	else
		return (0);
	return (1);
}

int main(int argn, char *argc[])
{
	t_pushswap		*dt;
	char			*str;

	dt = ft_ini(argn, argc);
	if (!dt)
		return (0);
	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		if (stack_commands(str, dt) == 0)
			return(ft_cleanup(dt), write(1, "Error\n", 6));
	}
	if (is_stack_sorted == 1)
		return (ft_cleanup(dt), write(1, "OK\n", 3));
	else 
		return (write(1, "OK\n", 3), ft_cleanup(dt));
}
