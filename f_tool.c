#include "monty.h"

/**
 * open_file - opens a file
 *
 * @file_name: file namepath
 *
 * Return: void
 */

void open_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		err(2, file_name);
	read_file(fd);
	fclose(fd);
}

/**
 * read_file - reads a file
 *
 * @fd: pointer to a file descriptor
 *
 * Return: void
 */

void read_file(FILE *fd)
{
	int ln, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (ln = 1; getline(&buffer, &len, fd) != -1; ln++)
		format = parse_line(buffer, ln, format);
	free(buffer);
}

/**
 * parse_line - tokenize the lines
 *
 * @buffer: line form the file
 * @ln: line number
 * @format: storage format
 *
 * Return: 0 if the opcode is stack, 1 if queue
 */

int parse_line(char *buffer, int ln, int format)
{
	char *opcode, *value;
	const char *delim = "\n";

	if (buffer == NULL)
		err(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);

	value = strtok(NULL, delim);
	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func(opcode, value, ln, format);
	return (format);
}

/**
 * find_func - finds the appropriate function for the opcode
 *
 * @opcode: the opcode
 * @value: argument of opcode
 * @format: storage format
 * @ln: line number
 *
 * Return: void
 */

void find_func(char *opcode, char *value, int ln, int format)
{
	int i, flag;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;
	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, ln, opcode);
}

/**
 * call_fun - calls the required function
 *
 * @func: pointer to the function
 * @op: the opcode string
 * @val: string representing a numeric value
 * @ln: line number
 * @format: format specifier
 */

void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag, i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (format ==  0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
