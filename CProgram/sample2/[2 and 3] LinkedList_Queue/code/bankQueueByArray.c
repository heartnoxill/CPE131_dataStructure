#include <string.h>
#include <stdio.h>
#include "bankQueue.h"

#define MAX_LENGTH 500

/* 
 * We implement the queue by storing the value in array
 * For example:
 * 		INITIAL			[]
 * 		ENQUEUE 50		[50]
 * 		ENQUEUE 100		[100, 50]
 * 		ENQUEUE 20		[20, 100, 50]
 * 		DEQUEUE			[20, 100]
 * 		DEQUEUE			[20]
 */

int bankQueue[MAX_LENGTH];
int queueCount;

void initialBankQueue()
{
	queueCount = 0;
}

void customerEnterTheQueue(int customerId)
{
	if (queueCount == MAX_LENGTH) {
		printf("Failed to join the queue.\n");
		return;
	}
	int i;
	for (i=queueCount-1; i>=0; i--) {
		bankQueue[i+1] = bankQueue[i];
	}
	queueCount++;
	bankQueue[0] = customerId;
	printf("Customer %d entered the queue.\n", customerId);
}

void callNextCustomerFromQueue(int counterNumber)
{
	// check if list is empty
	if (queueCount == 0) {
		printf("Queue is empty, take a break.");
		return;
	}
	// TODO: retrieve the next customerId from list
	int customerId = 555;

	// TODO: delete the first customerId from list
	
	// TODO: decrease the queueCount by 1
	
	printf("Customer %d please proceed to counter number %d.\n", customerId, counterNumber);
}

void listCustomerInQueue()
{
	int count = 0;
	int i;
	printf("Customers in queue are >\n");
	for (i=queueCount-1; i>=0; i--) {
		printf("- %d\n", bankQueue[i]);
	}
	printf("Total %d customers in queue\n", queueCount);
}