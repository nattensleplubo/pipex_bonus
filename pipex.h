/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:49:42 by ngobert           #+#    #+#             */
/*   Updated: 2022/02/20 18:30:28 by ngobert          ###   ########.fr       */
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
	int		**pipe;
	char	**argv;
	char	**envp;
	int		infile;
	int		outfile;
	int		tmpfile;
	int		fd[FOPEN_MAX][2];
	pid_t	*child;
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

#endif