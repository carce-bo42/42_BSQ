#include "header.h"

void	fill_solution_in_map(t_square *p_sq_sol)
{
	int	i;
	int	j;

	i = 0;
	while (i < p_sq_sol->size)
	{
		j = 0;
		while (j < p_sq_sol->size)
		{
			g_map[p_sq_sol->i + i][p_sq_sol->j + j] = g_filled;
			j++;
		}
		i++;
	}
}

void	print_solution(void)
{
	int	i;
	int	j;

	i = 1;
	while (i < g_fil + 1)
	{
		j = 0;
		while (j < g_col + 1)
		{
			write(1, &g_map[i][j], 1);
			j++;
		}
		i++;
	}
	return ;
}
