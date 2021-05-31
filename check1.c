#include "header.h"

/* error si archivo no empieza con numeros */
int	is_first_number (char *file)
{
	int		archv;
	char	a;

	archv = ft_open_read (file);
	read (archv, &a, 1);
	if (a < '0' || a > '9')
		return (-1);
	return (1);
}

/* obtener char empty, obstacle y filled */
char	*ft_get_control_chars_in_file(char *file)
{
	int		i;
	int		archv;
	char	*c;
	char	*p;
	char	a;

	c = malloc (3);
	i = 0;
	archv = ft_open_read(file);
	while (read(archv, &a, 1) != 0 && a != '\n')
		i++;
	close (archv);
	p = malloc (i + 1);
	archv = ft_open_read(file);
	read(archv, p, i);
	c[2] = p[i - 1];
	c[1] = p[i - 2];
	c[0] = p[i - 3];
	free (p);
	return (c);
}

/* detecta si contiene caracteres distinto control. 
recibe  (ft_get_control_chars_in_file) */
int	ft_check_chars_in_file(char *file, char *chart)
{
	int		i;
	int		archv;
	char	a;

	archv = ft_open_read(file);
	i = 0;
	while (read(archv, &a, 1) != 0)
	{
		if (a == '\n')
		{	
			i++;
			continue ;
		}	
		if (i > 0)
		{
			if (a != chart[0] && a != chart[1])
				return (-1);
		}
	}
	close (archv);
	return (1);
}
