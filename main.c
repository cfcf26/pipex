/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:22:33 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/11 13:36:29 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpipex/pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	if (BONUS == 1)
		bonus(argc, argv, envp);
	else
		mandatory(argc, argv, envp);
	return (0);
}
