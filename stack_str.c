#include "monty.h"

/**
 * mnplt_stack_and_str - performs stack and string operations.
 * @stack: A pointer to pointer pointing the top node of a stack.
 * @line_nmbr: Line number where the opcode is found.
 * @opcode: An operation responsible for (e.g., "print_char", "print_str", "rotl", "rotr").
 */
void mnplt_stack_and_str(stack_t **stack, unsigned int line_nmbr, const char *opcode)
{
	if (strcmp(opcode, "print_char") == 0)
	{
		if (*stack == NULL)
				str_err(11, line_nmbr);
				ascii = (*stack)->n;
				if (ascii < 0 || ascii > 127)
				str_err(10, line_nmbr);
				printf("%c\n", ascii);
				}

				else if (strcmp(opcode, "print_str") == 0)
				{
					stack_t *tmp = *stack;
					while (tmp != NULL)
					{
						int ascii = tmp->n;
						if (ascii <= 0 || ascii > 127)
							break;
						printf("%c", ascii);
						*tmp =next;
					}
					printf("\n");
				}

	else if (strcmp(opcode, "rotl") == 0)
	{
		if (*stack != NULL && (*stack)->next != NULL)
		{
			stack_t *tmp = *stack;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = *stack;
			(*stack)->prev = tmp;
			*stack = (*stack)->next;
			(*stack)->prev->next = NULL;
			(*stack)->prev = NULL;
		}
	}

	else if (strcmp(opcode, "rotr") == 0)
	{
		if (*stack != NULL && (*stack)->next != NULL)
		{
			stack_t *tmp = *stack;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = *stack;
			tmp->prev->next = NULL;
			tmp->prev = NULL;
			(*stack)->prev = tmp;
			*stack = tmp;
		}
	}
}
