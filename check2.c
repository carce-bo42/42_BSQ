#include "header.h"

/* controla que los caracteres codigo
no son repetidos 
(recibe de ft_get_control_chars_in_file)*/
int	ft_check_chars_no_rep (char *chars)
{
	if (chars[0] == chars[1])
		return (-1);
	if (chars[0] == chars[2])
		return (-1);
	if (chars[1] == chars[2])
		return (-1);
	else
		return (1);
}

// comprueba que lineas no son 0
int	ft_line_is_not_zero (char *file)
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
	if (a != '\n')
		return (-1);
	close (archv);
	if (i <= 1)
		return (-1);
	else
		return (1);
}

// comprueba que columnas no son 0
int	ft_colum_is_not_zero(char *file)
{
	int		archv;
	int		i;
	int		j;
	char	a;

	i = 0;
	j = 0;
	archv = ft_open_read(file);
	while (read(archv, &a, 1) != 0)
	{
		if (a == '\n' && j == 0)
		{
			i++;
			continue ;
		}
		if (i == 1 && a != '\n')
			j++;
	}
	close(archv);
	if (j == 0)
		return (-1);
	else
		return (1);
}
