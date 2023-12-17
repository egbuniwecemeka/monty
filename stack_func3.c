#include "monty.h"

/**
 * mul_node - Multiplies the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node.
 * @num_line: line number of opcode.
 */
void mul_node(stack_t **stack, unsigned int num_line)
{
	int mul;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, num_line, "mul");

	(*stack) = (*stack)->next;
	mul = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = mul;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod_node - Modulusof the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node.
 * @num_line: line number of opcode.
 */
void mod_node(stack_t **stack, unsigned int num_line)
{
	int mod;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, num_line, "mod");


	if ((*stack)->n == 0)
		more_err(9, num_line);
	(*stack) = (*stack)->next;
	mod = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = mod;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
