#include "monty.h"

/**
 * main - entry point
 * @argc: args count
 * @argv: list of args
 * Return: always 0
 */

int main(int argc, char *argv[])
{

	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_node();
	return (0);
}

/**
 * create_node - Creates a node.
 * @n: node num.
 * Return: sucessful, point to the node. Otherwise NULL.
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_node - Frees nodes in the stack.
 */
void free_node(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}


/**
 * add_to_queue - Adds a node to the queue.
 * @new: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void add_to_queue(stack_t **new, __attribute__((unused))unsigned int ln)
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
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *new;
	(*new)->prev = temp;

}
