/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sferrad <sferrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 03:50:35 by sferrad           #+#    #+#             */
/*   Updated: 2024/12/30 14:59:17 by sferrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_parsing(char *str, t_list **pilea)
{
	t_list		*list;
	long int	nb;
	long int	*val;

	if (!is_number(str))
		return (0);
	nb = ft_atol(str);
	if (nb == LONG_MAX || nb == LONG_MIN || nb > 2147483647 || nb < -2147483648)
		return (0);
	val = malloc(sizeof(long int));
	if (!val)
		return (0);
	*val = nb;
	list = ft_lstnew(val);
	if (!list)
		return (free(val), 0);
	ft_lstadd_back(pilea, list);
	if (!is_double(*pilea))
		return (0);
	return (1);
}

int	ft_parsing_str(char *str, t_list **pile_a)
{
	char	**numbers;
	int		i;

	i = 0;
	if (!str[i])
		return (0);
	if (!check_tab(str))
		return (0);
	numbers = ft_split(str, ' ');
	while (numbers[i])
	{
		if (!ft_parsing(numbers[i], pile_a))
		{
			i = 0;
			while (numbers[i])
				free(numbers[i++]);
			free(numbers);
			return (0);
		}
		i++;
	}
	i = 0;
	while (numbers[i])
		free(numbers[i++]);
	return (free(numbers), 1);
}

int	main(int ac, char **av)
{
	t_list	*pilea;
	t_list	*pile_b;
	int		i;

	i = 0;
	pile_b = NULL;
	pilea = NULL;
	ft_error(ac, av, &pilea, i);
	if (ft_is_sorted(pilea))
	{
		ft_lstclear(&pilea, free);
		return (0);
	}
	if (ft_lstsize(pilea) == 2)
	{
		if (!ft_is_sorted(pilea))
		{
			ft_instruct_swap(pilea, 1);
			ft_lstclear(&pilea, free);
			return (0);
		}
	}
	ft_sort(&pilea, &pile_b);
	ft_lstclear(&pilea, free);
	return (ft_lstclear(&pile_b, free), 0);
}
