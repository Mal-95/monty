#include "monty.h"

/**
 * handle_err - Handles a number of different errors and prints appropriate messages.
 * @err_code: The follows such errors:
 *   (1) => User does not provide any file or more than one file to the program.
 *   (2) => The file presented cannot be read or opened.
 *   (3) => The file presented contains invalid instruction.
 *   (4) => When the program cannot to malloc more memory.
 *   (5) => When the number passed to the instruction "push" is not an integer.
 *   (6) => Whenever the stack is empty for pint.
 *   (7) => Whenever the stack is empty for pop.
 *   (8) => Whenever the stack is short for the operation.
 *   (9) => Dividing by zero.
 *   (10) => The number inside a node is beyond ASCII bounds.
 *   (11) => The stack is empty.
 */
void handle_err(int err_code, ...)
{
	va_list args;
	va_start(args, err_code);

	switch (err_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
			break;
		case 3:
			fprintf(stderr, "L%d: unknown instruction %s\n", va_arg(args, int), va_arg(args, char *));
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(args, int));
			break;
		case 8:
			fprintf(stderr, "L%d: can't %s, stack too short\n", va_arg(args, int), va_arg(args, char *));
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n", va_arg(args, int));
			break;
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", va_arg(args, int));
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", va_arg(args, int));
			break;
		default:
			break;
	}

	free_nodes();
	exit(EXIT_FAILURE);
}
