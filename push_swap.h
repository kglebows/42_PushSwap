/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:12:23 by kglebows          #+#    #+#             */
/*   Updated: 2023/06/27 15:21:48 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int					nb;
	int					id;
	int					mv;
	struct s_stack		*nxt;
}						t_stack;

typedef struct s_pushswap
{
	int					max;
	int					min;
	int					ph1;
	int					len;
	t_stack				*A;
	t_stack				*B;
	char				*cmd;
}						t_pushswap;

t_pushswap		*ft_ini(int argn, char *argc[]);
t_stack			*ft_stack_add(t_stack *A, int nb);
t_pushswap		*ft_ini_dt();
void			test_input(t_pushswap *dt);
int				ft_ini_A(int argn, char *argc[], t_pushswap *dt);
int				ft_ini_inputcheck(t_pushswap *dt);
t_stack			*ft_stack_ini(int nb, t_pushswap *dt);
void			ft_ini_id(t_pushswap *dt);
void			ft_ini_dtdata(t_pushswap *dt);
int				ft_ini_id_index(t_stack *temp, t_pushswap *dt);
void			ft_stackiter(t_stack *start, t_stack *end, void (*f)(void *));
void			ft_ini_ph1(t_pushswap *dt);
void			ft_ini_ph1_id(t_pushswap *dt);
void			test(t_pushswap *dt);
void			test_stacks(t_pushswap *dt);
void			ft_stack_pa(t_pushswap *dt);
void			ft_stack_pb(t_pushswap *dt);
void			ft_stack_ra(t_pushswap *dt);
void			ft_stack_rb(t_pushswap *dt);
void			ft_stack_rr(t_pushswap *dt);
t_stack			*ft_stacklast(t_stack *stack);
void			ft_stack_rra(t_pushswap *dt);
// void			ft_stack_rrb(t_pushswap *dt);
// void			ft_stack_rrr(t_pushswap *dt);
// void			ft_stack_sa(t_pushswap *dt);
// void			ft_stack_sb(t_pushswap *dt);
// void			ft_stack_ss(t_pushswap *dt);
#endif



/*

ToDo:
- stack phase 1 mv calculation
- phase1_id
- B stack ini
- stack operations
- phase1 simulation 
- swap algorithm 
- rotate algorithm
- sort check
- distance calculation algorithm
- distance implementation.
- print out Error\n if error.

phase1 - push_swap:
- find the id that would leave in stack 1 the biggest number of elements after phase 1
- implementing swap when element fits the swap. When reaching the next element see if swap will still fit. if yes, do it.
- if sort check ok on A, begin phase 2.
- mv contains number of elements left in A after phase 1 - without swaps (default -1)

phase2 - rotate_push:
- mv (in stack B) - contains distance, + rotation, - reverse rotation. 
- 

swap alg:
- if swap in A, then check if swap in B would result in descending order, if yes - do double swap

distance alg:
- distance is a number of moves from B stack element to corresponding place in stack A.
- is is precalculated for rotating A stack, rotating B stack and rotating both. whichever takes less moves.
- Actual moving alg will calculate this again, this part focuses on finding the lowest amount of moves.
- < i could ditch it in favour of just wheeling it.- lets start with just that

*/