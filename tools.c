#include "monty.h"

/**
 * main - the point of entry
 * @argc: count of arguments
 * @argv: a list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * crt_node - Creates node.
 * @n: Number inside node.
 * Return: For success pointer to the node. Otherwise print NULL.
 */
stack_t *crt_node(int n)
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
 * free_nodes - Frees nodes in a stack.
 * @head - head of a stack.
 */
void free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	for (tmp = head; tmp != NULL; tmp = head)
	{
		head = head->next;
		free(tmp);
	}
}

/**
 * add_queue - Adds node to queue.
 * @new_node: points new node.
 * @ln: line number where opcode is found.
 */
void add_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;
}
