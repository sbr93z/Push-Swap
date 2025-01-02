/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sferrad <sferrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:47:01 by sferrad           #+#    #+#             */
/*   Updated: 2024/12/29 14:49:35 by sferrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_list *list)
{
	while (list && list->next)
	{
		if (*(int *)(list->content) > *(int *)(list->next->content))
			return (0);
		list = list->next;
	}
	return (1);
}

void	ft_error(int ac, char **av, t_list **pilea, int i)
{
	if (ac == 2)
	{
		if (!ft_parsing_str(av[1], pilea))
		{
			ft_putstr_fd("Error\n", 2);
			ft_lstclear(pilea, free);
			return ;
		}
	}
	else if (ac == 1)
		return ;
	else
	{
		i = 1;
		while (i < ac)
		{
			if (!ft_parsing(av[i], pilea))
			{
				ft_putstr_fd("Error\n", 2);
				ft_lstclear(pilea, free);
				return ;
			}
			i++;
		}
	}
}

void	ft_sort(t_list **pile_A, t_list **pile_B)
{	
	int	size;

	size = ft_lstsize(*pile_A);
	if (size == 3)
		ft_sort_three(pile_A);
	else if (size == 4)
		ft_sort_four(pile_A, pile_B);
	else if (size == 5)
		ft_sort_five(pile_A, pile_B);
	else
		ft_radix_sort(pile_A, pile_B);
}
