/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepend_slash_to_command.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:32:40 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/11 13:36:12 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**prepend_slash_to_command(char **cmd_and_opt, t_bool is_specified_path)
{
	if (cmd_and_opt == NULL)
		return (NULL);
	if (is_specified_path == true)
		return (cmd_and_opt);
	ft_memmove(cmd_and_opt[0] + 1, cmd_and_opt[0], ft_strlen(cmd_and_opt[0]));
	cmd_and_opt[0][0] = '/';
	return (cmd_and_opt);
}
