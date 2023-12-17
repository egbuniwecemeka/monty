#include "monty.h"

/**
 * add_to_stack - adds a node to stack
 * @new: pointer tonew node
 * @num_line: line num of opcode
 */

void add_to_stack(stack_t **new, __attribute__((unused))unsigned int num_line)
{
	stack_t *temp;

	if (new == NULL || *new == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new;
		return;
	}
	temp = head;
	head = *new;
	head->next = temp;
	temp->prev = head;
}



/**
 * print_stack - Displays a node to the stack.
 * @stack: Pointer to ptr  pointing to top node
 * @num_line: line number of  the opcode.
 */
void print_stack(stack_t **stack, unsigned int num_line)
{
	stack_t *temp;

	(void) num_line;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pop_top - Removes a node to the stack.
 * @stack: Pointer to a pointer pointing to top node.
 * @num_line: line number of the opcode.
 */
void pop_top(stack_t **stack, unsigned int num_line)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		more_err(7, num_line);

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}


/**
 * print_top - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @num_line: line number of opcode.
 */
void print_top(stack_t **stack, unsigned int num_line)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, num_line);
	printf("%d\n", (*stack)->n);
}
