/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe_argument.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:01:22 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/18 01:35:54 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipeline	*create_pipe_argument(int argc, char *argv[], char **envp)
{
	t_pipeline	*pipe;

	pipe = malloc(sizeof(t_pipeline));
	if (pipe == NULL)
		ft_error(CREATE_PIPE_ARGUMENT1);
	pipe->commands = create_commands(argc, argv, envp);
	pipe->in_out_fd[0] = open(argv[1], O_RDWR);
	if (pipe->in_out_fd[0] < 0)
		perror(CREATE_PIPE_ARGUMENT2);
	pipe->in_out_fd[1] = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipe->in_out_fd[1] < 0)
		ft_error(CREATE_PIPE_ARGUMENT3);
	validate_commands(pipe->commands, argc);
	return (pipe);
}
