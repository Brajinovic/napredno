#include <stdio.h>
#include <string.h>
#include "stack.h"


void printMenu()
{
	printf("\t 0 - new transaction input\n");
	printf("\t 1 - delete last transaction\n");
	printf("\t 2 - check last transaction\n");
	printf("\t 3 - transaction history overview\n");
	printf("\t 4 - transaction category browser\n");
	printf("\t 5 - monthly report\n");
	printf("\t 6 - transaction browser\n");
	printf("\t 7 - exit\n");

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
	printf("This program was made as a part of the subject Advanced programming.\n\n");
	printf("Enter a number to navigate the menu. Only numbers shown in the menue screen are allowed!\n");
	printf("No letters, special characters or numbers outside the allowed range are permitted. \nIf the input is incorrect, you will be asked to do it again.\n");
	printf("The program menu should appear after this message.\n\n");
}

int main()
{
	// array used to store the user input
	char user_input[100];

	// structure elements
	float total;
	int category;
	int day;
	int month;
	char description[50];

	struct stack* stack = initialize();
	if (stack == NULL)
	{
		printf("Stack initialization failed!\n");
		printf("Exiting program!");

		return FAIL;
	}

	// variable used for the menu navigation
	char* menu_index = (char*)malloc(sizeof(char) * 2);
	// high impedence, default value
	if (menu_index == NULL)
	{
		printf("Failed to allocate memory for menu_index!\n");
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
	
	struct transaction* other_transaction;

	transaction0->total = 10.0;
	transaction0->category = 0;
	transaction0->day = 1;
	transaction0->month = 1;
	strcpy(transaction0->description, "Lunch.");

	transaction1->total = 11.0;
	transaction1->category = 2;
	transaction1->day = 3;
	transaction1->month = 12;
	strcpy(transaction1->description, "Drinks.");

	transaction2->total = 12.0;
	transaction2->category = 3;
	transaction2->day = 4;
	transaction2->month = 5;
	strcpy(transaction2->description, "Charity donation.");

	transaction3->total = 13.0;
	transaction3->category = 3;
	transaction3->day = 29;
	transaction3->month = 11;
	strcpy(transaction3->description, "Charity donation.");

	transaction4->total = 14.0;
	transaction4->category = 1;
	transaction4->day = 15;
	transaction4->month = 1;
	strcpy(transaction4->description, "Internet.");

	transaction5->total = 15.0;
	transaction5->category = 3;
	transaction5->day = 8;
	transaction5->month = 5;
	strcpy(transaction5->description, "Lost it, can\'t find it");

	transaction6->total = 16.53;
	transaction6->category = 0;
	transaction6->day = 22;
	transaction6->month = 9;
	strcpy(transaction6->description, "Dinner with spouse.");

	transaction7->total = 1.99;
	transaction7->category = 1;
	transaction7->day = 18;
	transaction7->month = 3;
	strcpy(transaction7->description, "Bus ticket.");

	transaction8->total = 0.50;
	transaction8->category = 1;
	transaction8->day = 28;
	transaction8->month = 9;
	strcpy(transaction8->description, "Parking.");

	transaction9->total = 999.0;
	transaction9->category = 2;
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

#endif

	printWelcomeScreen();
	while(1)
	{
		do
		{
			printMenu();
			fgets(menu_index, 2, stdin);
			while(getchar() != '\n');
			// 0 - 48
			// 7 - 55
			// c - 99
		// if the input is outside of the allowed range, repeat the entry
		} while (!(menu_index[0] >= 48 && (menu_index[0] <= 55) || (menu_index[0] == 99)));

		if (menu_index[0] == '0')
		{
			printf(" Chosen option: 0 - new transaction input.\n");
			// input new transaction
			do
			{
				// input total price
				printf(" Enter the total amount of the transaction, only numbers are allowed (they can be decimal) and can it can't be 0.0: \n");
				
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

			do
			{
				printf(" Enter the transaction category! In case of invalid input, These are the categories and the correlated values: \n");
				printf(" 0 - FOOD (default value)\n");
				printf(" 1 - UTILITIES\n");
				printf(" 2 - FUN\n");
				printf(" 3 - OTHER\n");
	
				// read the input as a string
				fgets(user_input, 100, stdin);
				category = atoi(user_input);
				// atof converts string to float if valid input
				// otherwise it returns 0.0
			}while(!(category >= 0 && category <= 3));

			
			do
			{
				// day
				printf(" Enter the transaction day. Valid input is in the range from 1 to 31: \n");
				
				// read the input as a string
				fgets(user_input, 100, stdin);
				day = atoi(user_input);
				// atof converts string to float if valid input
				// otherwise it returns 0.0
			}while(!(day >= 1 && day <= 31));

			do
			{
				// month
				printf(" Enter the transaction month. Valid input is in the range from 1 to 12: \n");
			
				// read the input as a string
				fgets(user_input, 100, stdin);
				month = atoi(user_input);
				// atof converts string to float if valid input
				// otherwise it returns 0.0
			}while(!(month >= 1 && month <= 12));

			// description
			// read the input as a string
			printf(" Enter transactiond details. Up to 50 characters! If you enter more than that, only the first 50 characters are going to be stored!\n"),
			fgets(description, 50, stdin);


			other_transaction = (struct transaction*)malloc(sizeof(struct transaction));
			other_transaction->total = total;
			other_transaction->category = category;
			other_transaction->day = day;
			other_transaction->month = month;
			strcpy(other_transaction->description, description);

			if (push(other_transaction, stack) == FAIL)
			{
				printf("Failed to push transaction to stack!\n");
			} else
			{
			}

		} else if (menu_index[0] == '1')
		{
			printf(" Chosen option: 1 - delete last transaction.\n");
			pop(stack);

		} else if (menu_index[0] == '2')
		{
			printf(" Chosen option: 2 - check last transaction.\n");
			printTransaction(peek(stack));
		} else if (menu_index[0] == '3')
		{
			printf(" Chosen option: 3 - transaction history overview.\n");
			printContent(stack);

		}  else if (menu_index[0] == '4')
		{
			do
			{
				printf(" Chosen option: 4 - browse by category.\n");
				printf("Enter search categoriy: \n");
				printf(" 0 - FOOD\n");
				printf(" 1 - UTILITIES\n");
				printf(" 2 - FUN\n");
				printf(" 3 - OTHER\n");
				
				// read the input as a string
				fgets(user_input, 100, stdin);
				while(getchar() != '\n');
				category = atoi(user_input);
				// atof converts string to float if valid input
				// otherwise it returns 0.0
			}while(!(category >= 0 && category <= 3));
			// print all transactions with that categoriy
			printContentByCategory(stack, category);

		} else if (menu_index[0] == '5')
		{
			int month = 0;
			double sum_fun = 0.0;
			double sum_utilities = 0.0;
			double sum_food = 0.0;
			double sum_other = 0.0;

			printf(" Chosen option: 5 - monthly cost summary.\n");
			do
			{
				printf(" Enter a number between 1 and 12 representing the month of interest: \n");

				// read the input as a string
				fgets(user_input, 100, stdin);	

				// atof converts string to float if valid input
				// otherwise it returns 0.0
				month = atoi(user_input);

			}while(!(month >= 1 && month <= 12));

			int index = 0;
			// search through all of the transactions
			// sum the costs by category for the given month
			while ( index < stack->top)
			{
				if ( stack->transaction_history[index]->month == month)
				{
					int cost_category = stack->transaction_history[index]->category;
					if (  cost_category == 0)
					{
						sum_food += stack->transaction_history[index]->total;
					} else if ( cost_category == 1)
					{
						sum_utilities += stack->transaction_history[index]->total;
					} else if (cost_category == 2)
					{
						sum_fun += stack->transaction_history[index]->total;
					} else
					{
						sum_other += stack->transaction_history[index]->total;
					}
				}
				index = index + 1;
			}
			printf(" Cost summary for the month: %d\n", month);
			printf("\tCategory FOOD: %.2f\n", sum_food);
			printf("\tCategory UTILITIES: %.2f\n", sum_utilities);
			printf("\tCategory FUN: %.2f\n", sum_fun);
			printf("\tCategory OTHER: %.2f\n\n\n", sum_other);
			// based on the user input (months)
			// calculate the sum of costs for each category
		} else if (menu_index[0] == '6')
		{
			int browse_option;
			int day;
			int month;
			
			do
			{
				// the user should be able to browse the transactions
				// based on day (1-31) and/or month (12)
				// select one of the two options
				printf(" Chosen option: 6 - Date based transaction browser.\n");
				printf(" Enter 0 if you want to browse transactions based on the day.\n");
				printf(" Enter 1 if you want to browse transactions based on the day and month.\n");
				// read the input as a string
				fgets(user_input, 100, stdin);
				browse_option = atoi(user_input);
				// atof converts string to float if valid input
				// otherwise it returns 0.0
			}while(!(browse_option >= 0 && browse_option <= 1));

			if ( browse_option == 0)
			{
				do
				{
					printf(" Chosen option: Browse by day!\n");
					printf(" Enter a number between 1 and 31.\n");
					
					// read the input as a string
					fgets(user_input, 100, stdin);
					day = atoi(user_input);
					// atof converts string to float if valid input
					// otherwise it returns 0.0
				}while(!(day >= 1 && day <= 31));

				printf("Search criteria: \n"),
				printf("\tDay: %d\n\n", day);

				int index = 0;
				while ( index <= stack->top )
				{
					if (stack->transaction_history[index]->day == day)
					{
						printTransaction(stack->transaction_history[index]);
					}
					index = index + 1;
				}
			} else
			{
				do
				{
					printf(" Chosen option: Browse by day and month!\n");
					printf(" Enter a number between 1 and 31.\n");
					// read the input as a string
					fgets(user_input, 100, stdin);
					day = atoi(user_input);
					// atof converts string to float if valid input
					// otherwise it returns 0.0
				}while(!(day >= 1 && day <= 31));

				do
				{
					printf(" Enter a number between 1 and 12.\n");
					// read the input as a string
					fgets(user_input, 100, stdin);			
					month = atoi(user_input);
					// atof converts string to float if valid input
					// otherwise it returns 0.0
				}while(!(month >= 1 && month <= 12));

				printf("Search criteria: \n"),
				printf("\tDay: %d\n", day);
				printf("\tMonth: %d\n\n", month);

				int index = 0;
				while ( index <= stack->top )
				{
					if (stack->transaction_history[index]->day == day && stack->transaction_history[index]->month == month)
					{
						printTransaction(stack->transaction_history[index]);
					}
					index = index + 1;
				}

			}
		} else if (menu_index[0] == '7')
		{	
			break;
		} else if (menu_index[0] == 'c')
		{
			printf("Press \"c\" to print out the menu.\n");
			printMenu();
		}
		
		printf("To show the menu, press \"c\".\n");
		// reset input
		menu_index[0] = 'z';
	}

	return SUCCESS;
}