#include "header_main.h"

int	main (int argc, char **argv)
{
	int			i;
	t_square	*p_sq_sol;
	t_square	sq_sol;
	char		*file;

	p_sq_sol = &sq_sol;
	if (argc == 1)
	{
		file = ft_arg_is_empty();
		solution_single_arg(file, p_sq_sol);
	}
	else
	{
		i = 0;
		while (i < argc - 1)
		{
			if (i != 0)
				write(1, "\n", 1);
			file = argv[i + 1];
			solution_several_arg(file, p_sq_sol);
			i++;
		}
	}
	return (0);
}

void	solution_several_arg(char *file, t_square *p_sq_sol)
{
	int		j;
	char	**p;

	j = 0;
	if (ft_control_check(file) == -1)
		write (1, "map error\n", 10);
	else
	{
		ft_solutionator(p_sq_sol, file);
		while (j <= g_fil)
		{
			p = (g_map + j);
			free(*p);
			j++;
		}
		free(g_map);
	}
}

void	solution_single_arg(char *file, t_square *p_sq_sol)
{
	int		j;
	char	**p;

	j = 0;
	if (ft_control_check(file) == -1)
		write(1, "map error\n", 10);
	else
	{
		ft_solutionator(p_sq_sol, file);
		while (j <= g_fil)
		{
			p = (g_map + j);
			free(*p);
			j++;
		}
		free(g_map);
	}
}
