/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:54:54 by cchabeau          #+#    #+#             */
/*   Updated: 2023/04/13 20:15:58 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

enum				e_type
{
	T_STACK = 1,
	ARRAY = 2,
	STR = 3
};

typedef struct s_structure
{
	struct s_stack	*head;
	struct s_stack	*tail;
	int				size;
}					t_body;

typedef struct s_stack
{
	int				content;
	int				expected_index;
	int				current_index;
	int				target_current;
	int				price_a;
	int				price_b;
	struct s_stack	*next;
}					t_stack;

// UTILS
int					ft_strcmp(const char *s1, const char *s2);
int					ft_isnumeric(char *str);
int					is_sorted(t_stack *stack);
char				**ft_split(char const *s, char c);
char				*ft_strdup(const char *s);
size_t				ft_strlen(const char *s);
size_t				ft_tablen(char **array);
size_t				stack_len(t_stack *stack);
long int			ft_atoi(const char *str);
void				ft_putstr_fd(char *s, int fd);

// GET_NEXT_LINE
void				ft_bzero(void *s, size_t n);
size_t				ft_strlcpy(char *dst, char *src, size_t dstsize);
char				*ft_strjoin(char *s1, char *s2, int *check_newline);
char				*ft_gnldup(char *str, int *check_newline);
char				*get_next_line(int fd);

// PARSING
int					is_double(long int nbr, t_body *structure);
char				**ft_get_arg(int argc, char **argv);

//	STACK
t_body				*init_body(void);
t_body				*fill_structure(char **array, t_body *structure);

//	OPERATION
void				swap_a(t_body *structure);
void				swap_b(t_body *structure);
void				swap_ab(t_body *structure_a, t_body *structure_b);
void				push_a(t_body *src, t_body *dest);
void				push_b(t_body *src, t_body *dest);
void				rotate_a(t_body *structure);
void				rotate_b(t_body *structure);
void				rotate_ab(t_body *structure_a, t_body *structure_b);
void				reverse_rotate_a(t_body *structure);
void				reverse_rotate_b(t_body *structure);
void				reverse_rotate_ab(t_body *structure_a, t_body *structure_b);
int					do_op(t_body *stack_a, t_body *stack_b, char *line);

//	ERROR
void				free_tab(char **array);
void				free_stack(t_body *structure);
void				ft_error(void *ptr, int type);

#endif