/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:12:23 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/16 18:04:06 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct s_stack
{
	int					nb;
	int					id;
	int					mv;
	int					rt;
	struct s_stack		*nxt;
}						t_stack;

typedef struct s_pushswap
{
	int					max;
	int					min;
	int					ph1;
	int					len;
	int					alen;
	int					top;
	int					cnt;
	t_stack				*a;
	t_stack				*b;
}						t_pushswap;

//ini
t_pushswap			*ft_ini(int argn, char *argc[]);
int					ft_ini_a(int argn, char *argc[], t_pushswap *dt);
int					ft_ini_inputcheck(t_pushswap *dt);
t_pushswap			*ft_error(t_pushswap *dt);

//sort
int					ft_distance(int id, t_pushswap *dt);
void				ft_phase1(t_pushswap *dt);
void				ft_phase2(t_pushswap *dt);
void				ft_solve(t_pushswap *dt);
void				ft_sort(t_pushswap *dt);
int					ft_swap(int first, int next);
void				ft_presorted(t_pushswap *dt);

//stack
t_stack				*ft_stack_add(t_stack *a, int nb);
t_stack				*ft_stack_ini(int nb, t_pushswap *dt);
t_stack				*ft_stack_last(t_stack *stack);
void				ft_stack_cleanup(t_pushswap *dt);
void				ft_stack_pa(int mute, t_pushswap *dt);
void				ft_stack_pb(int mute, t_pushswap *dt);
void				ft_stack_ra(int mute, t_pushswap *dt);
void				ft_stack_rb(int mute, t_pushswap *dt);
void				ft_stack_rr(int mute, t_pushswap *dt);
void				ft_stack_rra(int mute, t_pushswap *dt);
void				ft_stack_rrb(int mute, t_pushswap *dt);
void				ft_stack_rrr(int mute, t_pushswap *dt);
void				ft_stack_sa(int mute, t_pushswap *dt);
void				ft_stack_sb(int mute, t_pushswap *dt);
void				ft_stack_ss(int mute, t_pushswap *dt);

#endif
