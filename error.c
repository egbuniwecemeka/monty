#include "monty.h"

/**
 * err - prints appropriate error message
 * @err_inp: error codes as follows
 * (1) => no input file or input file exceeds one
 * (2) => provided file cannot be opened or read
 * (3) => file contains invalid command
 * (4) => proggram unable to malloc more memory
 * (5) => param to "push" not an int
 *
 * Return: void
 */

void err(int err_inp, ...)
{
	va_list err_ag;
	char *op;
	int l_num;

	va_start(err_ag, err_inp);
	switch (err_inp)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Can't open or read file%s\n",
			va_arg(err_ag, char *));
			break;
		case 3:
			l_num = va_arg(err_ag, int);
			op = va_arg(err_ag, char *);
			fprintf(stderr, "len%d: Invalid command %s\n", l_num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "len%d: Push interger\n", va_arg(err_ag, int));
			break;
		default:
			break;
	}
	free_node();
	exit(EXIT_FAILURE);
}


/**
 * more_err - more error handling
 * @err_inp: error code are as follows
 * (6) => stack empty for pint
 * (7) => stack empty for pop
 * (8) => stack too short for program
 * (9) => Division for zero
 *
 * Return: void
 */
void more_err(int err_inp, ...)
{
	va_list err_ag;
	char *op;
	int l_num;

	va_start(err_ag, err_inp);
	switch (err_inp)
	{
		case 6:
			fprintf(stderr, "len%d: can't pint, stack empty\n",
			      va_arg(err_ag, int));
			break;
		case 7:
			fprintf(stderr, "len%d: cant open pop, stack empty\n",
					va_arg(err_ag, int));
			break;
		case 8:
			l_num = va_arg(err_ag, unsigned int);
			op = va_arg(err_ag, char *);
			fprintf(stderr, "len%d: can't %s, stack too short\n", l_num, op);
			break;
		case 9:
			fprintf(stderr, "len%d: division by zero\n",
					va_arg(err_ag, unsigned int));
			break;
		default:
			break;
	}
	free_node();
	exit(EXIT_FAILURE);
}


/**
 * string_err - string error handling
 * @err_inp: error code are as follows
 * (10) => the number in node is outside ASCII value
 * (11) => stack is empty
 */
void string_err(int err_inp, ...)
{
	va_list err_ag;
	int l_num;

	va_start(err_ag, err_inp);
	l_num = va_arg(err_ag, int);
	switch (err_inp)
	{
		case 10:
			fprintf(stderr, "len%d, can't pchar, out of range\n", l_num);
			break;
		case 11:
			fprintf(stderr, "len%d, can't pchar, stack empty\n", l_num);
			break;
		default:
			break;
	}
	free_node();
	exit(EXIT_FAILURE);
}
