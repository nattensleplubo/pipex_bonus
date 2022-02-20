/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:54:48 by ngobert           #+#    #+#             */
/*   Updated: 2022/02/20 17:00:29 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc_child(t_data *data)
{
	if (data->here_doc == false)
		dup2(data->infile, STDIN_FILENO);
}

void	run_first(t_data *data)
{
	char	**paths;
	char	*cmd;
	char	*bin;
	
	data->child[0] = fork();
	if(data->child[0] < 0)
	{
		ft_error("Fork error");
	}
	else if (data->child[0] == 0)
	{
		cmd = (ft_split(data->argv[2], ' '));
		paths = get_paths(data);
		bin = get_bin(cmd[0], paths);
		close(data->pipe[0][0]);
		here_doc_child(data);
		dup2(data->pipe[0][1], STDOUT_FILENO);
		if (data->here_doc == false)
			close(data->infile);
		close(data->pipe[0][1]);
		execve(bin, cmd, data->envp);
	}
}

void	ft_pipex(t_data *data, int argc, char **argv)
{
	int	i;

	i = 1;
	data->nb_cmd = argc - 3;
	pipe_creator(data);
	run_first(data);
	while (i < data->nb_cmd - 1);
	{
		run_mid(data, i);
		i++;
	}
	run_last(data);
	wait_childs(data);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		i;

	i = 0;
	if (argc < 5)
		ft_error("Error");
	else
	{
		data = get_args(argc, argv, envp);
		data.outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC);
		data.infile = open(argv[1], O_RDONLY);
		if (!data.infile || !data.outfile)
			ft_error("Error");
		ft_pipex(&data, argc, argv);
	}
}