#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
extern char		**g_map;
extern int		g_fil;
extern int		g_col;
extern char		g_empty;
extern char		g_obstacle;
extern char		g_filled;
typedef struct s_square
{
	int	i;
	int	j;
	int	size;
}	t_square;
int		ft_file_size(char *file);
int		ft_open_read(char *file);
int		ft_num_col (char *file);
int		ft_num_lineas (char *file);
int		ft_check_chars (void);
void	ft_dimension_gmap(void);
void	ft_copy_to_array(char *file);
int		is_first_number (char *file);
char	*ft_get_control_chars_in_file(char *file);
int		ft_check_chars_in_file(char *file, char *chart);
int		ft_check_chars_no_rep (char *chars);
int		ft_check_chars_no_rep (char *chars);
int		ft_line_is_not_zero (char *file);
int		ft_colum_is_not_zero(char *file);
int		ft_num_lines_head(char *file);
int		*ft_long_per_line (int numl, char *file);
int		ft_ecual_perline (int *listl, int nline);
int		ft_search_t_square(t_square control);
void	solver(t_square *p_sq_sol);
int		searcher(t_square *p_sq_sol);
void	init_sq_sol(t_square *p_sq_sol);
void	control_to_sol(t_square *p_sq_sol, t_square control);
void	print_solution(void);
void	fill_solution_in_map(t_square *p_sq_sol);
int		ft_control_check(char *file);
void	ft_init_map(char *file);
void	ft_get_control_chars(void);
void	ft_solutionator(t_square *p_sq_sol, char *file);
char	*ft_arg_is_empty(void);
int		ft_atoi(char *str);
char	*ft_get_number (char *file);
int		ft_check_head_number (char *file);
int		ft_check_string(char *str);
void	solution_single_arg(char *file, t_square *p_sq_sol);
void	solution_several_arg(char *file, t_square *p_sq_sol);
#endif
