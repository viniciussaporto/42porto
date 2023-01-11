/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:07:43 by vsa-port          #+#    #+#             */
/*   Updated: 2022/11/11 17:58:36 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	aux = ft_lstlast(*lst);
	aux->next = new;
}

/*int		main()
{
	t_list *head;
	t_list *dois;
	t_list *tres;
	t_list *quatro;

	if(!(head = malloc(sizeof(t_list))))
		return 0;
	head->content = "-- UM --";
	head->next = NULL;

	if(!(dois = malloc(sizeof(t_list))))
		return 0;
	dois->content = "-- DOIS --";
	dois->next = NULL;

	if(!(tres = malloc(sizeof(t_list))))
		return 0;
	tres->content = "-- TRES --";
	tres->next = NULL;

	if(!(quatro = malloc(sizeof(t_list))))
		return 0;
	quatro->content = "-- QUATRO --";
	quatro->next = NULL;


	head->next = dois;
	head->next->next = tres;

	printf("All Numbers %s %s %s %p", (char *)head->content, 
	(char *)head->next->content,
	(char *)head->next->next->content,
	head->next->next->next);

	ft_lstadd_back(&head, quatro);

	printf("\nAll Numbers %s %s %s %s %p", (char *)head->content, 
	(char *)head->next->content,
	(char *)head->next->next->content,
	(char *)head->next->next->next->content,
	head->next->next->next->next);
	return(0);
}*/
