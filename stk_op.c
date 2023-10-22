#include "monty."

/**
 * mul_nodes - multiplies the two top elements of the stack
 *
 * @stack: pointer to a pointer to the top node of the stack
 * @ln: line number
 */

void mul_nodes(stack_t **stack, unsigned int ln)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, ln, "mul");
	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mod_nodes - returns the mod of the substraction the two top elements
 * of the stack
 *
 * @stack: pointer to a pointer to the top node of the stack
 * @ln: line number
 */

void mod_nodes(stack_t **stack, unsigned int ln)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, ln, "mod");
	if ((*stack)->n == 0)
		more_err(9, ln);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
