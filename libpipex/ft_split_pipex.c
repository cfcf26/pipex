/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:40:35 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/11 13:35:13 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	size_t	w_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static	char	*w_dup(char	const *s, char c)
{
	size_t	i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (str == NULL)
		ft_error(W_DUP);
	ft_bzero(str, i + 2);
	ft_strlcpy(str, s, i + 1);
	return (str);
}

static char	**ft_dosplit(char const *s, char c, const size_t w_con, char **str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < w_con && s[j])
	{
		if (s[j] != c)
		{
			str[i] = w_dup(&(s[j]), c);
			while (s[j] && s[j] != c)
				j++;
			i++;
		}
		else
			j++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split_pipelinex(char const *s, char c)
{
	char			**str;
	const size_t	w_con = w_count(s, c);

	if (s[0] == '\0')
		return (NULL);
	str = malloc(sizeof(char *) * (w_con + 1));
	if (str == NULL)
		ft_error(FT_SPLIT_PIPELINEX);
	ft_dosplit(s, c, w_con, str);
	return (str);
}
