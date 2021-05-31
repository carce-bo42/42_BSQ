#include "header.h"
//control general de errores
//devuelve -1 si encuentra error
//devuelve 1 si está todo OK
int	ft_control_check(char *file)
{
	int		numl;
	char	*a;

	if (is_first_number (file) == -1)
		return (-1);
	a = ft_get_control_chars_in_file(file);
	if (ft_check_chars_in_file (file, a) == -1
		|| ft_check_chars_no_rep (a) == -1)
	{
		free(a);
		return (-1);
	}
	free(a);
	if (ft_line_is_not_zero (file) == -1)
		return (-1);
	if (ft_colum_is_not_zero (file) == -1)
		return (-1);
	numl = ft_num_lines_head (file);
	if (ft_ecual_perline (ft_long_per_line (numl, file), numl) == -1)
		return (-1);
	if (ft_check_head_number(file) == -1)
		return (-1);
	return (1);
}

//cuenta todas lineas archivo incluso head
int	ft_num_lines_head(char *file)
{
	int		archv;
	int		i;
	char	a;

	i = 0;
	archv = ft_open_read(file);
	while (read(archv, &a, 1) != 0)
	{
		if (a == '\n')
			i++;
	}
	close (archv);
	return (i);
}

/* devuelve un puntero listando la
cantidad de caracteres por linea
(recibe de ft_num_lines_head) */
int	*ft_long_per_line (int numl, char *file)
{
	int		*pline;
	char	a;
	int		archv;
	int		i;
	int		j;

	pline = malloc(numl * sizeof(int));
	i = 0;
	j = 0;
	archv = ft_open_read(file);
	while (read(archv, &a, 1) != 0)
	{
		i++;
		if (a == '\n')
		{
			pline[j] = i;
			j++;
			i = 0;
		}	
	}
	return (pline);
}

/* comprueba que todas lineas
tenga mismos caracteres
(recibe de ft_long_per_line) y
*ft_num_lines_head*/
int	ft_ecual_perline (int *listl, int nline)
{
	int	i;
	int	j;
	int	resp;

	i = 1;
	j = 2;
	resp = 1;
	while (j < nline && resp != -1)
	{
		if (listl[i] != listl[j])
			resp = -1;
		i++;
		j++;
	}
	free (listl);
	return (resp);
}
