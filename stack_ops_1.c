#include "monty.h"

/**
 * stack_op - performs stack operations.
 * @stack: A pointer to pointer pointing the top node of stack.
 * @line_nmbr: Line number of the opcode.
 * @opcode: Performs operation (e.g., "push", "pall", "pop", "pint").
 */
void stack_op(stack_t **stack, unsigned int line_nmbr, const char *opcode)
{
	stack_t *tmp;

	if (stack == NULL)
		more_err(7, line_nmbr);

	if (strcmp(opcode, "push") == 0)
	{
		stack_t *new_node = crt_node(0);

		if (new_node == NULL)
			err(4);
		new_node->next = *stack;
		if (*stack != NULL)
			(*stack)->prev = new_node;
		*stack = new_node;
	}

	else if (strcmp(opcode, "pall") == 0)
	{
		tmp = *stack;
		while (tmp != NULL)
		{
			printf("%d\n", tmp->n);
			tmp = tmp->next;
		}

	}

	else if (strcmp(opcode, "pop") == 0)
	{
		if (*stack == NULL)
			more_err(6, line_nmbr);
		tmp = *stack;
		*stack = tmp->next;
		if (*stack != NULL)
			(*stack)->prev = NULL;
		free(tmp);
	}

	else if (strcmp(opcode, "pint") == 0)
	{
		if (*stack == NULL)
			more_err(6, line_nmbr);
		printf("%d\n", (*stack)->n);
	}
}
