/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:59:48 by ahadama-          #+#    #+#             */
/*   Updated: 2024/05/15 13:59:51 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_libft	*ft_lstnew(void *content)
{
	t_list_libft	*r;

	r = malloc(sizeof(*r));
	if (!r)
		return (NULL);
	r->content = content;
	r->next = NULL;
	return (r);
}
