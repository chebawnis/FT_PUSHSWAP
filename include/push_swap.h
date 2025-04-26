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

/////////////////INSTRUCTIONS///////////////////////
void	r(t_struct **head, int i);
void	rr(t_struct **s1, t_struct **s2);
void	r_r(t_struct **head, int i);
void	r_rr(t_struct **s1, t_struct **s2);
void	s(t_struct **head, int i);
void	p(t_struct **from, t_struct **to, int i);

/////////////////PARSING///////////////////////
void	create_last_node(int data, t_struct **head);
void	create_first_node(int data, t_struct **head);
int		fill_list(int argc, char **argv, t_struct **head);
void	FT_PUSHSWAP(int argc, char **argv);

///////////////////UTILS/////////////////////////////
void	print_list(t_struct *head);

#endif
