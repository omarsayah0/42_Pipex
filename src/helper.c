/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:20:40 by oaletham          #+#    #+#             */
/*   Updated: 2025/10/13 16:21:19 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	double_free(char **str)
{
	size_t	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static char	*get_env_path(char **env)
{
	int	i;

	if (!env)
		return (NULL);
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

static char	*search_in_paths(char *argv, char **allpathes)
{
	char	*part_of_path;
	char	*the_final_path;
	int		i;

	i = 0;
	while (allpathes[i])
	{
		if (allpathes[i][0] == '\0')
			part_of_path = ft_strdup("");
		else
			part_of_path = ft_strjoin(allpathes[i], "/");
		if (!part_of_path)
			return (NULL);
		the_final_path = ft_strjoin(part_of_path, argv);
		free(part_of_path);
		if (!the_final_path)
			return (NULL);
		if (access(the_final_path, F_OK | X_OK) == 0)
			return (the_final_path);
		free(the_final_path);
		i++;
	}
	return (NULL);
}

char	*get_path(char *argv, char **env)
{
	char	**allpathes;
	char	*get_path_var;
	char	*the_final_path;

	if (!argv || !*argv)
		return (NULL);
	if (ft_strchr(argv, '/'))
	{
		if (access(argv, X_OK) == 0)
			return (ft_strdup(argv));
		return (NULL);
	}
	get_path_var = get_env_path(env);
	if (!get_path_var)
		return (NULL);
	allpathes = ft_split(get_path_var, ':');
	if (!allpathes)
		return (NULL);
	the_final_path = search_in_paths(argv, allpathes);
	double_free(allpathes);
	if (the_final_path)
		return (the_final_path);
	return (NULL);
}

void	print_cmd_not_found(const char *name)
{
	write(2, "pipex: command not found: ", 26);
	if (name && *name)
		write(2, name, ft_strlen(name));
	else
		write(2, "(null)", 6);
	write(2, "\n", 1);
}
