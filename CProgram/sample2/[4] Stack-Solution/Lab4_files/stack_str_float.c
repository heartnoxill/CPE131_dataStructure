/**
 *  linkedListStack.c
 *
 *  An implementation of abstractStack using a linked list.
 *
 *  Created by Sally Goldin, 21December 2011 for CPE113
 *	Edited by Chattriya Jariyavajee, 27 January 2016 for CPE113(AE)
 *  Edited by Chattriya Jariyavajee, 8 February 2017 for CPE131(AE)
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack_str_float_ADT.h"

/* Structure that represents one item of the list */
typedef struct node
{
    void * data;               /* the data for the node */
    struct node * next;        /* Link to the next item in the list */
} STACK_NODE;

int count = 0;
STACK_NODE * top = NULL;

/**
 * Push a string data item onto the stack
 * Arguments:
 *   str   -  String we want to add to stack
 * Returns 1 if successful, 0 if we have an overflow.
 */
int pushString(char* str)
{
	char * data = (char *) calloc(strlen(str)+1, sizeof(char));
    STACK_NODE * newItem = (STACK_NODE *)calloc(1,sizeof(STACK_NODE));
    if (newItem == NULL || data == NULL)
	{
		return 0;
	}
    else
	{
	    strcpy(data, str);
		newItem->data = data;  /* store the data */
		newItem->next = top;
		top = newItem;
		count = count+1;
		return 1;
	}
}

/**
 * Removes and returns the top string item on the stack.
 * Returns NULL if the stack is empty.
 */
char * popString()
{
    char * data = NULL;
    STACK_NODE * tmp = top;
    if (top != NULL)
	{
		data = top->data;   /* this is what we will return */
		top = top->next;   /* make the following node the new top/top */
		free(tmp);          /* free the memory for this list item */
		count = count - 1;
	}
    return (char *) data;
}

/**
 * Returns the top item on the stack without remove it.
 * Returns NULL if the queue is empty (that is, underflow).
 */
char * topString()
{
	if(top == NULL) {
		return NULL;
	}
    return (char *) top->data;
}

/**
 * Push a float data item onto the stack
 * Arguments:
 *   number  -  number we want to add to stack
 * Returns 1 if successful, 0 if we have an overflow.
 */
int pushFloat(float number)
{
    float * data = (float *) calloc(1, sizeof(float));
    STACK_NODE * newItem = (STACK_NODE *)calloc(1,sizeof(STACK_NODE));
    if (newItem == NULL || data == NULL)
	{
		return 0;
	}
    else
	{
	    *data = number;
		newItem->data = data;  /* store the data */
		newItem->next = top;
		top = newItem;
		count = count+1;
		return 1;
	}
}

/**
 * Removes and returns the top item on the stack.
 */
float popFloat()
{
    STACK_NODE * tmp = top;
    float retVal;
    if (top != NULL)
	{
	    retVal = *((float*) top->data);
		top = top->next;   /* make the following node the new top */
		free(tmp->data);
		free(tmp);          /* free the memory for this list item */
		count = count - 1;
	}
    return retVal;
}

/**
 * Returns the top item on the stack without remove it.
 */
float topFloat()
{
    if(top == NULL) {
        printf("The stack is empty. You cannot top/peek anything. Please restart the program.\n");
		exit(-1);
	}
    return *((float *) top->data);
}

/**
 * Find out how many items are currently in the stack.
 * Returns 0 if the stack is empty.
 */
int stackSize()
{
	return count;
}

/**
 * Check whether stack is empty or not
 * Returns 1 - stack is empty
 *         0 - stack is not empty
 */
int stackEmpty()
{
    return stackSize() == 0 ? 1 : 0;
}

/**
 * Initialize the stack
 */
void initStack()
{
    STACK_NODE * current = top;
    while (current != NULL)
    {
       STACK_NODE * discardNode = current;
       current = current->next;
       free(discardNode->data);
       free(discardNode);
    }
    top = NULL;
    count = 0;
}

