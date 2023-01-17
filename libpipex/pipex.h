/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:09:27 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/11 13:36:07 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# ifndef BONUS
#  define BONUS 1
# endif
# if DEBUGE == 1
#  define GET_PATH_DIRECTORIES "bash: GET_PATH_DIRECTORIES"
#  define IS_SPECIFIED_PATH "bash: IS_SPECIFIED_PATH"
#  define PREPEND_SLASH_TO_COMMAND "bash: PREPEND_SLASH_TO_COMMAND"
#  define CREATE_COMMANDS "bash: CREATE_COMMANDS"
#  define CREATE_PIPE_ARGUMENT1 "bash: CREATE_PIPE_ARGUMENT1"
#  define CREATE_PIPE_ARGUMENT2 "bash: CREATE_PIPE_ARGUMENT2"
#  define CREATE_PIPE_ARGUMENT3 "bash: CREATE_PIPE_ARGUMENT3"
#  define FT_SPLIT_PIPELINEX "bash: FT_SPLIT_PIPELINEX"
#  define VALIDATE_COMMANDS "bash: VALIDATE_COMMANDS"
#  define CHECK_COMMAND_VALIDITY "bash: CHECK_COMMAND_VALIDITY"
#  define W_DUP "bash: W_DUP"
#  define EXEV_FIR_CMD_IN_PIPE1 "bash: EXEV_FIR_CMD_IN_PIPE1"
#  define EXEV_FIR_CMD_IN_PIPE2 "bash: EXEV_FIR_CMD_IN_PIPE2"
#  define EXEV_FIR_CMD_IN_PIPE3 "bash: EXEV_FIR_CMD_IN_PIPE3"
#  define EXEV_LAST_CMD_IN_PIPE "bash: EXEV_LAST_CMD_IN_PIPE"
#  define EXEV_MID_CMD_IN_PIPE "bash: EXEV_MID_CMD_IN_PIPE"
#  define MAIN "bash: MAIN"
#  define FT_DOSPLIT "bash: FT_DOSPLIT"
#  define HERE_DOC "bash: HERE_DOC"
#  define MANDATORY "bash: MANDATORY"
#  define MANAGE_PIPE "bash: MANAGE_PIPE"
# else
#  define GET_PATH_DIRECTORIES "bash"
#  define IS_SPECIFIED_PATH "bash"
#  define PREPEND_SLASH_TO_COMMAND "bash"
#  define CREATE_COMMANDS "bash"
#  define CREATE_PIPE_ARGUMENT1 "bash"
#  define CREATE_PIPE_ARGUMENT2 "bash"
#  define CREATE_PIPE_ARGUMENT3 "bash"
#  define FT_SPLIT_PIPELINEX "bash"
#  define VALIDATE_COMMANDS "bash"
#  define CHECK_COMMAND_VALIDITY "bash"
#  define W_DUP "bash"
#  define EXEV_FIR_CMD_IN_PIPE1 "bash"
#  define EXEV_FIR_CMD_IN_PIPE2 "bash"
#  define EXEV_FIR_CMD_IN_PIPE3 "bash"
#  define EXEV_LAST_CMD_IN_PIPE "bash"
#  define EXEV_MID_CMD_IN_PIPE "bash"
#  define MAIN "bash"
#  define FT_DOSPLIT "bash"
#  define HERE_DOC "bash"
#  define MANDATORY "bash"
#  define MANAGE_PIPE "bash"
# endif

typedef enum e_bool {false, true}	t_bool;
typedef struct s_commands
{
	t_bool	is_specified_path;
	char	**command;
	char	**dirs;
	char	*cmd_path;
}	t_commands;
typedef struct s_pipeline
{
	int					in_out_fd[2];
	int					pip_in_out_fd[2];
	struct s_commands	*commands;
}	t_pipeline;

void		ft_error(const char *str);
char		**get_path_directories(char **envp);
t_bool		is_specified_path(char *path);
char		**prepend_slash_to_command(char **cmd_and_opt, \
t_bool is_specified_path);
t_commands	*create_commands(int argc, char *argv[], char **envp);
t_pipeline	*create_pipe_argument(int argc, char *argv[], char **envp);
char		**ft_split_pipelinex(char const *s, char c);
void		validate_commands(t_commands *commands, int argc);
void		exev_fir_cmd_in_pipe(t_pipeline *pipeline, char **envp);
void		exev_mid_cmd_in_pipe(t_pipeline *pipeline, \
char **envp, int cnt, int input);
void		exev_last_cmd_in_pipe(t_pipeline *pipeline, char **envp, int last);
void		pipex(int argc, char *argv[], char **envp);
void		manage_pipeline(t_pipeline *pipe, char **envp, int argc);
void		bonus(int argc, char *argv[], char **envp);
void		mandatory(int argc, char *argv[], char **envp);
#endif