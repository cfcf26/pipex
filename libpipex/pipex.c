/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:51:14 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/11 13:35:59 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exev_fir_cmd_in_pipe(t_pipeline *pipeline, char **envp)
{
	pid_t	pid;

	if (pipe(pipeline->pip_in_out_fd) == -1)
		perror(EXEV_FIR_CMD_IN_PIPE1);
	pid = fork();
	if (pid == -1)
		perror(EXEV_FIR_CMD_IN_PIPE2);
	if (pid == 0)
	{
		if (pipeline->in_out_fd[0] < 0)
			exit(1);
		close(pipeline->in_out_fd[1]);
		dup2(pipeline->in_out_fd[0], 0);
		close(pipeline->in_out_fd[0]);
		dup2(pipeline->pip_in_out_fd[1], 1);
		close(pipeline->pip_in_out_fd[1]);
		close(pipeline->pip_in_out_fd[0]);
		execve(pipeline->commands[0].cmd_path, \
		&pipeline->commands[0].command[0], envp);
		perror(EXEV_FIR_CMD_IN_PIPE3);
	}
	close(pipeline->in_out_fd[0]);
	close(pipeline->pip_in_out_fd[1]);
}

void	exev_last_cmd_in_pipe(t_pipeline *pipeline, char **envp, int last)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		perror(EXEV_LAST_CMD_IN_PIPE);
	if (pid == 0)
	{
		dup2(pipeline->in_out_fd[1], 1);
		close(pipeline->in_out_fd[1]);
		dup2(pipeline->pip_in_out_fd[0], 0);
		close(pipeline->pip_in_out_fd[0]);
		execve(pipeline->commands[last].cmd_path, \
		&pipeline->commands[last].command[0], envp);
		perror(EXEV_LAST_CMD_IN_PIPE);
		exit(1);
	}
	close(pipeline->pip_in_out_fd[0]);
	close(pipeline->in_out_fd[1]);
}

void	exev_mid_cmd_in_pipe(t_pipeline *pipeline, \
char **envp, int cnt, int input)
{
	pid_t	pid;

	if (pipe(pipeline->pip_in_out_fd) == -1)
		perror(EXEV_MID_CMD_IN_PIPE);
	pid = fork();
	if (pid == -1)
		perror(EXEV_MID_CMD_IN_PIPE);
	if (pid == 0)
	{
		close(pipeline->in_out_fd[1]);
		dup2(input, 0);
		close(input);
		close(pipeline->pip_in_out_fd[0]);
		dup2(pipeline->pip_in_out_fd[1], 1);
		close(pipeline->pip_in_out_fd[1]);
		execve(pipeline->commands[cnt].cmd_path, \
		&pipeline->commands[cnt].command[0], envp);
		perror(EXEV_MID_CMD_IN_PIPE);
	}
	close(input);
	close(pipeline->pip_in_out_fd[1]);
}

void	manage_pipeline(t_pipeline *pipe, char **envp, int argc)
{
	int			cnt;
	int			i;

	cnt = 1;
	exev_fir_cmd_in_pipe(pipe, envp);
	while (cnt <= argc - 5)
	{
		exev_mid_cmd_in_pipe(pipe, envp, cnt, pipe->pip_in_out_fd[0]);
		cnt++;
	}
	exev_last_cmd_in_pipe(pipe, envp, argc - 4);
	i = -1;
	while (++i < argc - 3)
		wait(NULL);
}

void	pipex(int argc, char *argv[], char **envp)
{
	t_pipeline	*pipe;

	if (argc < 5)
		ft_error(MANAGE_PIPE);
	pipe = create_pipe_argument(argc, argv, envp);
	manage_pipeline(pipe, envp, argc);
}
