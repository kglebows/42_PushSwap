/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:12:23 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/14 17:57:43 by kglebows         ###   ########.fr       */
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

//sort
void			ft_do_the_next_best_move(t_pushswap *dt);

//utils
t_stack			*ft_stacklast(t_stack *stack);
void			ft_mvb(t_pushswap *dt);
void			ft_sortb(t_pushswap *dt);
void			ft_free(char **arr);
t_pushswap		*ft_error(t_pushswap *dt);
int				ft_isnum(char *str);
int				ft_swap(int first, int next);
t_pushswap		*ft_ini(int argn, char *argc[]);
void			ft_cleanup(t_pushswap *dt);


//ini
void			ft_ini_dtdata(t_pushswap *dt);
void			ft_ini_id(t_pushswap *dt);
void			ft_ini_mv(t_pushswap *dt);

//distanceB
int				ft_distance_b(int id, t_pushswap *dt);

//input
int				ft_ini_a(int argn, char *argc[], t_pushswap *dt);
t_pushswap		*ft_ini_dt(void);
int				ft_ini_inputcheck(t_pushswap *dt);

//phase1
void			ft_phase1(t_pushswap *dt);
void			ft_solve(t_pushswap *dt);

//phase2
void			ft_shortphase(t_pushswap *dt);

//stack_reverseRotate
void			ft_stack_rra(t_pushswap *dt);
void			ft_stack_rrb(t_pushswap *dt);
void			ft_stack_rrr(t_pushswap *dt);

//stack_pushRotate
void			ft_stack_pa(t_pushswap *dt);
void			ft_stack_pb(t_pushswap *dt);
void			ft_stack_ra(t_pushswap *dt);
void			ft_stack_rb(t_pushswap *dt);
void			ft_stack_rr(t_pushswap *dt);

//stack_swap
void			ft_stack_sa(t_pushswap *dt);
void			ft_stack_sb(t_pushswap *dt);
void			ft_stack_ss(t_pushswap *dt);

#endif
