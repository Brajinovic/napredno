#include "stack.h"


struct stack* initialize(void)
{
	struct stack* stack;
	stack = (struct stack*)malloc(sizeof(struct stack));

	if (stack == NULL)
	{
		printf("Stack initialization failed!\n");
		return FAIL;
	}
	stack->top = -1;
	stack->max_size = STACK_SIZE;
	stack->transaction_history = (struct transaction*)malloc(sizeof(struct transaction*) * stack->max_size);
	if (stack->transaction_history == NULL)
	{
		printf("Stack buffer initialization failed!\n");
		return FAIL;
	}
	return stack;
}


int push(struct transaction* transaction, struct stack* stack)
{
	if (stack->top <= stack->max_size)
	{
		// increment the top object counter
		stack->top = stack->top + 1;
		// add the object to the end
		stack->transaction_history[stack->top] = transaction;
		
	} else
	{
		printf("Stack is full! Not able to push transaction to stack!");
		return FAIL;
	}
	return SUCCESS;
}

struct transaction* pop(struct stack* stack)
{
	if (stack->top >= 0)
	{	

		stack->top = stack->top - 1;
		return stack->transaction_history[stack->top + 1];
	} else
	{
		// nothing to pop, stack is empty
		printf("Stack is empty, nothing to pop!\n");

		return FAIL;
	}
}

int isEmpty(struct stack* stack)
{
	if (stack->top <= -1)
	{
		return SUCCESS;
	} else
	{
		return FAIL;
	}
}

int isFull(struct stack* stack)
{
	if (stack->top >= stack->max_size)
	{
		return SUCCESS;
	} else
	{
		return FAIL;
	}
}

void printContent(struct stack* stack)
{
	if (isEmpty(stack) == SUCCESS)
	{
		printf("Stack is empty! Nothing to do!");
	} else
	{
		int index = 0;
		while (index <= stack->top)
		{
			printf("Transaction: %d\n", index);
			printf("\t Total: %f", stack->transaction_history[index]->total);
			printf("\t Category: %d", stack->transaction_history[index]->category);
			printf("\t Day: %d", stack->transaction_history[index]->day);
			printf("\t Month: %d", stack->transaction_history[index]->month);
			printf("\t Description: %s", stack->transaction_history[index]->description);
			
		}
	}
}