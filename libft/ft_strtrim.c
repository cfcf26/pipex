/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:19:42 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/11 11:24:39 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			i;
	size_t			start;
	size_t			end;
	const size_t	s1_len = ft_strlen(s1);

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	start = i;
	if (start == s1_len)
		return (ft_strdup(""));
	i = s1_len - 1;
	while (s1[i] && ft_strchr(set, s1[i]) && i >= 0)
		i--;
	end = i;
	return (ft_substr(s1, start, (end - start + 1)));
}
