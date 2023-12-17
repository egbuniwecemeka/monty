#include "monty.h"

/**
 * open_file - opeans a file
 * @file_name: files path
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
 * @fd: pointer to file descriptor
 * Return: void
 */

void read_file(FILE *fd)
{
	int num_line, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (num_line = 1; getline(&buffer, &len, fd) != -1; num_line++)
	{
		format = parse_line(buffer, num_line, format);
	}
	free(buffer);
}

/**
 * parse_line - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parse_line(char *buffer, int num_line, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

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

	find_func(opcode, value, num_line, format);
	return (format);
}

/**
 * find_func - find appropriate funcs for opcode
 * @opcode: opcode
 * @val: val of opcode
 * @format: storage format. if 0 save as stack, if
 * 1 save as queue
 * @num_line: number line
 *
 * Return: void
 */

void find_func(char *opcode, char *val, int num_line, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_node},
		{"add", add_node},
		{"sub", sub_node},
		{"mul", mul_node},
		{"div", div_node},
		{"mod", mod_node},
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
			call_fun(func_list[i].f, opcode, val, num_line, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, num_line, opcode);
}

/**
 * call_fun - calls required function
 * @func: pointer to function to be callled
 * @op: string for op code
 * @val: str for numeric val
 * @num_line: number line
 * @format: format specifier: 0 for stack and 1 for queue
 *
 * Return: void
 */
void call_fun(op_func func, char *op, char *val, int num_line, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			err(5, num_line);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, num_line);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, num_line);
		if (format == 1)
			add_to_queue(&node, num_line);
	}
	else
		func(&head, num_line);
}
