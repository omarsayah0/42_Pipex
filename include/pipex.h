/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:29:25 by oaletham          #+#    #+#             */
/*   Updated: 2025/10/13 17:59:35 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>

void	double_free(char **str);
char	*get_path(char *argv, char **env);
void	second_child_fd(int *pipe_type);
void	child_fd(int *pipe_type);
void	print_cmd_not_found(const char *name);
void	failed_fork(int *pipe_type);
void	failed_pipe(void);

#endif
