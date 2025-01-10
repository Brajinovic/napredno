#ifndef TRANSACTION_H
#define TRANSACTION_H

#define SUCCESS 0
#define FAIL 1

#include <stdlib.h>
#include <stdio.h>

enum transaction_category
{
	FOOD,
	UTILITIES,
	FUN,
	OTHER
};

struct transaction
{
	float total;
	enum transaction_category category;
	int day;
	int month;
	char description[50];
};


#endif