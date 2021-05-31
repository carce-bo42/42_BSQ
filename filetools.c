#include "header.h"

/* abre un fichero solo lectura (ahorrar lineas)*/
int	ft_open_read(char *file)
{
	int	a;

	a = open(file, O_RDONLY);
	return (a);
}

/* tamaño del mapa (para dimensionar el puntero 
donde se copia el mapa)*/
int	ft_file_size(char *file)
{
	int		a;
	int		i;
	char	b;

	i = 0;
	a = open (file, O_RDONLY);
	while (read (a, &b, 1) != 0)
		i++;
	close (a);
	return (i);
}

/* obtenemos el nº de columnas */
int	ft_num_col (char *file)
{
	int		a;
	int		i;
	char	b;
	int		control;

	control = 0;
	i = 0;
	a = open (file, O_RDONLY);
	while (read (a, &b, 1) != 0 && control < 2)
	{
		if (b == '\n')
			control++;
		if (control == 1)
			i++;
	}
	close (a);
	return (i - 1);
}

/* cuenta el numero de lineas del mapa */
int	ft_num_lineas (char *file)
{
	int		a;
	char	b;
	int		control;

	control = 0;
	a = open (file, O_RDONLY);
	while (read (a, &b, 1) != 0)
	{
		if (b == '\n')
			control++;
	}
	close (a);
	return (control - 1);
}
