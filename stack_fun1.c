#include "monty.h"

/**
 * add_to_stack - adds a node to the stack
 *
 * @new_node: pointer to the new node
 * @ln: line number
 */

void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}

/**
 * print_stack - print a node of the stack
 *
 * @stack: pointer to the new node
 * @ln: line number
 */

void print_stack(stack_t **stack, unsigned int ln)
{
	stack_t *tmp;

	(void) ln;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
