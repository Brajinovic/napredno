#ifndef STACK_H
#define STACK_H

#define SUCCESS 0
#define FAIL 1

#define STACK_SIZE 100


#include "transaction.h"
#include <stdio.h>
#include <stdlib.h>

struct stack
{
	struct transaction** transaction_history;
	int top;
	int max_size;
};

// create a stack instance
// allocate memory for the transaction_history
// set the head
// @ returns struct stack* if successful
// @ returns FAIL if not
struct stack* initialize(void);

// add a new transaction to the top
// increment top index counter
// @ returns SUCCESS if successful
// @ returns FAIL if not
int push(struct transaction* transaction, struct stack* stack);

// get the transaction from the top
// set the top transaction to the second to last one
// @ returns struct transaction* if successful
// @ returns FAIL if not
struct transaction* pop(struct stack*);

// check if the stack is empty
// @ returns SUCCESS if stack is empty
// @ returns FAIL if not
int isEmpty(struct stack* stack);

// check if the stack is full
// @ returns SUCCESS if stack is full
// @ returns FAIL if not
int isFull(struct stack* stack);

// print all contents of the stack
void printContent(struct stack*);

#endif