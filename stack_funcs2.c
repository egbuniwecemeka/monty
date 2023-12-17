#include "monty.h"

/**
 * nop - Dode unchanged.
 * @stack: Pointer to a pointer pointing to top node.
 * @num_line:  line number of opcode.
 */
void nop(stack_t **stack, unsigned int num_line)
{
	(void)stack;
	(void)num_line;
}


/**
 * swap_node - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node.
 * @num_line: line number of opcode.
 */
void swap_node(stack_t **stack, unsigned int num_line)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, num_line, "swap");
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

/**
 * add_node - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node.
 * @num_line: line number of opcode.
 */
void add_node(stack_t **stack, unsigned int num_line)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, num_line, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub_node - Subtracts the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node.
 * @num_line: line number of opcode.
 */
void sub_node(stack_t **stack, unsigned int num_line)
{
	int sub;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, num_line, "sub");


	(*stack) = (*stack)->next;
	sub = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sub;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_node - Divides the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node.
 * @num_line: line number of opcode.
 */
void div_node(stack_t **stack, unsigned int num_line)
{
	int div;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, num_line, "div");

	if ((*stack)->n == 0)
		more_err(9, num_line);
	(*stack) = (*stack)->next;
	div = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = div;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
