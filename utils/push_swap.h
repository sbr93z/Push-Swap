/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sferrad <sferrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 03:51:09 by sferrad           #+#    #+#             */
/*   Updated: 2024/12/28 20:23:36 by sferrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "stdio.h"

int			ft_parsing(char *str, t_list **pilea);
int			is_double(t_list *list);
int			is_number(char *str);
int			ft_parsing_str(char *str, t_list **pilea);
int			check_tab(char *s);
long int	ft_atol(const char *nptr);
t_list		*ft_instruct_swap(t_list *pile_X, int pile);
void		ft_instruct_push(t_list **src, t_list **dest, int pile);
void		ft_instruct_rotate(t_list **list, int pile);
void		ft_instruct_reverse(t_list **list, int pile);
void		ft_instruct_ss_rr(t_list **pile_X, t_list **pile_Z, int instruct);
int			*convert_tab(t_list *list, int size);
int			ft_find_max(t_list *list);
void		ft_sort_int_tab(int *tab, int size);
void		ft_swap(int *a, int *b);
void		ft_radix_sort(t_list **pile_A, t_list **pile_B);
void		ft_sort_three(t_list **stack);
void		ft_sort_five(t_list **a, t_list **b);
int			ft_find_min_index(t_list *list);
void		ft_move_to_top(t_list **pile, int index);
int			ft_find_max_index(t_list *stack);
int			get_lenght(t_list **pile, int i);
void		ft_index(t_list *list, int size);
int			ft_find_min_index(t_list *list);
void		ft_sort_four(t_list **pile_a, t_list **pile_b);
void		ft_error(int ac, char **av, t_list **pilea, int i);
int			ft_is_sorted(t_list *list);
void		ft_sort(t_list **pile_A, t_list **pile_B);
#endif