/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:12:23 by kglebows          #+#    #+#             */
/*   Updated: 2023/06/18 18:44:58 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int					nb;
	int					id;
	int					mv;
	struct s_stack		*prv;
	struct s_stack		*nxt;
}						t_stack;

typedef struct s_pushswap
{
	int					max;
	int					min;
	int					phase1_id;
	int					len;
	t_stack				*A;
	t_stack				*B;
}						t_pushswap;

#endif



/*

ToDo:
- input gather
- A stack ini
- input -> stack A
- stack phase 1 mv calculation
- pushswap max, min, len
- phase1_id
- B stack ini
- stack operations
- phase1 simulation 
- swap algorithm 
- rotate algorithm
- sort check
- distance calculation algorithm
- distance implementation.

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