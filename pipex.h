/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:49:42 by ngobert           #+#    #+#             */
/*   Updated: 2022/02/14 10:38:12 by ngobert          ###   ########.fr       */
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
	int		argc;
	char	**argv;
	char	**envp;
	int		infile;
	int		outfile;
	int		tmpfile;
	int		fd[2];
	pid_t	child_1;
	pid_t	child_2;
}			t_data;

/* PROTOTYPES */
void	ft_error(const char *str);
void	ft_free(char **tab);
void	close_and_wait(t_data *data);
char	*get_bin(char *cmd, char **paths);
char	*get_line(t_data *data);
char	**get_paths(t_data *data);
t_data	get_args(int argc, char **argv, char **envp);

#endif