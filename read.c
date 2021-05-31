#include "header.h"

/* copia el archivo en el array g_map */
void	ft_copy_to_array (char *file)
{
	int		i;
	int		j;
	int		file_int;
	char	a;

	i = 0;
	j = 0;
	file_int = ft_open_read (file);
	while (read(file_int, &a, 1) != 0)
	{
		g_map[i][j] = a;
		if (a == '\n')
		{
			j = -1;
			i++;
		}
		j++;
	}
	close (file_int);
}

/*dimensiona la matriz */
void	ft_dimension_gmap (void)
{
	int	i;

	g_map = (char **) malloc ((g_fil + 1) * 8);
	i = 0;
	while (i <= g_fil)
	{
		g_map[i] = (char *) malloc (g_col + 1);
		i++;
	}
}

/* para obtener los caracters imprimibles */
void	ft_get_control_chars(void)
{
	int		i;

	i = 0;
	while (g_map[0][i] != '\n')
	{
		i++;
	}
	g_empty = g_map[0][i - 3];
	g_obstacle = g_map[0][i - 2];
	g_filled = g_map[0][i - 1];
}

void	ft_init_map(char *file)
{
	g_fil = ft_num_lineas(file);
	g_col = ft_num_col(file);
	ft_dimension_gmap();
	ft_copy_to_array(file);
	ft_get_control_chars();
}
