#include "header.h"

char	*ft_arg_is_empty(void)
{
	char	a;
	int		archv;

	a = 'a';
	archv = open ("substitute_file", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (archv < 0)
		return (NULL);
	while (read(STDIN_FILENO, &a, 1) != 0)
		write(archv, &a, 1);
	close (archv);
	return ("substitute_file");
}

void	ft_solutionator(t_square *p_sq_sol, char *file)
{
	ft_init_map(file);
	init_sq_sol(p_sq_sol);
	solver(p_sq_sol);
	fill_solution_in_map(p_sq_sol);
	print_solution();
}
