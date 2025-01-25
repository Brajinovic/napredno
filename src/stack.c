#include "stack.h"


struct stack* initialize(void)
{
	struct stack* stack;
	stack = (struct stack*)malloc(sizeof(struct stack));

	if (stack == NULL)
	{
		printf("Stack initialization failed!\n");
		return NULL;
	}
	stack->top = -1;
	stack->max_size = STACK_SIZE;
	stack->transaction_history = (struct transaction**)malloc(sizeof(struct transaction*) * stack->max_size);
	if (stack->transaction_history == NULL)
	{
		printf("Stack buffer initialization failed!\n");
		return NULL;
	}
	return stack;
}


int push(struct transaction* transaction, struct stack* stack)
{
	if (stack == NULL)
	{
		printf("Stack not allocated!");
		return FAIL;
	}

	if (transaction == NULL)
	{
		printf("Transaction not allocated!");
		return FAIL;
	}
	if (isFull(stack) == FAIL)
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
	if (stack == NULL)
	{
		printf("Stack not allocated!");
		return NULL;
	}
	if (isEmpty(stack) == FAIL)
	{	
		// I am not deleting the last element, just decrementing the counter
		// the next new transation is going to be written in the place of the 
		// now poped transaction and in that way it is going to be deleted
		stack->top = stack->top - 1;
		return stack->transaction_history[stack->top + 1];
	} else
	{
		// nothing to pop, stack is empty
		printf("Stack is empty, nothing to pop!\n");

		return NULL;
	}
}

struct transaction* peek(struct stack* stack)
{
	if (stack != NULL)
	{
		if (stack->transaction_history != NULL)
			{
				// return the pointer to the last transation
				return stack->transaction_history[stack->top];
			}
	}
	
	return NULL;
}

int isEmpty(struct stack* stack)
{
	if (stack == NULL)
	{
		printf("Stack not allocated!");
		return FAIL;
	}

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
	if (stack == NULL)
	{
		printf("Stack not allocated!");
		return FAIL;
	}
	if (stack->top >= stack->max_size)
	{
		return SUCCESS;
	} else
	{
		return FAIL;
	}
}


void printTransaction(struct transaction* transaction)
{
	printf("\t Total: %.2f", transaction->total);
	printf("\t Category: %d", transaction->category);
	printf("\t Day: %d", transaction->day);
	printf("\t Month: %d", transaction->month);
	printf("\t Description: %s\n\n"	, transaction->description);
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
			printf("Transaction: %d\n", index + 1);
			printTransaction(stack->transaction_history[index]);
			index = index + 1;
		}
	}
}

void printContentByCategory(struct stack* stack, int category)
{
	if (isEmpty(stack) == SUCCESS)
	{
		printf("Stack is empty! Nothing to do!");
	} else
	{
		int index = 0;
		while (index <= stack->top)
		{
			if ( stack->transaction_history[index]->category == category)
			{
				printf("Transaction: %d\n", index + 1);
				printTransaction(stack->transaction_history[index]);
				
			}
			index = index + 1;
		}
	}
}