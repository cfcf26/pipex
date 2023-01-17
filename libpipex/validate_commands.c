/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:43:22 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/11 13:36:20 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_command_validity(t_commands *command)
{
	int		i;
	char	*temp;

	i = 0;
	if (command->command == NULL)
	{
		command->cmd_path = NULL;
		return ;
	}
	temp = command->command[0];
	while (command->dirs[i])
	{
		command->cmd_path = ft_strjoin(command->dirs[i], temp);
		if (command->cmd_path == NULL)
			perror(CHECK_COMMAND_VALIDITY);
		if (access(command->cmd_path, F_OK | X_OK) == 0)
			return ;
		free(command->cmd_path);
		i++;
	}
	command->cmd_path = NULL;
}

void	validate_commands(t_commands *commands, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 3)
	{
		if (commands[i].is_specified_path == true)
		{
			if (access(commands[i].command[0], F_OK | X_OK) != 0)
				commands[i].cmd_path = NULL;
			else
				commands[i].cmd_path = commands[i].command[0];
		}
		else
			check_command_validity(&commands[i]);
		i++;
	}
}
