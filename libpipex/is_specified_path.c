/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_specified_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:57:32 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/11 13:35:32 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_bool	is_specified_path(char *path)
{
	if (path[0] == '/')
		return (true);
	else if (path[0] == '~' && path[1] == '/')
		return (true);
	else if (path[0] == '.' && path[1] == '/')
		return (true);
	else if (path[0] == '.' && path[1] == '.' && path[2] == '/')
		return (true);
	else if (access(path, F_OK | X_OK) == 0)
		return (true);
	else
		return (false);
}
