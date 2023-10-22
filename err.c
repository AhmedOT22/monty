#include "monty.h"

/**
 * err - handles the error message
 *
 * @err_code: error code
 */

void err(int err_code, ...)
{
	va_list age;
	char *opr;
	int lnum;

	va_start(age, err_code);
	switch (err_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(age, char *);
			break;
		case 3:
			lnum = va_arg(age, int);
			opr = va_arg(age, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", lnum, opr);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(age, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err - handles the error message
 *
 * @err_code: error code
 */

void more_err(int err_code, ...)
{
	va_list age;
	char *opr;
	int lnum;

	va_start(age, err_code);
	switch (err_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint stack empt\n",
				va_arg(age, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(age, int));
			break;
		case 8:
			lnum = va_arg(age, unsigned int);
			opr = va_arg(age, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", lnum, opr);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(age, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - handles error message
 *
 * @err_code: error code
 */

void string_err(int err_code, ...)
{
	va_list age;
	int lnum;

	va_start(age, err_code);
	lnum = va_arg(age, int);
	switch (err_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", lnum);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", lnum);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
