#include "monty.h"

/**
 * nop - does nothing
 *
 * @stack: pointer to a pointer to the top node of the stack
 * @ln: line number
 */

void nop(stack_t **stack, unsigned int ln)
{
	(void)stack;
	(void)ln;
}

/**
 * swap_nodes - swaps the two top elements of the stack
 *
 * @stack: pointer to a pointer to the top node of the stack
 * @ln: line number
 */

void swap_nodes(stack_t **stack, unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, ln, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * add_nodes - adds the two top elements of the stack
 *
 * @stack: pointer to a pointer to the top node of the stack
 * @ln: line number
 */

void add_nodes(stack_t **stack, unsigned int ln)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, ln, "add");
	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sub_nodes - substracts the two top elements of the stack
 *
 * @stack: pointer to a pointer to the top node of the stack
 * @ln: line number
 */

void sub_nodes(stack_t **stack, unsigned int ln)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, ln, "add");
	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div_nodes - divides the two top elements of the stack
 *
 * @stack: pointer to a pointer to the top node of the stack
 * @ln: line number
 */

void div_nodes(stack_t **stack, unsigned int ln)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, ln, "div");
	if ((*stack)->n == 0)
		more_err(9, ln);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
