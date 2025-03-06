#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_struct
{
	int					data;
	int					index;
	struct s_struct		*next;
} t_struct;

void	create_last_node(int data, int index, t_struct **head);
void	create_first_node(int data, int index, t_struct **head);
void	fill_list(int argc, char **argv, t_struct **head);
void	rotate(t_struct **head);
void	r_rotate(t_struct **head);
void	swap(t_struct **head);
void	print_list(t_struct **head);
void	FT_PUSHSWAP(int argc, char **argv);

#endif
