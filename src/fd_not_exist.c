/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_not_exist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:49:18 by oaletham          #+#    #+#             */
/*   Updated: 2025/10/13 15:57:44 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_fd(int *pipe_type)
{
	perror("pipex: infile");
	close(pipe_type[0]);
	close(pipe_type[1]);
	exit(1);
}

void	second_child_fd(int *pipe_type)
{
	perror("pipex: outfile");
	close(pipe_type[0]);
	close(pipe_type[1]);
	exit(1);
}

void	failed_fork(int *pipe_type)
{
	perror("pipex: fork");
	close(pipe_type[0]);
	close(pipe_type[1]);
	exit(1);
}

void	failed_pipe(void)
{
	perror("pipex: pipe");
	exit(1);
}
