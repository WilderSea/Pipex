/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:12:36 by msintas-          #+#    #+#             */
/*   Updated: 2022/12/10 20:09:57 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./Libft/libft.h"
# include "./ft_printf/ft_printf.h"

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	char	*name_command_1;
	char	*name_command_2;
	char	**full_command_1;
	char	**full_command_2;
	char	*environ_path;
	char	*access_path_1;
	char	*access_path_2;
}	t_pipex;

void	ft_free_split(char **split);
char	*ft_access_program(char *environ_path, char *command);
char	*ft_env_path(char **envp);
char	**ft_command_extract(char *cmd);
int		ft_first_execution(t_pipex *data, int *fd, char **envp);
int		ft_second_execution(t_pipex *data, int *fd, char **envp);
int		ft_forking_process(int argc, char *argv[], int fd[2], char **envp);
int		ft_infile_valid(char **argv);
int		main(int argc, char **argv, char **envp);

#endif
