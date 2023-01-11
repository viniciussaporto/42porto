/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:42:55 by vsa-port          #+#    #+#             */
/*   Updated: 2022/11/11 18:02:56 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;

	node = lst;
	while (node != NULL)
	{
		if (node->next == NULL)
			return (node);
		node = node->next;
	}
	return (node);
}

/*int		main()
{
	t_list *head;
	t_list *dois;
	t_list *tres;
	t_list *quatro;
	t_list *last;

	head = ft_lstnew("um");
	dois = ft_lstnew("dois");
	tres = ft_lstnew("tres");
	quatro = ft_lstnew("quatro");

	head->next = dois;
	dois->next = tres;
	tres->next = quatro;

	printf("\nO ultimo t_list e -- %s -- e tem pointer de %p \n", 
	(char *)quatro->content, quatro->next);

	last = ft_lstlast(head);

	printf("O ultimo t_list e -- %s -- e tem pointer de %p \n", 
	(char *)last->content, last->next);
}*/
