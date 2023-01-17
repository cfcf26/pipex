/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_directories.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:02:31 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/18 01:38:45 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path_directories(char **envp)
{
	int		i;
	char	**dirs;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			dirs = ft_split((envp[i] + 5), ':');
			if (dirs == NULL)
				ft_error(GET_PATH_DIRECTORIES);
			return (dirs);
		}
		i++;
	}
	ft_error(GET_PATH_DIRECTORIES);
	return (NULL);
}
