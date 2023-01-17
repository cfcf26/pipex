/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:28:00 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/11 13:35:39 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	mandatory(int argc, char *argv[], char **envp)
{
	if (argc != 5)
		ft_error(MANDATORY);
	pipex(argc, argv, envp);
}
