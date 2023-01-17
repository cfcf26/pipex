/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:43:27 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/11 11:22:08 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*str;
	const unsigned char	temp = (unsigned char)c;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == temp)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
