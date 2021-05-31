#include "header.h"

//Función que itera sobre la solución anterior del cuadrado sq_sol
//y encuentra la siguiente solución, escribiendo en el cuadrado 
//sq_sol las nuevas coordenadas y tamaño. Esta función para cuando
//o bien no encuentra un cuadrado del size o bien lo encuentra. Pero
//buscar busca.
//Esto SIEMPRE devuelve uno HASTA que devuelve -1 (acaba la búsqueda).
int	searcher(t_square *p_sq_sol)
{
	t_square	control;

	control.i = p_sq_sol->i;
	control.j = p_sq_sol->j;
	control.size = p_sq_sol->size + 1;
	while (control.i <= g_fil - control.size + 1)
	{
		if (ft_search_t_square(control) == -1)
		{
			if (control.j < g_col - control.size)
				control.j++;
			else
			{
				control.i++;
				control.j = 0;
			}
		}
		else
		{
			control_to_sol(p_sq_sol, control);
			return (1);
		}
	}
	return (-1);
}

//sq_sol es el cuadrado solución que tenemos hasta el momento.
//Se inicializa en i, , size = (1,0,1). (la primera línea de 
//g_matrix es la de los caracteres).
int	ft_search_t_square(t_square control)
{
	int	k;
	int	l;

	k = 0;
	while (k < control.size)
	{
		l = 0;
		while (l < control.size)
		{
			if (g_map[control.i + k][control.j + l] != g_empty)
				return (-1);
			l++;
		}
		k++;
	}
	return (1);
}

void	solver(t_square *p_sq_sol)
{
	int	control;

	control = 0;
	while (1)
	{
		control = searcher(p_sq_sol);
		if (control == -1)
			break ;
	}
}

void	init_sq_sol(t_square *p_sq_sol)
{
	p_sq_sol->i = 1;
	p_sq_sol->j = 0;
	p_sq_sol->size = 0;
	return ;
}

void	control_to_sol(t_square *p_sq_sol, t_square control)
{
	p_sq_sol->i = control.i;
	p_sq_sol->j = control.j;
	p_sq_sol->size = control.size;
}
