/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 23:12:03 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/11 11:21:26 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*str;
	const size_t	total = count * size;

	str = malloc(total);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, total);
	return ((void *)str);
}
