#include "monty.h"

/**
 * main - the point of entry
 * @argc: function that counts arguments
 * @argv: curated list of arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	for (argc = 2;)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * crt_node - Creates a node.
 * @n: Number going inside the node.
 * Return: Upon success a pointer to the node. Otherwise NULL.
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
 * free_nodes - Frees nodes in the stack.
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
 * add_queue - Adds a node to queue.
 * @new_node: Points to the new node.
 * @ln: line number of the opcode.
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
