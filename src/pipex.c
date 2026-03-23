/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 20:22:06 by oaletham          #+#    #+#             */
/*   Updated: 2025/10/13 15:57:39 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exc(char *argv, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	if (!cmd || !*cmd)
	{
		print_cmd_not_found(NULL);
		double_free(cmd);
		exit(127);
	}
	path = get_path(cmd[0], env);
	if (!path)
	{
		print_cmd_not_found(cmd[0]);
		double_free(cmd);
		exit(127);
	}
	if (execve(path, cmd, env) == -1)
	{
		perror("pipex");
		free(path);
		double_free(cmd);
		exit(126);
	}
}

static void	child(char **argv, int *pipe_type, char **env)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		child_fd(pipe_type);
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("pipex: dup2(infile)");
		close(fd);
		close(pipe_type[0]);
		close(pipe_type[1]);
		exit(1);
	}
	close (fd);
	if (dup2(pipe_type[1], STDOUT_FILENO) == -1)
	{
		perror("pipex: dup2(pipe write)");
		close(pipe_type[0]);
		close(pipe_type[1]);
		exit(1);
	}
	close(pipe_type[0]);
	close (pipe_type[1]);
	exc(argv[2], env);
}

static void	second_child(char **argv, int *pipe_type, char **env)
{
	int	fd;

	fd = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd == -1)
		second_child_fd(pipe_type);
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("pipex: dup2(outfile)");
		close(fd);
		close(pipe_type[0]);
		close(pipe_type[1]);
		exit(1);
	}
	close (fd);
	if (dup2(pipe_type[0], STDIN_FILENO) == -1)
	{
		perror("pipex: dup2(pipe read)");
		close(pipe_type[0]);
		close(pipe_type[1]);
		exit(1);
	}
	close (pipe_type[1]);
	close (pipe_type[0]);
	exc(argv[3], env);
}

static void	print_usage(int argc)
{
	if (argc != 5)
	{
		write(2,
			"Usage: ./pipex infile \"cmd1 args\" \"cmd2 args\" outfile\n",
			55);
		exit(1);
	}
}

int	main(int argc, char **argv, char **env)
{
	int		pipe_type[2];
	pid_t	process_id_1;
	pid_t	process_id_2;
	int		st2;

	print_usage(argc);
	if (pipe(pipe_type) == -1)
		failed_pipe();
	process_id_1 = fork();
	if (process_id_1 == -1)
		failed_fork(pipe_type);
	if (process_id_1 == 0)
		child(argv, pipe_type, env);
	process_id_2 = fork();
	if (process_id_2 == -1)
		failed_fork(pipe_type);
	if (process_id_2 == 0)
		second_child(argv, pipe_type, env);
	close(pipe_type[0]);
	close(pipe_type[1]);
	waitpid(process_id_1, NULL, 0);
	waitpid(process_id_2, &st2, 0);
	if (WIFEXITED(st2))
		return (WEXITSTATUS(st2));
	return (1);
}
