#include "header.h"

int	ft_atoi(char *str)
{
	int	j;
	int	n;
	int	k;

	k = 0;
	n = 0;
	j = 9;
	if (ft_check_string(str) == -1)
		return (-1);
	while (str[k] >= '0' && str[k] <= '9')
	{
		if (k < j)
			n = n * 10 + str[k] - '0';
		else
		{
			n = -1;
			break ;
		}
		k++;
		if (n == 0)
			j++;
	}
	return (n);
}

int	ft_check_string(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (1);
}

char	*ft_get_number (char *file)
{
	int		i;
	int		archv;
	char	*s;
	char	a;

	i = 0;
	archv = ft_open_read(file);
	while (read(archv, &a, 1) != 0 && a != '\n')
		i++;
	close (archv);
	s = malloc (i + 1);
	archv = ft_open_read(file);
	read(archv, s, i);
	s[i - 3] = '\0';
	free (s);
	return (s);
}

int	ft_check_head_number (char *file)
{
	char	*line_nbr_str;
	int		line_nbr;

	line_nbr_str = ft_get_number(file);
	line_nbr = ft_atoi(line_nbr_str);
	if (line_nbr == -1)
		return (-1);
	if (line_nbr != ft_num_lines_head(file) - 1)
		return (-1);
	return (1);
}
