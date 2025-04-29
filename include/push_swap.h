#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

typedef struct s_struct
{
	int					data;
	struct s_struct		*next;
} t_struct;

/////////////////////MAIN//////////////////////////////////////////////////////////////////

void			sort_list(t_struct **head, t_struct **s2);
void			ft_pushswap(int argc, char **argv);
int				main(int argc, char **argv);

//////////////////FIRST PART///////////////////////////////////////////////////////////////

void			push_to_s2_bis(t_struct **s1, t_struct **s2, int targets[3]);
void			push_to_s2(t_struct **s1, t_struct **s2, int targets[3]);
void			reverse_sort_to_b(t_struct **s1, t_struct **s2);
void			find_hunter_and_target(t_struct *s1, t_struct *s2, int *targets);

/////////////////SECOND PART///////////////////////////////////////////////////////////////

void			ft_sort_three(t_struct **stack);
void			sort_3(t_struct **stack, int len);
int				get_lower_max(int data, t_struct *s2);
void			final_placement(t_struct **s1, t_struct **s2);

////////////////GET NUMBER SHOT////////////////////////////////////////////////////////////

int				under(int size_s1, int size_s2, int hntr, int trg);
int				over(int size_s1, int size_s2, int hntr, int trg);
int				get_number_shot(int size_s1, int size_s2, int hunter, int target);

/////////////////INSTRUCTIONS//////////////////////////////////////////////////////////////

void			r(t_struct **head, int i);
void			rr(t_struct **s1, t_struct **s2);
void			r_r(t_struct **head, int i);
void			r_rr(t_struct **s1, t_struct **s2);
void			s(t_struct **head, int i);
void			p(t_struct **from, t_struct **to, int i);

/////////////////PARSING///////////////////////////////////////////////////////////////////

int				verify_number(char *nptr);
int				verif_struct(t_struct **head);
int				fill_list(int argc, char **argv, t_struct **head);

///////////////////UTILS///////////////////////////////////////////////////////////////////

void			print_list(t_struct *head);
void			ft_putstr(char *s);
int				ft_atoi(const char *nptr);
int				is_num(char *str);
int				is_char_num(char c);
int				isstrnum(char *str);

///////////////////UTILS///////////////////////////////////////////////////////////////////

int				is_under(int len, int indice);
int				is_over(int len, int indice);
int				cmp_int(int index_1, int index_2);
int				cmp_min_int(int index_1, int index_2);
void			init_target(int *target);

////////////////LIST_FUNCTIONS/////////////////////////////////////////////////////////////

void			create_last_node(int data, t_struct **head);
void			create_first_node(int data, t_struct **head);
void			free_list(t_struct **head);
int				fill_list_str(char *str, t_struct **head);

///////////////////LIST_UTILS//////////////////////////////////////////////////////////////

int				get_pos(t_struct *head, int data);
int				is_sorted(t_struct *head);
int				get_min(t_struct *head);
int				get_max(t_struct *head);
void			get_in_top(t_struct **head, int value, int i);

///////////////////LIST_UTILS_2////////////////////////////////////////////////////////////

int				count_nodes(t_struct *head);
int				is_new_max_or_min(int data, t_struct *head);
int				get_higher_min(int data, t_struct *s2);
void			a(t_struct **head, int value, int i);

/////////////////////FT_SPLIT//////////////////////////////////////////////////////////////

int				countwords(char const *s, char c);
char			**ft_split(char const *s, char c);

#endif
