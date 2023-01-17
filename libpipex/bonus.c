/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:29:50 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/11 13:34:45 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_print_c(int c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

static int	ft_print_s(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		i += ft_print_c(str[i], fd);
	return (i);
}

void	here_doc_input(char *limiter)
{
	const int	fd = open("temp", O_WRONLY | O_CREAT, 0644);
	char		*input;

	while (1)
	{
		input = get_next_line(0);
		ft_print_s(input, fd);
		if (input == NULL)
			ft_error("bash");
		if (ft_strncmp(input, limiter, ft_strlen(limiter)) == 0)
		{
			free(input);
			close(fd);
			return ;
		}
		free(input);
	}
}

void	manage_here_doc(int argc, char *argv[], char **envp)
{
	char	**new_argv;
	int		i;

	if (argc < 6 || argv[2][0] == '\0')
		ft_error(MAIN);
	here_doc_input(argv[2]);
	i = 3;
	new_argv = malloc((argc - 1) * (sizeof(char *)));
	if (new_argv == NULL)
		ft_error(HERE_DOC);
	new_argv[1] = "temp";
	while (i <= argc - 1)
	{
		new_argv[i - 1] = argv[i];
		i++;
	}
	pipex(argc - 1, new_argv, envp);
	unlink("temp");
}

void	bonus(int argc, char *argv[], char **envp)
{
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		manage_here_doc(argc, argv, envp);
	else
		pipex(argc, argv, envp);
}
