/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:24:11 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/11 11:23:13 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	const char	temp = (char)c;

	i = 0;
	while (s[i])
	{
		if (s[i] == temp)
			return ((char *)&s[i]);
		i++;
	}
	if (temp == '\0' && s[i] == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
