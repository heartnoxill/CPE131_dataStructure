#include <string.h>
#include <stdio.h>
#include "bankQueue.h"
#include "listADT.h"

/* 
 * We implement the queue by storing the value in linkedlist
 * For example:
 * 		INITIAL			[]
 * 		ENQUEUE 50		50
 * 		ENQUEUE 100		50 -> 100
 * 		ENQUEUE 20		50 -> 100 -> 20
 * 		DEQUEUE			100 -> 20
 * 		DEQUEUE			20
 */

void initialBankQueue()
{
	// TODO: clean list by delete all the number in list
}

void customerEnterTheQueue(int customerId)
{
	// TODO: store the customerId into the list, last position is recommended.

	printf("Customer %d entered the queue.\n", customerId);
}

void callNextCustomerFromQueue(int counterNumber)
{
	// TODO: check if list is empty
	if (1) {
		printf("Queue is empty, take a break.");
		return;
	}
	// TODO: retrieve the next customerId from list
	int customerId = 555;
	printf("Customer %d please proceed to counter number %d.\n", customerId, counterNumber);
	// TODO: delete customer from queue.
}

void listCustomerInQueue()
{
	// TODO: show all items in list
}