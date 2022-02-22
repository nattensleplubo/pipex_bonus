/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:54:48 by ngobert           #+#    #+#             */
/*   Updated: 2022/02/22 19:18:36 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_childs(t_data *data)
{
	int	i;
	int	stat;

	i = 0;
	stat = 0;
	while (i < data->nb_cmd)
	{
		waitpid(data->child[i], &stat, 0);
		i++;
	}
}

void	ft_pipex(t_data *data, int argc)
{
	int	i;

	i = 1;
	data->nb_cmd = argc - 3;
	pipe_creator(data);
	run_first(data);
	while (i < data->nb_cmd - 1)
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

	data.here_doc = false;
	if (argc < 5)
		ft_error("Error");
	else
	{
		data = get_args(argc, argv, envp);
		data.outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC);
		data.infile = open(argv[1], O_RDONLY);
		if (!data.infile || !data.outfile)
			ft_error("Error");
		ft_pipex(&data, argc);
	}
}