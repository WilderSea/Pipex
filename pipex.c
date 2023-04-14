/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:49:50 by msintas-          #+#    #+#             */
/*   Updated: 2023/01/30 17:45:16 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_initializer(t_pipex *data, int argc, char **argv, char **envp)
{
	data->full_command_1 = ft_command_extract(argv[2]);
	data->full_command_2 = ft_command_extract(argv[3]);
	data->name_command_1 = data->full_command_1[0];
	data->name_command_2 = data->full_command_2[0];
	data->environ_path = ft_env_path(envp);
	data->access_path_1 = ft_access_program(data->environ_path, \
			data->name_command_1);
	data->access_path_2 = ft_access_program(data->environ_path, \
			data->name_command_2);
	data->infile = open(argv[1], O_RDONLY);
	if (access(argv[argc - 1], F_OK) != 0 || access(argv[argc - 1], W_OK) == 0)
		data->outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	else if (access(argv[argc - 1], W_OK) != 0)
	{
		perror(argv[argc - 1]);
		exit(1);
	}
	if (data->outfile < 0)
		exit(1);
}

int	ft_first_execution(t_pipex *data, int *fd, char **envp)
{
	int	pid_1;

	pid_1 = fork();
	if (pid_1 == -1)
		return (2);
	if (pid_1 == 0)
	{
		if (data->infile < 0)
			exit(1);
		dup2(data->infile, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve(data->access_path_1, data->full_command_1, envp);
		ft_putstr_fd("Error: Command does not exist.\n", 2);
		exit(1);
	}
	free(data->access_path_1);
	ft_free_split(data->full_command_1);
	return (pid_1);
}

int	ft_second_execution(t_pipex *data, int *fd, char **envp)
{
	int	pid_2;

	pid_2 = fork();
	if (pid_2 == -1)
		return (7);
	if (pid_2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(data->outfile, STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve(data->access_path_2, data->full_command_2, envp);
		ft_putstr_fd("Error: Command does not exist.\n", 2);
		exit(1);
	}
	free(data->access_path_2);
	ft_free_split(data->full_command_2);
	return (pid_2);
}

int	ft_forking_process(int argc, char **argv, int fd[2], char **envp)
{
	t_pipex	data;
	int		pid_1;
	int		pid_2;
	int		exit_code;

	ft_initializer(&data, argc, argv, envp);
	pid_1 = ft_first_execution(&data, fd, envp);
	pid_2 = ft_second_execution(&data, fd, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid_1, NULL, 0);
	waitpid(pid_2, &exit_code, 0);
	return (WEXITSTATUS(exit_code));
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];

	if (argc != 5)
	{
		ft_printf("Wrong! [use] ./pipex archivo1 comando1 comando2 archivo2");
		return (1);
	}
	if (argv[1])
		ft_infile_valid(argv);
	if (pipe(fd) == -1)
		return (1);
	ft_forking_process(argc, argv, fd, envp);
	return (0);
}
