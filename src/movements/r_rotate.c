#include "push_swap.h"

void	r_rotate(t_struct **head)
{
	t_struct								*tmp;
	t_struct								*tmp2;
	int										i;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;
	tmp = *head;
	i = 0;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *head;
	*head = tmp2;
}

void	r_r(t_struct **head, int i)
{
	if (i == 0)
		write(1, "rra\n", 4);
	else if (i == 1)
		write(1, "rrb\n", 4);
	r_rotate(head);
}

void	r_rr(t_struct **s1, t_struct **s2)
{
	rotate(s1);
	rotate(s2);
	write(1, "rrr\n", 4);
}
