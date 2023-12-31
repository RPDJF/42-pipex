/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:36:49 by rude-jes          #+#    #+#             */
/*   Updated: 2023/12/31 14:34:45 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

static void	close_heredoc(int fd, t_pipex *pipex)
{
	if (close(fd) < 0)
	{
		ft_putendl_fd("ERROR", 2);
		unlink(HEREDOC_FILENAME);
		exitprogmsg(*pipex, strerror(errno));
	}
}

static char	*get_input(void)
{
	write(STDOUT_FILENO, "> ", 2);
	return (ft_get_next_line(STDIN_FILENO));
}

static int	write_temp(char *limiter, t_pipex *pipex, int fd)
{
	char	*line;
	int		i;

	i = 1;
	line = get_input();
	while (line)
	{
		if (ft_strlen(limiter) == ft_strlen(line) - 1
			&& !ft_strncmp(line, limiter, ft_strlen(line) - 1))
			break ;
		if (write(fd, line, ft_strlen(line) - 1) < 0 || write(fd, "\n", 1) < 0)
			exitprogmsg(*pipex, strerror(errno));
		line = get_input();
		i++;
	}
	close_heredoc(fd, pipex);
	if (!line)
		ft_putchar_fd('\n', STDOUT_FILENO);
	if (!line)
		progcontextmsg(*pipex, "warning",
			ft_strreplace(ft_strreplace(ERR_WRONG_LIMITER,
					VAR_LIMITER, limiter), "$line", ft_itoa(i)));
	return (i);
}

char	*init_heredoc(int *argc, char ***argv, t_pipex *pipex)
{
	int	fd;

	if (ft_strncmp((*argv)[1], "here_doc", ft_strlen((*argv)[1])))
		return ((*argv)[1]);
	pipex->heredoc = true;
	fd = open(HEREDOC_FILENAME, O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (fd < 0)
		progcontextmsg(*pipex, HEREDOC_FILENAME, strerror(errno));
	write_temp((*argv)[2], pipex, fd);
	(*argv)[1] = (*argv)[0];
	(*argv)[2] = HEREDOC_FILENAME;
	(*argv)++;
	(*argc)--;
	return (HEREDOC_FILENAME);
}
