/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:42:58 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/16 16:17:23 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arr(char **arr)
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

int	isnum(char *str)
{
	while (*str != '\0')
	{
		if (!(ft_isdigit((int) *str) || *str == '-' || *str == '+'))
			return (0);
		str++;
	}
	return (1);
}

int	ft_ini_a(int argn, char *argc[], t_pushswap *dt)
{
	long		i[3];
	char		**arr;
	t_stack		*a;

	a = dt->a;
	i[0] = 1;
	while (i[0] < argn)
	{
		arr = ft_split(argc[i[0]], ' ');
		i[1] = 0;
		while (arr[i[1]])
		{
			i[2] = ft_atoi(arr[i[1]]);
			if (!isnum(arr[i[1]]) || i[2] > 2147483647 || i[2] < -2147483648)
				return (free_arr(arr), 0);
			if (!a)
				a = ft_stack_ini((int) i[2], dt);
			else
				a = ft_stack_add(a, (int) i[2]);
			i[1]++;
		}
		free_arr(arr);
		i[0]++;
	}
	return (1);
}

int	ft_ini_inputcheck(t_pushswap *dt)
{
	t_stack		*temp;
	t_stack		*tmp;
	int			check;

	temp = dt->a;
	while (temp->nxt != NULL)
	{
		check = temp->nb;
		tmp = temp;
		while (tmp->nxt != NULL)
		{
			tmp = tmp->nxt;
			if (tmp->nb == check)
				return (0);
		}
		temp = temp->nxt;
	}
	return (1);
}

t_pushswap	*ft_error(t_pushswap *dt)
{
	write(1, "Error\n", 6);
	ft_stack_cleanup(dt);
	return (NULL);
}
