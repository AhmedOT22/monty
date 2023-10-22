#include "monty.h"

/**
 * print_char - prints the ascii value
 *
 * @stack: pointer to a pointer to the top node of the stack
 * @ln: line number
 */

void print_char(stack_t **stack, unsigned int ln)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		string_err(11, ln);
	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		string_err(10, ln);
	print("%c\n", ascii);
}

/**
 * print_str - prints a string
 *
 * @stack: pointer to a pointer to the top node of the stack
 * @ln: line number
 */

void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		print("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl - rotates the first node to the bottom
 *
 * @stack: pointer to a pointer to the top node of the stack
 * @ln: line number
 */

void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotr - rotates the last node to the bottom
 *
 * @stack: pointer to a pointer to the top node of the stack
 * @ln: line number
 */

void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack;
	tmp->prev->next = NULL;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	(*stack) = NULL;
}