/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_ft_lstnew.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <astachni>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:45:06 by aastachni         #+#    #+#             */
/*   Updated: 2022/11/19 18:48:38 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elm;

	elm = malloc(sizeof(*content));
	if (!elm)
		return (NULL);
	elm->content = content;
	elm->next = NULL;
	return (elm);
}
