/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:00:33 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/11 13:34:46 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_commands	*create_commands(int argc, char *argv[], char **envp)
{
	t_commands	*commands;
	char		**dirs;
	int			i;

	commands = malloc(sizeof(t_commands) * (argc - 2));
	if (commands == NULL)
		ft_error(CREATE_COMMANDS);
	ft_memset(commands, 0, argc - 2);
	dirs = get_path_directories(envp);
	i = 0;
	while (i < argc - 3)
	{
		commands[i].is_specified_path = is_specified_path(argv[i + 2]);
		commands[i].command = \
		prepend_slash_to_command(ft_split_pipelinex(argv[i + 2], ' '), \
		commands[i].is_specified_path);
		commands[i].dirs = dirs;
		i++;
	}
	return (commands);
}
