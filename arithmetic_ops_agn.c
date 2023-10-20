#include "monty.h"

/**
 * arithmetic_op - Performs arithmetic operations.
 * @stack: Pointer to pointer pointing at the top node of the stack.
 * @line_nmbr: Line number where the opcode exists.
 * @opcode: Performs operation (e.g., "mul", "mod").
 */
void arithmetic_op(stack_t **stack, unsigned int line_nmbr, const char *opcode)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_nmbr, opcode);

	if (strcmp(opcode, "mul") == 0)
	{
		(*stack) = (*stack)->next;
		(*stack)->n *= (*stack)->prev->n;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}

	else if (strcmp(opcode, "mod") == 0)
	{
		if ((*stack)->n == 0)
			more_err(9, line_nmbr);
		(*stack) = (*stack)->next;
		(*stack)->n %= (*stack)->prev->n;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
}
