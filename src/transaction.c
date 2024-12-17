#include "transaction.h"

int init_transaction(struct transaction* transaction)
{
	transaction = (struct transaction*)malloc(sizeof(struct transaction));
	if (transaction == NULL)
	{
		printf("Failed to allocate memory for struct transaction!");
		return FAIL;
	}
	return SUCCESS;
}