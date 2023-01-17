/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 08:01:34 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/11 11:22:22 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const	void *src, size_t n)
{
	size_t			i;
	unsigned char	*cpy_d;
	unsigned char	*cpy_s;

	if (dst == src)
		return (dst);
	i = 0;
	cpy_d = (unsigned char *)dst;
	cpy_s = (unsigned char *)src;
	while (i < n)
	{
		cpy_d[i] = cpy_s[i];
		i++;
	}
	return (cpy_d);
}
