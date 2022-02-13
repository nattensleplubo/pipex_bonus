/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:49:42 by ngobert           #+#    #+#             */
/*   Updated: 2022/02/13 10:57:56 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* INCLUDES */
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/libft.h"

/* STRUCTURE */
typedef struct s_data
{
	char	**argv;
	char	**envp;
	int		infile;
	int		outfile;
	int		tmp;
	int		argc;
	int		fd[2];
	pid_t	child_1;
	pid_t	child_2;
}			t_data;

/* PROTOTYPES */
void	ft_error(const char *str);
t_data	get_args(int argc, char **argv, char **envp);
char	**get_paths(t_data *data);
char	*get_bin(char *cmd, char **paths);
void	close_and_wait(t_data *data);
void	ft_free(char **tab);
char	*get_line(t_data *data);

#endif