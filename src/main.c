#include <stdio.h>
#include "stack.h"

// define return values
#define SUCCESS 0
#define FAIL 1

// define logic states
#define True 1
#define False 0


int main()
{

	struct stack* stack = initialize();
	struct transaction* transaction = (struct transaction*)malloc(sizeof(struct transaction));
	struct transaction* other_transaction = (struct transaction*)malloc(sizeof(struct transaction));
	printf("pre init: %x\n", transaction);
	/*
	if (init_transaction(transaction) == FAIL)
	{
		printf("Transaction initialization failed!");
	}
`	*/
	printf("post init: %x\n", transaction);
	transaction->total = 10.0;
	transaction->category = 1;
	transaction->day = 1;
	transaction->month = 1;
	transaction->description[0] = 'H';
	
	if (stack == FAIL)
	{
		printf("Stack initialization failed!\n");
	}

	if (push(transaction, stack) == FAIL)
	{
		printf("Failed to push transaction to stack!\n");
	} else
	{
		printf("Cost of top transaction: %f\n", stack->transaction_history[0]->total);
	}

	other_transaction = pop(stack);
	printf("%x\n", other_transaction);
	printf("Cost of top transaction: %f\n", other_transaction->total);


	printf("Hello, World!\n");
	return 0;
}