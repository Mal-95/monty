#include "monty.h"

/**
 * arithmetic_op - Perform arithmetic operations.
 * @stack: Pointer to pointer pointing to the top node of the stack.
 * @line_nmbr: Line number where the opcode is found.
 * @opcode: Performs operation (e.g., "add", "sub", "div").
 */
void arithmetic_op(stack_t **stack, unsigned int line_nmbr, const char *opcode)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_nmbr, opcode);

	if (strcmp(opcode, "add") == 0)
	{
		(*stack) = (*stack)->next;
		(*stack)->n += (*stack)->prev->n;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}

	else if (strcmp(opcode, "sub") == 0)
	{
		(*stack) = (*stack)->next;
		(*stack)->n -= (*stack)->prev->n;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}

	else if (strcmp(opcode, "div") == 0)
	{
		if ((*stack)->n == 0)
			more_err(9, line_nmbr);
		(*stack) = (*stack)->next;
		(*stack)->n /= (*stack)->prev->n;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
}
