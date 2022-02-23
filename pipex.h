/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:49:42 by ngobert           #+#    #+#             */
/*   Updated: 2022/02/23 11:49:38 by ngobert          ###   ########.fr       */
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
# include <stdbool.h>

# include "libft/libft.h"

/* STRUCTURE */
typedef struct s_data
{
	int		argc;
	int		nb_cmd;
	int		nb_pipe;
	int		**pipe;
	char	**argv;
	char	**envp;
	int		infile;
	int		outfile;
	pid_t	child[100];
	bool	here_doc;
}			t_data;

/* PROTOTYPES */
t_data	get_args(int argc, char **argv, char **envp);
void	ft_error(const char *str);
void	pipe_creator(t_data *data);
char	*get_bin(char *cmd, char **paths);
char	*get_line(t_data *data);
char	**get_paths(t_data *data);
void	run_first(t_data *data);
void	run_mid(t_data *data, int i);
void	run_last(t_data *data);

#endif