#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bankQueue.h"

int main()
{
	srand((unsigned int)time(NULL));	//initial the random number generator
	int menu = 0;
	initialBankQueue();
	do
	{
		printf("Bank queueing system program\n");
		printf("1 - Customer enter the queue\n");
		printf("2 - Bank officer call a customer from the queue\n");
		printf("3 - Show all customers id in the queue\n");
		do
		{
			menu = 0;
			printf("Enter your choice (0 to exit) :");
			scanf("%d", &menu);
			fflush(stdin);
		} while(menu < 0 || menu > 3);
		if (menu == 0) 
			exit(0);
		else if (menu == 1)
		{
			int customerId = rand() + 1;	//random a customer id (positive integer)
			customerEnterTheQueue(customerId);
		}
		else if (menu == 2)
		{
			int counterNumber;
			printf("Enter bank counter number :");
			scanf("%d" , &counterNumber);
			fflush(stdin);
			callNextCustomerFromQueue(counterNumber);
		}
		else if (menu == 3)
		{
			listCustomerInQueue();
		}
		printf("\nPress enter to continue...\n");
		getc(stdin);
	} while(menu != 0);
    return 0;
}