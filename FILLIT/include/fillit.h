/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 09:03:47 by dcooray           #+#    #+#             */
/*   Updated: 2016/12/06 11:25:57 by sdahmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define BUF_SIZE	10000

typedef struct	s_tetris
{
	char			**tetris;
	int				height;
	int				width;
	char			letter;
	struct s_tetris	*next;
}				t_tetris;

typedef struct	s_coord
{
	int				i;
	int				j;
}				t_coord;

typedef struct	s_map
{
	char			**tab;
	int				size;
}				t_map;

char			*ft_open_file(char **argv);
t_tetris		*ft_define_list();
t_tetris		*ft_init_tetris(char *str);
void			ft_addlist(t_tetris **list);
void			ft_dellist(t_tetris **list);
void			ft_del_onelist(t_tetris **list);
void			ft_list_letter(t_tetris *list);
void			ft_check_form(t_tetris *list);
void			ft_error(void);
int				ft_strlen(char *str);
char			*ft_strcpy(char *dst, char *src);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putendl(char *str);
void			ft_check_motif(t_tetris *list);
int				ft_motif_sf(char **motif);
int				ft_motif_sf_bis(char **motif);
int				ft_motif_sf_ter(char **motif);
int				ft_motif_sf_quater(char **motif);
int				ft_motif_sf_quint(char **motif);
int				ft_motif(char **motif);
int				ft_motif_bis(char **motif);
int				ft_motif_ter(char **motif);
int				ft_motif_quater(char **motif);
char			**ft_param(char **motif, int *i, int *j);
int				ft_init_tetris_bis(char *str, int j);
t_map			*ft_init_map(int size);
int				ft_number_list(t_tetris *list);
void			ft_delcoord(t_coord **coord);
t_coord			*ft_init_point(int i, int j);
int				ft_place(t_tetris *list, t_map *map, int i, int j);
int				ft_resolve_array(t_map *map, t_tetris *list);
t_map			*ft_resolve(t_tetris *list);
int				high_sqrt(int n);
void			ft_delmap(t_map **map);
void			ft_return_min_square(char **table, int *k, int *l);
void			ft_print_table(t_map *map);
void			ft_put_value(t_tetris *list, t_map *map,
				t_coord *coord, char c);
t_tetris		**ft_cut_motif(t_tetris *list, t_tetris **s_list);
t_tetris		**ft_cut_motif_iter(t_tetris *list, t_tetris **s_list);
void			ft_init_h_w_motif(t_tetris *s_list);
t_coord			*ft_return_min_motif(t_tetris *list);
void			ft_init_cut(t_tetris *s_list);

#endif
