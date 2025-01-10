#include <stdio.h>
#include <string.h>
#include "stack.h"

// define return values
#define SUCCESS 0
#define FAIL 1

// define logic states
#define True 1
#define False 0

#define DEBUG 1
#define EXTENDED 0

void printMenu()
{
	printf("\t 0 - new transaction input\n");
	printf("\t 1 - delete last transaction\n");
	printf("\t 2 - check last transaction\n");
	printf("\t 3 - transaction history overview\n");
	printf("\t 4 - pregled ukupnog stanja\n");
// if I am not doing the extra tasks, number 5 will be to exit the program
#if EXTENDED == 0	
	printf("\t 5 - exit\n");
#endif
// if I am doing the extra tasks, number 8 will be to exit the program & there are additional options
#if EXTENDED == 1
	printf("\t 5 - transaction category browser\n");
	printf("\t 6 - monthly report\n");
	printf("\t 7 - transaction browser\n");
	printf("\t 8 - exit\n");
#endif
}

// clear screen
// print basic information about the program
// 		author
// 		course name
// 		topic/functionality
void printWelcomeScreen()
{
	printf("\n\n\n\n");
	printf("Welcome to the personal finance tracking program!\n\n");
	printf("This program was created on the construction exercises of the Advanced programming subject.\n");
	printf("Enter a number to navigate the menu. Only numbers shown in the menue screen are allowed!\n");
	printf("No letters, special characters or numbers outside the allowed range are permitted. \nIf the input is incorrect, you will be asked to do it again.\n");
	printf("The program menu should appear after this message.\n\n");
}

int main()
{
	char user_input[100];

	float total;
	enum category category;
	int day;
	int month;
	char description[50];

	struct stack* stack = initialize();
	if (stack == FAIL)
	{
		printf("Stack initialization failed!\n");
		printf("Exiting program!");
		return FAIL;
	}

#if DEBUG == 1
	struct transaction* transaction0 = (struct transaction*)malloc(sizeof(struct transaction));
	struct transaction* transaction1 = (struct transaction*)malloc(sizeof(struct transaction));
	struct transaction* transaction2 = (struct transaction*)malloc(sizeof(struct transaction));
	struct transaction* transaction3 = (struct transaction*)malloc(sizeof(struct transaction));
	struct transaction* transaction4 = (struct transaction*)malloc(sizeof(struct transaction));
	struct transaction* transaction5 = (struct transaction*)malloc(sizeof(struct transaction));
	struct transaction* transaction6 = (struct transaction*)malloc(sizeof(struct transaction));
	struct transaction* transaction7 = (struct transaction*)malloc(sizeof(struct transaction));
	struct transaction* transaction8 = (struct transaction*)malloc(sizeof(struct transaction));
	struct transaction* transaction9 = (struct transaction*)malloc(sizeof(struct transaction));
	
	struct transaction* other_transaction = (struct transaction*)malloc(sizeof(struct transaction));

	transaction0->total = 10.0;
	transaction0->category = 1;
	transaction0->day = 1;
	transaction0->month = 1;
	strcpy(transaction0->description, "Lunch.");

	transaction1->total = 11.0;
	transaction1->category = 3;
	transaction1->day = 3;
	transaction1->month = 12;
	strcpy(transaction1->description, "Drinks.");

	transaction2->total = 12.0;
	transaction2->category = 4;
	transaction2->day = 4;
	transaction2->month = 5;
	strcpy(transaction2->description, "Charity donation.");

	transaction3->total = 13.0;
	transaction3->category = 4;
	transaction3->day = 29;
	transaction3->month = 11;
	strcpy(transaction3->description, "Charity donation.");

	transaction4->total = 14.0;
	transaction4->category = 2;
	transaction4->day = 15;
	transaction4->month = 1;
	strcpy(transaction4->description, "Internet.");

	transaction5->total = 15.0;
	transaction5->category = 4;
	transaction5->day = 8;
	transaction5->month = 5;
	strcpy(transaction5->description, "Lost it, can\'t find it");

	transaction6->total = 16.53;
	transaction6->category = 1;
	transaction6->day = 22;
	transaction6->month = 9;
	strcpy(transaction6->description, "Dinner with spouse.");

	transaction7->total = 1.99;
	transaction7->category = 2;
	transaction7->day = 18;
	transaction7->month = 3;
	strcpy(transaction7->description, "Bus ticket.");

	transaction8->total = 0.50;
	transaction8->category = 2;
	transaction8->day = 28;
	transaction8->month = 9;
	strcpy(transaction8->description, "Parking.");

	transaction9->total = 999.0;
	transaction9->category = 3;
	transaction9->day = 29;
	transaction9->month = 8;
	strcpy(transaction9->description, "Weekend getaway!");
	

	if (push(transaction0, stack) == FAIL)
	{
		printf("Failed to push transaction to stack!\n");
	} else
	{
	}

	if (push(transaction1, stack) == FAIL)
	{
		printf("Failed to push transaction to stack!\n");
	} else
	{
	}

	if (push(transaction2, stack) == FAIL)
	{
		printf("Failed to push transaction to stack!\n");
	} else
	{
	}

	if (push(transaction3, stack) == FAIL)
	{
		printf("Failed to push transaction to stack!\n");
	} else
	{
	}

	if (push(transaction4, stack) == FAIL)
	{
		printf("Failed to push transaction to stack!\n");
	} else
	{
	}

	if (push(transaction5, stack) == FAIL)
	{
		printf("Failed to push transaction to stack!\n");
	} else
	{
	}
	if (push(transaction6, stack) == FAIL)
	{
		printf("Failed to push transaction to stack!\n");
	} else
	{
	}

	if (push(transaction7, stack) == FAIL)
	{
		printf("Failed to push transaction to stack!\n");
	} else
	{
	}

	if (push(transaction8, stack) == FAIL)
	{
		printf("Failed to push transaction to stack!\n");
	} else
	{
	}

	if (push(transaction9, stack) == FAIL)
	{
		printf("Failed to push transaction to stack!\n");
	} else
	{
	}

	printContent(stack);
	other_transaction = pop(stack);
	printf("\n Delete transaction %s \n\n", other_transaction->description);
	printContent(stack);

	other_transaction = peek(stack);
	printf("Peek at the new top transaction: %s\n", other_transaction->description);
#endif

	printWelcomeScreen();
	printMenu();

	// high impedence, default value
	char menu_index = 'z';

	while(1)
	{
		do
		{
			// when multiple characters are read from the stdin, the program kinda breaks
			// it doesn't crash but it fills the buffer with some wierd characters and then you need to 
			// play around with it to get it going again
			scanf("%c", &menu_index);
			getchar();
#if DEBUG == 1
			printf("Pressed: %d\n", menu_index);
#endif
			// 0 - 48
			// 5 - 53
			// 8 - 56
		// if the input is outside of the allowed range, repeat the entry
		} while (!(menu_index >= 48 && (menu_index <= (EXTENDED == 0 ? 53 : 56)) || menu_index == 99));

		if (menu_index == '0')
		{
			printf(" Chosen option: 0 - new transaction input\n");
			// input new transaction
			while (1)
			{
				printf(" Enter the total amount of the transaction, only numbers are allowed (they can be decimal) and can it can't be 0.0: ");
				// input total price
				do
				{
					// read the input as a string
					fgets(user_input, 100, stdin);

					// atof converts string to float if valid input
					// otherwise it returns 0.0
					total = atof(user_input);

#if DEBUG == 1
					printf("\n Total: %f\n", total);
#endif
				// if the input is outside of the allowed range, repeat the entry
				} while (total == 0.0);

				printf(" Enter the transaction category! In case of invalid input, These are the categories and the correlated values: \n");
				printf(" 0 - FOOD (default value)\n");
				printf(" 1 - UTILITIES\n");
				printf(" 2 - FUN\n");
				printf(" 3 - OTHER\n");
				do
				{
					// read the input as a string
					fgets(user_input, 100, stdin);
					category = atoi(user_input);
					// atof converts string to float if valid input
					// otherwise it returns 0.0
				}while(!(user_input >= 0 && user_input <= 3));

			}
		} else if (menu_index == '1')
		{
			printf(" Chosen option: 1 - delete last transaction\n");
			pop(stack);

		} else if (menu_index == '2')
		{
			printf(" Chosen option: 2 - check last transaction\n");
			printTransaction(peek(stack));
		} else if (menu_index == '3')
		{
			printf(" Chosen option: 3 - transaction history overview\n");
			printContent(stack);

		} else if (menu_index == '4')
		{
			printf(" 5 - To be implemented\n");
		} else if (menu_index == 'c')
		{
			printf("Press \"c\" to print out the menu.");
			printMenu();
		}

#if EXTENDED == 0
		// in case of not extended menu, the 5 is used to exit the program
		else if (menu_index == '5')
		{
			break;
		}
#else
		// in case of the extended menu, the 8 is used to exit the program
		else if (menu_index == '5')
		{
			printf(" 5 - To be implemented\n");
		} else if (menu_index == '6')
		{
			
			printf(" 6 - To be implemented\n");
		} else if (menu_index == '7')
		{
			
			printf(" 7 - To be implemented\n");
		} else if (menu_index == '8')
		{
			break;
		}
#endif
		
		printf("To show the menu, press \"c\"\n");
		// reset input
		menu_index = 'z';
	}

	return SUCCESS;
}